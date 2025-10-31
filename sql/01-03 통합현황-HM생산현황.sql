-- 통합현황
-- HM 생산 현황
SELECT NVL(CEIL(B.TO_PLAN_QTY),0) TO_PLAN_QTY,                                        -- 계획량
       NVL(CEIL(A.MONTH_PROD_QTY),0) MONTH_PROD_QTY,                                        -- 생산량
       DECODE(B.MONTH_PLAN_QTY, 0,0,NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100, 1),0)) MONTH_RATE,    -- 당월 달성률
       DECODE(B.PRE_PLAN_QTY,0,0,NVL(ROUND(A.PRE_PROD_QTY / B.PRE_PLAN_QTY * 100),0)) PRE_RATE,            -- 전일 달성률
       CASE WHEN B.TOD_PLAN_QTY = 0 THEN 0 ELSE NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) END TOD_RATE,            -- 금일 달성률
       NVL(ROUND(C.YIELD,1),0) YIELD,                                                    -- 수율 실적
       NVL(ROUND(D.GOAL_YIELD,1),0) GOAL_YIELD,                                            -- 수율 계획
       NVL(ROUND(C.YIELD*100 / D.GOAL_YIELD, 1),0) YIED_RATE                        -- 수율 달성율
  FROM (
        -- 생산량 :  소결선별 생산(완공처리)량 + HIP선별 생산(완공처리)량
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
               SUM(PROD_QTY) MONTH_PROD_QTY,
               SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_PRE_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) PRE_PROD_QTY,
               SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) TOD_PROD_QTY
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'HM'
           AND OPER IN ('OH23020', 'OH23050')         
         GROUP BY SUBSTR(WORK_DATE,0,6)
       ) A,
       (
        -- 계획량
        SELECT SUBSTR(PLAN_DATE,0,6) AS WORK_MONTH,
               SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량
               SUM(CASE WHEN PLAN_DATE <= F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) THEN QTY END) TO_PLAN_QTY, -- 현재까지의 계획량
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_PRE_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) PRE_PLAN_QTY,
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
                     AND OPER IN ('OH23020', 'OH23050')  
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
         GROUP BY SUBSTR(PLAN_DATE,0,6)
       ) B,
       (
           SELECT WORK_MONTH, ROUND(EXP(SUM(LN(DIRECT_RATE))) * 100, 2) YIELD
            FROM (
                   SELECT WORK_MONTH, DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM', OPER) OPER,
                        EXP(SUM(LN(DIRECT_RATE))) DIRECT_RATE   
                   FROM (
                        SELECT WORK_MONTH, OPER, 
                            (CASE WHEN NVL(SUM(PROD_IN_QTY),0)>0 THEN SUM(PROD_QTY)/SUM(PROD_IN_QTY) ELSE 0 END) DIRECT_RATE 
                        FROM (SELECT SUBSTR(A.WORK_DATE,1,6) AS WORK_MONTH, 
                              (CASE  WHEN A.OPER IN ('OH22010', 'OH22020', 'OH22040') THEN 'EXT'                                              
                                     WHEN A.OPER IN ('OH23020', 'OH23050') THEN 'SINTER'                                                  
                                     WHEN A.OPER IN ('OH24010', 'OH24020', 'OH24090') THEN 'REFORM1'
                                     WHEN A.OPER IN ('OH24050') THEN 'REFORM2'
                                     WHEN A.OPER IN ('OH24030','OH24040','OH24060','OH24070') THEN 'REFORM3'
                                     WHEN A.OPER IN ('OH24110') THEN 'INSP'
                                 END) OPER,
                              NVL(SUM(CASE  
                                     /*압출 공정 수율 = (양품 수량 합계) ÷ (양품 수량 합계 + 불량 수량 합계)*/
                                     WHEN A.OPER IN ('OH22010', 'OH22020', 'OH22040') THEN PROD_QTY                                              
                                     /*소결 공정 수율 = (양품 수량 합계) ÷ (양품 수량 합계 + 불량 수량 합계)*/
                                     WHEN A.OPER IN ('OH23020', 'OH23050') THEN PROD_QTY                                                 
                                     /*절단 공정 수율 = MD 절단,Blank 절단, 양끝절단*/
                                     WHEN A.OPER IN ('OH24010', 'OH24020', 'OH24090') THEN PROD_QTY   
                                     /*외경 공정 수율 = 가공(센터리스)*/
                                     WHEN A.OPER IN ('OH24050') THEN PROD_QTY   
                                     /*단면공정 수율 = 가공(양두연삭), 가공(평면연삭), 가공(외경양두), 가공(외경평면)*/
                                     WHEN A.OPER IN ('OH24030','OH24040','OH24060','OH24070') THEN PROD_QTY   
                                     /*검사 공정 수율 = (양품 수량 합계) ÷ (양품 수량 합계 + 불량 수량 합계)*/                     
                                     WHEN A.OPER IN ('OH24110') THEN PROD_QTY                                                 
                                 END),0) PROD_QTY,
                              NVL(SUM(CASE  
                                     WHEN A.OPER IN ('OH22010', 'OH22020', 'OH22040') THEN PROD_IN_QTY                                              
                                     WHEN A.OPER IN ('OH23020', 'OH23050') THEN PROD_IN_QTY                                                 
                                     WHEN A.OPER IN ('OH24010', 'OH24020', 'OH24030', 'OH24040', 'OH24050', 'OH24060', 'OH24070', 'OH24080', 'OH24090') THEN PROD_IN_QTY
                                     WHEN A.OPER IN ('OH24110') THEN PROD_IN_QTY 
                                 END),0) PROD_IN_QTY                            
                       FROM CSUMWIPOPR A
                        WHERE A.FACTORY = 'IJDK1'                      
                           AND A.AREA_ID='HM'        
                           AND MAT_CLASS IN ('MDS', 'MDC', 'EDR')             
                           AND A.OPER IN ('OH22010', 'OH22020', 'OH22040', 
                                          'OH23020', 'OH23050', 
                                          'OH24010', 'OH24020', 'OH24030', 'OH24040', 'OH24050', 'OH24060', 'OH24070', 'OH24090', 
                                          'OH24110')                        
                           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                        GROUP BY SUBSTR(A.WORK_DATE,1,6) , A.OPER
                  ) GROUP BY WORK_MONTH, OPER      
                ) GROUP BY WORK_MONTH, DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM', OPER)
             )GROUP BY WORK_MONTH        
       ) C,
       (
        -- 수율 계획
        SELECT WORK_MONTH, GOAL_YIELD
          FROM CWIPPRDGOL
         WHERE FACTORY = 'IJDK1'
           AND KIND = 'Y'
           AND CLASS='MONTH'
           AND WEEK_OF_MONTH = 1
           AND AREA_ID = 'HM'
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) D
WHERE A.WORK_MONTH=B.WORK_MONTH(+)
    AND A.WORK_MONTH=C.WORK_MONTH(+)
    AND A.WORK_MONTH=D.WORK_MONTH(+)
  ;

