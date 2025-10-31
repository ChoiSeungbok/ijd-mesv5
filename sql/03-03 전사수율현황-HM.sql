WITH PROD_LIST AS (
        SELECT WORK_MONTH, WORK_WEEK, WORK_DATE,OPER, 
            NVL(SUM(PROD_QTY),0) PROD_QTY,
            NVL(SUM(PROD_IN_QTY),0) PROD_IN_QTY                
        FROM (
            SELECT SUBSTR(A.WORK_DATE,1,6) AS WORK_MONTH,    
                    SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W' AS WORK_WEEK,
                    A.WORK_DATE,                                       
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
                             WHEN A.OPER IN ('OH24010', 'OH24020', 'OH24090') THEN PROD_IN_QTY   
                             WHEN A.OPER IN ('OH24050') THEN PROD_IN_QTY   
                             WHEN A.OPER IN ('OH24030','OH24040','OH24060','OH24070') THEN PROD_IN_QTY
                             WHEN A.OPER IN ('OH24110') THEN PROD_IN_QTY 
                         END),0) PROD_IN_QTY                      
            FROM CSUMWIPOPR A,  MWIPCALDEF B
            WHERE A.FACTORY = 'IJDK1'                      
               AND A.AREA_ID='HM'        
               AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               AND MAT_CLASS IN ('MDS', 'MDC', 'EDR')             
               AND A.OPER IN ('OH22010', 'OH22020', 'OH22040', 
                              'OH23020', 'OH23050', 
                              'OH24010', 'OH24020', 'OH24030', 'OH24040', 'OH24050', 'OH24060', 'OH24070', 'OH24090', 
                              'OH24110')                                          
                AND A.FACTORY = B.CALENDAR_ID
                AND A.WORK_DATE = B.SYS_DATE
           GROUP BY SUBSTR(A.WORK_DATE,1,6),    
                    SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W',
                    A.WORK_DATE, A.OPER
     )
     GROUP BY WORK_MONTH, WORK_WEEK, WORK_DATE,OPER
)
,MONTH_YIELD AS (
   SELECT ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
   FROM (          
        SELECT DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM', OPER) OPER, EXP(SUM(LN(MAT_YIELD))) MAT_YIELD 
        FROM (
            SELECT OPER,
                 (CASE WHEN NVL(SUM(PROD_IN_QTY),0)>0 THEN SUM(PROD_QTY)/SUM(PROD_IN_QTY) ELSE 0 END) MAT_YIELD
            FROM PROD_LIST
            GROUP BY OPER
        )          
        GROUP BY DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM',OPER)
    )
)
,WEEK_YIELD AS (    
   SELECT ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
   FROM (          
        SELECT DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM', OPER) OPER, EXP(SUM(LN(MAT_YIELD))) MAT_YIELD 
        FROM (
            SELECT OPER,
                 (CASE WHEN NVL(SUM(PROD_IN_QTY),0)>0 THEN SUM(PROD_QTY)/SUM(PROD_IN_QTY) ELSE 0 END) MAT_YIELD
            FROM PROD_LIST  A, MWIPCALDEF B   
            WHERE B.CALENDAR_ID='IJDK1'
                AND A.WORK_WEEK = (SELECT  SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W'
                      FROM MWIPCALDEF
                     WHERE CALENDAR_ID = 'IJDK1'
                            AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')))         
            GROUP BY OPER
        )          
        GROUP BY DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM',OPER)
    )
)
,TODAY_YIELD AS (

   SELECT ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
   FROM (          
        SELECT DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM', OPER) OPER, EXP(SUM(LN(MAT_YIELD))) MAT_YIELD 
        FROM (
            SELECT OPER,
                 (CASE WHEN NVL(SUM(PROD_IN_QTY),0)>0 THEN SUM(PROD_QTY)/SUM(PROD_IN_QTY) ELSE 0 END) MAT_YIELD
            FROM PROD_LIST
            WHERE WORK_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))   
            GROUP BY OPER
        )          
        GROUP BY DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM',OPER)
    )    
)
,GOAL_YIELD AS (
    SELECT WORK_MONTH, GOAL_YIELD
          FROM CWIPPRDGOL
         WHERE FACTORY = 'IJDK1'
           AND KIND = 'Y'
           AND CLASS='MONTH'
           AND WEEK_OF_MONTH = 1
           AND AREA_ID = 'CTM'
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
)
SELECT NVL(A.YIELD,0) AS YIELD,                                     --월 실적 
       NVL(D.GOAL_YIELD,0) GOAL_YIELD,                              --월 계획
       NVL(B.YIELD,0) AS YIELD_W,                                   --주간 실적
       NVL(C.YIELD,0) AS YIED_RATE,                                --당일 실적       
       ROUND(NVL(C.YIELD/D.GOAL_YIELD,0)*100,1) AS M_YIELD_RATE     --월 달성율
