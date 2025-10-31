
/*공정현황_장비현황(전체)*/
SELECT AREA_ID, RES_GRP_2, RES_GRP_2_DESC,
        STOP_CNT, WAIT_CNT, RUN_CNT,  
        RES_TOT_CNT, --총수량
       (CASE WHEN RES_TOT_CNT>0 THEN ROUND(RUN_CNT / RES_TOT_CNT *100,1) END)AS RUN_RATE  --가동현황
FROM (
    SELECT  RES.AREA_ID, RES.RES_GRP_2, GRP.DATA_1 AS RES_GRP_2_DESC,  
            COUNT(RES_ID) AS RES_TOT_CNT,
            SUM(CASE WHEN RES_PRI_STS='D' THEN 1 ELSE 0 END) AS STOP_CNT ,   --정지
            SUM(CASE WHEN RES_PRI_STS='I' THEN 1 ELSE 0 END) AS WAIT_CNT ,   --대기
            SUM(CASE WHEN RES_PRI_STS='R' THEN 1 ELSE 0 END) AS RUN_CNT     --가동
    FROM MRASRESDEF RES,
         MGCMTBLDAT GRP       
    WHERE RES.FACTORY=GRP.FACTORY(+)
         AND TABLE_NAME(+)='RES_GRP_2' 
         AND RES.RES_GRP_2=GRP.KEY_1(+) 
         AND RES.FACTORY='IJDK1'
         AND RES.AREA_ID='HM'      --AREA:HM,CTM,HM,PDC
         --AND RES.RES_GRP_2='F010' --  F010:성형,F002:EDR 압출,F004:MD 압출,F011:소결,F012:압출가공
         AND RES.RES_GRP_2 != ' '  AND RES.RES_GRP_2 IS NOT NULL
    GROUP BY RES.AREA_ID, RES.RES_GRP_2, GRP.DATA_1 
)
;