-- 소결 시간당 생산성 실적 : (소결선별 생산(완공처리)량 + HIP선별 생산(완공처리)량) ÷ 소결(압출,내마모) 투입 공수 시간
 SELECT NVL(GOAL_PRODUCTVITY,0) GOAL_PRODUCTVITY,                                                -- 계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME, 2),0) ACTUAL_RESULT,                           -- 실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME, 2) / GOAL_PRODUCTVITY,0) AS ACTUAL_RESULT_RATE -- 달성률
  FROM (
        -- 소결 생산 실적
        -- 소결선별, HIP선별
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
               SUM(PROD_QTY) PROD_QTY
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'HM'
           AND OPER IN ('OH23020', 'OH23050')
         GROUP BY SUBSTR(WORK_DATE,0,6) 
       ) A,
       (
        -- 소결 투입 공수
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
            SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME
          FROM CWIPWRKINP
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND OPER = 'HP005'  -- 소결
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
         GROUP BY SUBSTR(WORK_DATE,0,6)        
       ) B,
       (
        -- 목표 생산성
        SELECT WORK_MONTH, GOAL_PRODUCTVITY
          FROM CWIPPRDGOL
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND SHOP = 'HL004'      -- 소결
           AND OPER_GRP = 'HP005'  -- 소결(압출)
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
           AND KIND = 'P'
           AND CLASS='MONTH'
           AND WEEK_OF_MONTH = 1
       ) C
  WHERE A.WORK_MONTH=B.WORK_MONTH(+)
    AND A.WORK_MONTH=C.WORK_MONTH(+)