FROM MONTH_YIELD A, WEEK_YIELD B, TODAY_YIELD C, GOAL_YIELD D
;

-- 일간 수율
WITH PROD_LIST AS (
        SELECT WORK_MONTH, WORK_WEEK, WORK_DATE,OPER, 
            NVL(SUM(PROD_QTY),0) PROD_QTY,
            NVL(SUM(PROD_IN_QTY),0) PROD_IN_QTY                
        FROM (
            SELECT SUBSTR(A.WORK_DATE,1,6) AS WORK_MONTH,    
                    SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W' AS WORK_WEEK,
                    A.WORK_DATE,                                       
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
                             WHEN A.OPER IN ('OH24010', 'OH24020', 'OH24090') THEN PROD_IN_QTY   
                             WHEN A.OPER IN ('OH24050') THEN PROD_IN_QTY   
                             WHEN A.OPER IN ('OH24030','OH24040','OH24060','OH24070') THEN PROD_IN_QTY
                             WHEN A.OPER IN ('OH24110') THEN PROD_IN_QTY 
                         END),0) PROD_IN_QTY                      
            FROM CSUMWIPOPR A,  MWIPCALDEF B
            WHERE A.FACTORY = 'IJDK1'                      
               AND A.AREA_ID='HM'        
               AND WORK_DATE BETWEEN F_GET_WORK_DATE(TO_CHAR(SYSDATE-8, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               AND MAT_CLASS IN ('MDS', 'MDC', 'EDR')             
               AND A.OPER IN ('OH22010', 'OH22020', 'OH22040', 
                              'OH23020', 'OH23050', 
                              'OH24010', 'OH24020', 'OH24030', 'OH24040', 'OH24050', 'OH24060', 'OH24070', 'OH24090', 
                              'OH24110')                                          
                AND A.FACTORY = B.CALENDAR_ID
                AND A.WORK_DATE = B.SYS_DATE
           GROUP BY SUBSTR(A.WORK_DATE,1,6),    
                    SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W',
                    A.WORK_DATE, A.OPER
     )
     GROUP BY WORK_MONTH, WORK_WEEK, WORK_DATE,OPER
)
, CAL AS (
    SELECT /*+ INDEX_DESC(A MWIPCALDEF_PK) */ SYS_DATE WORK_DATE
          FROM MWIPCALDEF A
         WHERE CALENDAR_ID = 'IJDK1'
           AND SYS_DATE <= F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
        FETCH FIRST 9 ROW ONLY
 )