/*공정현황_생산현황_성형*/
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                          -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                          -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE,				-- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0) TOD_PLAN_QTY,												-- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,					-- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY															-- 재공
	    ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T
  FROM  (     
        --생산실적:성형가공 실적량
        SELECT                 
            SUM(PROD_QTY) MONTH_PROD_QTY,  --당월 실적
            SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) TOD_PROD_QTY --당일 실적
        FROM CSUMWIPOPR                            
        WHERE FACTORY = 'IJDK1'
            AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND AREA_ID = 'HM'         
            AND OPER IN ('OH11020')--성형가공                          
        ) A,
       (
        -- 생산계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량                 
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND OPER IN ('OH11020')--성형가공
       ) B,
       (
        -- 공정 재공
        SELECT SUM(QTY_1) AS WIP_QTY
          FROM MWIPLOTSTS
         WHERE FACTORY = 'IJDK1'
           AND OPER IN ('OH11010')--CIP 성형
           AND LOT_DEL_FLAG<>'Y'
       ) C
 ;
 
 /*공정현황_생산현황_소결*/
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                          -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                          -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE,				-- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0) TOD_PLAN_QTY,												-- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,					-- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY															-- 재공
	    ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T
  FROM 
       (        
		--생산실적:소결선별, HIP선별 실적량
		SELECT                 
			SUM(PROD_QTY) MONTH_PROD_QTY,  --당월 실적
			SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) TOD_PROD_QTY --당일 실적
		 FROM CSUMWIPOPR                            
		 WHERE FACTORY = 'IJDK1'
		   AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND AREA_ID = 'HM'		  
		   AND OPER IN ('OH23020', 'OH23050') --소결선별, HIP선별
                          
        ) A,
       (
        -- 생산계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량                 
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND OPER IN ('OH23020', 'OH23050') --소결선별, HIP선별
       ) B,
       (
        -- 공정 전체 재공 재고 합계
        SELECT SUM(QTY_1) AS WIP_QTY
          FROM MWIPLOTSTS
         WHERE FACTORY = 'IJDK1'
           AND OPER IN ('OH23010','OH23020','OH23030','OH23040','OH23050') --소결(Sinter-HIP),소결선별,소결(Sinter),HIP,HIP선별
           AND LOT_DEL_FLAG<>'Y'
       ) C
 ;
 
 /*공정현황_생산현황_EDR 압출*/
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                          -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                          -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE,				-- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0) TOD_PLAN_QTY,												-- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,					-- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY															-- 재공
	    ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T
  FROM 
       (        
		--생산실적: EDR Extruding + 성형 절단(D-CIP) 실적량
		SELECT                 
			SUM(PROD_QTY) MONTH_PROD_QTY,  --당월 실적
			SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) TOD_PROD_QTY --당일 실적
		  FROM CSUMWIPOPR                            
		 WHERE FACTORY = 'IJDK1'
		   AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND AREA_ID = 'HM'		  
		   AND OPER IN ('OH22020', 'OH22040')
                          
        ) A,
       (
        -- 생산계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,                   
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND OPER IN ('OH22020', 'OH22040')
       ) B,
       (
        -- 공정 전체 재공 재고 합계
        SELECT SUM(QTY_1) AS WIP_QTY
          FROM MWIPLOTSTS
         WHERE FACTORY = 'IJDK1'
           AND OPER IN ('OH22030') --성형/성형가공(D-CIP)
           AND LOT_DEL_FLAG<>'Y'
       ) C
 ;
 
  /*공정현황_생산현황_MD 압출*/ 
 SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                          -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                          -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE,				-- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0) TOD_PLAN_QTY,												-- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,					-- 당일달성률
       0 AS WIP_QTY															-- 재공
	    ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T
  FROM 
       (        
		--생산실적:MD Extruding 실적량
		SELECT                 
			SUM(PROD_QTY) MONTH_PROD_QTY, 
			SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) TOD_PROD_QTY --당일 실적
		  FROM CSUMWIPOPR                            
		 WHERE FACTORY = 'IJDK1'
		   AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND AREA_ID = 'HM'		  
		   AND OPER IN ('OH22010')   
                          
        ) A,
       (
        -- 생산계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,                   
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND OPER IN ('OH21010')
       ) B
 ;
  /*공정현황_생산현황_압출 가공 */ 
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                          -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                          -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE,				-- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0) TOD_PLAN_QTY,												-- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,					-- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY															-- 재공
	    ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T
  FROM 
       (        
		--생산실적:가공(양두연삭) 가공(평면연삭) 가공(외경평면) 가공(외경양두) 양끝절단  실적량
		SELECT                 
			SUM(PROD_QTY) MONTH_PROD_QTY,  --당월 실적
			SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) TOD_PROD_QTY --당일 실적
		  FROM CSUMWIPOPR                            
		 WHERE FACTORY = 'IJDK1'
		   AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND AREA_ID = 'HM'		 
		   AND OPER IN ('OH24030', 'OH24040', 'OH24060', 'OH24070', 'OH24090')
                          
        ) A,
       (
        -- 생산계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량                 
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'HM'
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND OPER IN ('OH24030', 'OH24040', 'OH24060', 'OH24070', 'OH24090')
       ) B,
       (
        -- 공정 전체 재공 재고 합계
        SELECT SUM(QTY_1) AS WIP_QTY
          FROM MWIPLOTSTS
         WHERE FACTORY = 'IJDK1'
           AND OPER IN ('OH24080', 'OH24010', 'OH24020', 'OH24050') --샌딩,MD 절단,Blank 절단,가공(센터리스)
           AND LOT_DEL_FLAG<>'Y'
       ) C
 ;
 
 /*생산성_성형*/
 SELECT NVL(PROD_GOAL_PROD,0) GOAL_M,
       NVL(WEEK_GOAL_PROD,0) GOAL_W,                                   -- 계획
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2),0) AS MONTH_PROD_RESULT,      -- 당월 실적
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) / PROD_GOAL_PROD,0) AS MONTH_PROD_RATE, -- 당월 달성률
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2),0) AS WEEK_PROD_RESULT,      -- 주간 실적
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) / WEEK_GOAL_PROD,0) AS WEEK_PROD_RATE  -- 주간 달성률
        ,CASE WHEN PROD_GOAL_PROD > ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN PROD_GOAL_PROD < ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2)
                        ELSE PROD_GOAL_PROD END
                AS MAX_VAL_MON
        ,CASE WHEN WEEK_GOAL_PROD > ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN WEEK_GOAL_PROD < ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2)
                        ELSE WEEK_GOAL_PROD END
                AS MAX_VAL_WEEK            
  FROM (
        -- 생산 실적
		-- 성형가공 실적량 ÷ 성형 투입 공수 시간
         SELECT SUM(PROD_QTY) MOM_PROD_QTY, --당월
           SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN PROD_QTY END) WEEK_PROD_QTY -- 주간  
        FROM CSUMWIPOPR A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
        WHERE A.FACTORY = 'IJDK1'
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.AREA_ID = 'HM'
            AND OPER IN ('OH11020')--성형가공           
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) A,
       (
        -- 투입 공수
        SELECT SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME, --월간 
            SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN TOTAL_WORK_TIME END) WEEK_WORK_TIME -- 주간   
          FROM CWIPWRKINP A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
         WHERE A.FACTORY = 'IJDK1'
            AND A.AREA_ID = 'HM'
            AND A.OPER = 'HP002'  -- 성형(내마모)
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) B,
       (
        -- 목표 생산성
         SELECT MAX(CASE WHEN CLASS='MONTH' AND WEEK_OF_MONTH=1 THEN A.GOAL_PRODUCTVITY END) AS PROD_GOAL_PROD,
                MAX(CASE WHEN CLASS='WEEK' AND WEEK_OF_MONTH = CAL_CMF_1 THEN A.GOAL_PRODUCTVITY END) AS WEEK_GOAL_PROD            
         FROM CWIPPRDGOL A, (
                SELECT CAL_CMF_1
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) B        
         WHERE A.FACTORY = 'IJDK1'
           AND A.KIND='P'          
		   AND A.CLASS='MONTH'
		   AND A.WEEK_OF_MONTH = 1         
           AND A.AREA_ID = 'HM'                      
           AND A.SHOP = 'HL002'      -- 성형(내마모)
           AND A.OPER_GRP = 'HP002'  -- 성형(내마모)
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6) 
          
       ) C
    ;   
	
 /*생산성_소결*/