;

-- 압출 시간당 생산성 실적 : (MD Kneading + MD Extruding 실적량) ÷ MD 압출 투입 공수 시간
SELECT NVL(GOAL_PRODUCTVITY,0) GOAL_PRODUCTVITY,                                                -- 계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME, 2),0) ACTUAL_RESULT,                           -- 실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME, 2) / GOAL_PRODUCTVITY,0) AS ACTUAL_RESULT_RATE -- 달성률
  FROM (
        -- 생산성 실적 : (MD Kneading + MD Extruding 실적량) 
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
               SUM(PROD_QTY) PROD_QTY
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'HM'
           AND OPER IN ('OH21010', 'OH22010')    
         GROUP BY SUBSTR(WORK_DATE,0,6) 
       ) A,
       (
        -- 투입 공수
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
            SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME
          FROM CWIPWRKINP
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND OPER = 'HP004'  -- MD 압출
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
         GROUP BY SUBSTR(WORK_DATE,0,6)        
       ) B,
       (
        -- 목표 생산성
        SELECT WORK_MONTH, GOAL_PRODUCTVITY
          FROM CWIPPRDGOL
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND SHOP = 'HL003'      -- 압출
           AND OPER_GRP = 'HP004'  -- MD 압출
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
           AND KIND = 'P'
           AND CLASS='MONTH'
           AND WEEK_OF_MONTH = 1
       ) C
  WHERE A.WORK_MONTH=B.WORK_MONTH(+)
    AND A.WORK_MONTH=C.WORK_MONTH(+)
;

-- 압출가공 시간당 생산성 실적 : MD절단 + 가공(양두연삭) + 가공(평면연삭) + 가공(외경평면) + 가공(외경양두) + 양끝절단 + Blank 절단 실적량 ÷ 압출가공 투입 공수 시간
SELECT NVL(GOAL_PRODUCTVITY,0) GOAL_PRODUCTVITY,                                                -- 계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME, 2),0) ACTUAL_RESULT,                           -- 실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME, 2) / GOAL_PRODUCTVITY,0) AS ACTUAL_RESULT_RATE -- 달성률
  FROM (
        -- 생산성 실적 : MD절단 + 가공(양두연삭) + 가공(평면연삭) + 가공(외경평면) + 가공(외경양두) + 양끝절단 + Blank 절단 실적량 
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
               SUM(PROD_QTY) PROD_QTY
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'HM'
           AND OPER IN ('OH24010', 'OH24020', 'OH24030', 'OH24040', 'OH24060', 'OH24070', 'OH24090')
         GROUP BY SUBSTR(WORK_DATE,0,6) 
       ) A,
       (
        -- 투입 공수
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
            SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME
          FROM CWIPWRKINP
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND OPER = 'HP007'  -- 압출가공
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
         GROUP BY SUBSTR(WORK_DATE,0,6)        
       ) B,
       (
        -- 목표 생산성
        SELECT WORK_MONTH, GOAL_PRODUCTVITY
          FROM CWIPPRDGOL
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND SHOP = 'HL006'      -- 압출가공
           AND OPER_GRP = 'HP007'  -- 압출가공
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
           AND KIND = 'P'
           AND CLASS='MONTH'
           AND WEEK_OF_MONTH = 1
       ) C
  WHERE A.WORK_MONTH=B.WORK_MONTH(+)
    AND A.WORK_MONTH=C.WORK_MONTH(+)
;