,DAY_YIELD AS (       
   SELECT A.WORK_DATE, B.YIELD
   FROM  CAL A,(          
            SELECT WORK_DATE, ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
            FROM (
                    SELECT WORK_DATE, DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM', OPER) OPER, EXP(SUM(LN(MAT_YIELD))) MAT_YIELD 
                    FROM (
                        SELECT WORK_DATE, OPER,
                             (CASE WHEN NVL(PROD_IN_QTY,0)>0 THEN PROD_QTY/PROD_IN_QTY ELSE 0 END) MAT_YIELD
                        FROM PROD_LIST  
                    )          
                    GROUP BY WORK_DATE, DECODE(OPER, 'REFORM1','REFORM','REFORM2','REFORM','REFORM3','REFORM',OPER)
                ) 
               GROUP BY WORK_DATE
           ) B
    WHERE A.WORK_DATE = B.WORK_DATE(+)  
)
,GOAL_YIELD AS (
    SELECT WORK_MONTH, GOAL_YIELD
          FROM CWIPPRDGOL
         WHERE FACTORY = 'IJDK1'
           AND KIND = 'Y'
           AND CLASS='MONTH'
           AND WEEK_OF_MONTH = 1
           AND AREA_ID = 'CTM'
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
)
SELECT TO_CHAR(TO_DATE(WORK_DATE,'YYYYMMDD'),'MM-DD') AS WORK_DATE, NVL(YIELD,0) T_YIELD , B.GOAL_YIELD AS IND_VAL
    , WORK_DATE AS SEQ
FROM DAY_YIELD A, GOAL_YIELD B
ORDER BY 4 
;
 ;

-- 월간 Worst Loss
SELECT B.WORK_DATE, B.LOSS_CODE, B.LOSS_DESC, B.SEQ, ROUND(B.LOSS_QTY / A.PROD_QTY * 100, 1) LOSS_RATE
  FROM (
        -- 월간 작업량
        SELECT SUM(A.PROD_QTY + A.LOSS_QTY) PROD_QTY
          FROM CSUMWIPOPR A
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'HM'          
       ) A,
       (
        SELECT A.WORK_DATE, A.LOSS_CODE, B.DATA_1 LOSS_DESC, B.DATA_2 SEQ, SUM(A.LOSS_QTY) LOSS_QTY
          FROM CSUMWIPLOS A, MGCMTBLDAT B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'HM'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.FACTORY = B.FACTORY
           AND A.AREA_ID = B.KEY_1
           AND A.LOSS_CODE = B.KEY_2
           AND B.TABLE_NAME = 'C_WORST_LOSS'
         GROUP BY A.WORK_DATE, A.LOSS_CODE, B.DATA_1, B.DATA_2
         ORDER BY A.WORK_DATE, B.DATA_2
       ) B
;

-- 9일간 Worst 불량 내역
WITH CAL AS (
        SELECT /*+ INDEX_DESC(A MWIPCALDEF_PK) */ SYS_DATE WORK_DATE
          FROM MWIPCALDEF A
         WHERE CALENDAR_ID = 'IJDK1'
           AND SYS_YEAR = TO_NUMBER(SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 4))
           AND HOLIDAY_FLAG = ' '
           AND SYS_DATE <= F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
        FETCH FIRST 9 ROW ONLY
)
SELECT C.WORK_DATE, NVL(B.KEY_2, 'TOT') LOSS_CODE, B.DATA_1 LOSS_DESC, NVL(SUM(A.LOSS_QTY), 0) LOSS_QTY
  FROM CSUMWIPLOS A, MGCMTBLDAT B, CAL C
 WHERE C.WORK_DATE = A.WORK_DATE(+)
   AND A.FACTORY(+) = 'IJDK1'
   AND A.AREA_ID(+) = 'HM'
   AND A.FACTORY(+) = B.FACTORY
   AND A.AREA_ID(+) = B.KEY_1
   AND A.LOSS_CODE(+) = B.KEY_2
   AND B.TABLE_NAME = 'C_WORST_LOSS'
 GROUP BY ROLLUP(C.WORK_DATE, B.KEY_2, B.DATA_1, B.DATA_2)
 HAVING GROUPING_ID(C.WORK_DATE, B.KEY_2, B.DATA_1, B.DATA_2) IN (0, 7)
 ;