SELECT NVL(PROD_GOAL_PROD,0) GOAL_M,
       NVL(WEEK_GOAL_PROD,0) GOAL_W,                                   -- 계획
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2),0) AS MONTH_PROD_RESULT,      -- 당월 실적
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) / PROD_GOAL_PROD,0) AS MONTH_PROD_RATE, -- 당월 달성률
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2),0) AS WEEK_PROD_RESULT,      -- 주간 실적
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) / WEEK_GOAL_PROD,0) AS WEEK_PROD_RATE  -- 주간 달성률
        ,CASE WHEN PROD_GOAL_PROD > ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN PROD_GOAL_PROD < ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2)
                        ELSE PROD_GOAL_PROD END
                AS MAX_VAL_MON
        ,CASE WHEN WEEK_GOAL_PROD > ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN WEEK_GOAL_PROD < ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2)
                        ELSE WEEK_GOAL_PROD END
                AS MAX_VAL_WEEK                
  FROM (        
        -- (소결선별 생산(완공처리)량 + HIP선별 생산(완공처리)량) ÷ 소결(압출,내마모) 투입 공수 시간    
         SELECT SUM(PROD_QTY) MOM_PROD_QTY, --당월
           SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN PROD_QTY END) WEEK_PROD_QTY -- 주간    
        FROM CSUMWIPOPR A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
        WHERE A.FACTORY = 'IJDK1'
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.AREA_ID = 'HM'
            AND A.OPER IN ('OH23020', 'OH23050')            
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) A,
       (
        -- 투입 공수
        SELECT SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME, --월간
            SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN TOTAL_WORK_TIME END) WEEK_WORK_TIME -- 주간
          FROM CWIPWRKINP A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
         WHERE A.FACTORY = 'IJDK1'
            AND A.AREA_ID = 'HM'
            AND A.OPER = 'HP005'  -- 소결
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) B,
       (
        -- 목표 생산성
         SELECT MAX(CASE WHEN CLASS='MONTH' AND WEEK_OF_MONTH=1 THEN A.GOAL_PRODUCTVITY END) AS PROD_GOAL_PROD,
                MAX(CASE WHEN CLASS='WEEK' AND WEEK_OF_MONTH = CAL_CMF_1 THEN A.GOAL_PRODUCTVITY END) AS WEEK_GOAL_PROD            
         FROM CWIPPRDGOL A, (
                SELECT CAL_CMF_1
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) B        
         WHERE A.FACTORY = 'IJDK1'
           AND A.KIND='P'          
		   AND A.CLASS='MONTH'
		   AND A.WEEK_OF_MONTH = 1          
           AND A.AREA_ID = 'HM'                      
           AND A.SHOP ='HL004'      -- 소결
           AND A.OPER_GRP =  'HP005'  -- 소결(압출)
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6) 
          
       ) C
    ;   
 
/*생산성_EDR 압출*/
SELECT NVL(PROD_GOAL_PROD,0) GOAL_M,
       NVL(WEEK_GOAL_PROD,0) GOAL_W,                                   -- 계획
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2),0) AS MONTH_PROD_RESULT,      -- 당월 실적
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) / PROD_GOAL_PROD,0) AS MONTH_PROD_RATE, -- 당월 달성률
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2),0) AS WEEK_PROD_RESULT,      -- 주간 실적
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) / WEEK_GOAL_PROD,0) AS WEEK_PROD_RATE  -- 주간 달성률
        ,CASE WHEN PROD_GOAL_PROD > ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN PROD_GOAL_PROD < ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2)
                        ELSE PROD_GOAL_PROD END
                AS MAX_VAL_MON
        ,CASE WHEN WEEK_GOAL_PROD > ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN WEEK_GOAL_PROD < ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2)
                        ELSE WEEK_GOAL_PROD END
                AS MAX_VAL_WEEK     
  FROM (
        -- 생산 실적
        -- (EDR Kneading + EDR Extruding + 성형/성형가공(D-CIP) 실적량) ÷ EDR 압출 투입 공수 시간     
         SELECT SUM(PROD_QTY) MOM_PROD_QTY, --당월실적
           SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN PROD_QTY END) WEEK_PROD_QTY -- 주간 실적   
        FROM CSUMWIPOPR A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
        WHERE A.FACTORY = 'IJDK1'
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.AREA_ID = 'HM'
            AND A.OPER IN ('OH21020', 'OH22020', 'OH22030') --EDR Kneading + EDR Extruding + 성형/성형가공(D-CIP) 실적량           
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) A,
       (
        -- 투입 공수
        SELECT SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME, --월간
            SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN TOTAL_WORK_TIME END) WEEK_WORK_TIME -- 주간 
          FROM CWIPWRKINP A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
         WHERE A.FACTORY = 'IJDK1'
            AND A.AREA_ID = 'HM'
            AND A.OPER = 'HP003'  -- 압출
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) B,
       (
        -- 목표 생산성
         SELECT MAX(CASE WHEN CLASS='MONTH' AND WEEK_OF_MONTH=1 THEN A.GOAL_PRODUCTVITY END) AS PROD_GOAL_PROD,
                MAX(CASE WHEN CLASS='WEEK' AND WEEK_OF_MONTH = CAL_CMF_1 THEN A.GOAL_PRODUCTVITY END) AS WEEK_GOAL_PROD            
         FROM CWIPPRDGOL A, (
                SELECT CAL_CMF_1
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) B        
         WHERE A.FACTORY = 'IJDK1'
           AND A.KIND='P'          
		   AND A.CLASS='MONTH'
		   AND A.WEEK_OF_MONTH = 1         
           AND A.AREA_ID = 'HM'                      
           AND A.SHOP = 'HL003'      -- 압출
           AND A.OPER_GRP = 'HP003'  -- EDR 압출
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6) 
          
       ) C
;

/*생산성_MD 압출*/
SELECT NVL(PROD_GOAL_PROD,0) GOAL_M,
       NVL(WEEK_GOAL_PROD,0) GOAL_W,                                   -- 계획
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2),0) AS MONTH_PROD_RESULT,      -- 당월 실적
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) / PROD_GOAL_PROD,0) AS MONTH_PROD_RATE, -- 당월 달성률
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2),0) AS WEEK_PROD_RESULT,      -- 주간 실적
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) / WEEK_GOAL_PROD,0) AS WEEK_PROD_RATE  -- 주간 달성률
        ,CASE WHEN PROD_GOAL_PROD > ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN PROD_GOAL_PROD < ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2)
                        ELSE PROD_GOAL_PROD END
                AS MAX_VAL_MON
        ,CASE WHEN WEEK_GOAL_PROD > ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN WEEK_GOAL_PROD < ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2)
                        ELSE WEEK_GOAL_PROD END
                AS MAX_VAL_WEEK     
  FROM (
        -- 생산 실적
        -- (MD Kneading + MD Extruding 실적량) ÷ MD 압출 투입 공수 시간
         SELECT SUM(PROD_QTY) MOM_PROD_QTY, --당월실적
           SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN PROD_QTY END) WEEK_PROD_QTY -- 주간 실적   
        FROM CSUMWIPOPR A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
        WHERE A.FACTORY = 'IJDK1'
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.AREA_ID = 'HM'
            AND A.OPER IN ('OH21010', 'OH22010')           
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) A,
       (
        -- 투입 공수
        SELECT SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME, --월간
            SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN TOTAL_WORK_TIME END) WEEK_WORK_TIME -- 주간
          FROM CWIPWRKINP A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
         WHERE A.FACTORY = 'IJDK1'
            AND A.AREA_ID = 'HM'
            AND A.OPER = 'HP004'  -- 압출
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) B,
       (
        -- 목표 생산성
         SELECT MAX(CASE WHEN CLASS='MONTH' AND WEEK_OF_MONTH=1 THEN A.GOAL_PRODUCTVITY END) AS PROD_GOAL_PROD,
                MAX(CASE WHEN CLASS='WEEK' AND WEEK_OF_MONTH = CAL_CMF_1 THEN A.GOAL_PRODUCTVITY END) AS WEEK_GOAL_PROD            
         FROM CWIPPRDGOL A, (
                SELECT CAL_CMF_1
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) B        
         WHERE A.FACTORY = 'IJDK1'
           AND A.KIND='P'          
		   AND A.CLASS='MONTH'
		   AND A.WEEK_OF_MONTH = 1       
           AND A.AREA_ID = 'HM'                      
           AND A.SHOP = 'HL003'  -- 압출
           AND A.OPER_GRP = 'HP004'  -- MD 압출
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6) 
          
       ) C
    ;   
/*생산성_압출 가공*/
SELECT NVL(PROD_GOAL_PROD,0) GOAL_M,
       NVL(WEEK_GOAL_PROD,0) GOAL_W,                                   -- 계획
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2),0) AS MONTH_PROD_RESULT,      -- 당월 실적
       NVL(ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) / PROD_GOAL_PROD,0) AS MONTH_PROD_RATE, -- 당월 달성률
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2),0) AS WEEK_PROD_RESULT,      -- 주간 실적
       NVL(ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) / WEEK_GOAL_PROD,0) AS WEEK_PROD_RATE  -- 주간 달성률
        ,CASE WHEN PROD_GOAL_PROD > ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN PROD_GOAL_PROD < ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2) THEN ROUND(A.MOM_PROD_QTY / B.TOTAL_WORK_TIME, 2)
                        ELSE PROD_GOAL_PROD END
                AS MAX_VAL_MON
        ,CASE WHEN WEEK_GOAL_PROD > ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN PROD_GOAL_PROD
                WHEN WEEK_GOAL_PROD < ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2) THEN ROUND(A.WEEK_PROD_QTY / B.WEEK_WORK_TIME, 2)
                        ELSE WEEK_GOAL_PROD END
                AS MAX_VAL_WEEK     
  FROM (
        -- 생산 실적 :MD절단 + 가공(양두연삭) + 가공(평면연삭) + 가공(외경평면) + 가공(외경양두) + 양끝절단 + Blank 절단
         SELECT SUM(PROD_QTY) MOM_PROD_QTY, 
           SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN PROD_QTY END) WEEK_PROD_QTY  
        FROM CSUMWIPOPR A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
        WHERE A.FACTORY = 'IJDK1'
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.AREA_ID = 'HM'
            AND A.OPER IN ('OH24010', 'OH24020', 'OH24030', 'OH24040', 'OH24060', 'OH24070', 'OH24090')      
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) A,
       (
        -- 투입 공수
        SELECT SUM(TOTAL_WORK_TIME) TOTAL_WORK_TIME, 
            SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN TOTAL_WORK_TIME END) WEEK_WORK_TIME  
          FROM CWIPWRKINP A, MWIPCALDEF B,
               (
                SELECT PLAN_WEEK
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) C         
         WHERE A.FACTORY = 'IJDK1'
            AND A.AREA_ID = 'HM'
            AND A.OPER = 'HP007'  -- 압출가공
            AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            AND A.FACTORY=B.CALENDAR_ID
            AND A.WORK_DATE=B.SYS_DATE
       ) B,
       (
        -- 목표 생산성
         SELECT MAX(CASE WHEN CLASS='MONTH' AND WEEK_OF_MONTH=1 THEN A.GOAL_PRODUCTVITY END) AS PROD_GOAL_PROD,
                MAX(CASE WHEN CLASS='WEEK' AND WEEK_OF_MONTH = CAL_CMF_1 THEN A.GOAL_PRODUCTVITY END) AS WEEK_GOAL_PROD            
         FROM CWIPPRDGOL A, (
                SELECT CAL_CMF_1
                  FROM MWIPCALDEF
                 WHERE CALENDAR_ID = 'IJDK1'
                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
               ) B        
         WHERE A.FACTORY = 'IJDK1'
           AND A.KIND='P'          
		   AND A.CLASS='MONTH'
		   AND A.WEEK_OF_MONTH = 1
           AND A.AREA_ID = 'HM'                      
		   AND A.SHOP = 'HL006'      -- 압출가공
           AND A.OPER_GRP = 'HP007'  -- 압출가공
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6) 
          
       ) C
    ;   
       
       