-- 장비 현황
SELECT RES_TYPE, RES_TYPE_DESC, TOTAL_RES, IDLE, RUN, STOP, ROUND(RUN/ TOTAL_RES * 100, 1) RUN_RATE
  FROM (
        SELECT A.RES_GRP_2 RES_TYPE, B.DATA_1 RES_TYPE_DESC,
               COUNT(*) TOTAL_RES,
               SUM(DECODE(A.RES_PRI_STS, 'I', 1, 0)) IDLE,
               SUM(DECODE(A.RES_PRI_STS, 'R', 1, 0)) RUN,
               SUM(DECODE(A.RES_PRI_STS, 'D', 1, 0)) STOP
          FROM MRASRESDEF A, MGCMTBLDAT B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.FACTORY = B.FACTORY
           AND B.TABLE_NAME = 'RES_GRP_2'
           AND B.KEY_1 = A.RES_GRP_2
         GROUP BY A.RES_GRP_2, B.DATA_1
       )
;

-- 생산현황
-- 전처리
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                            -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                            -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE, -- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0)TOD_PLAN_QTY,                                              -- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,     -- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY                                                   -- 재공
	   ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T
  FROM (
        -- 전처리 생산 실적
        -- (컵 완조립 Move량 + 셀 완조립 Move량)
        SELECT SUM(PROD_QTY) MONTH_PROD_QTY,  -- 당월 실적
               SUM(DECODE(WORK_DATE, F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), PROD_QTY, 0)) TOD_PROD_QTY -- 당일 실적
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'PDC'
           AND OPER IN ('OP03020', 'OP05020')
       ) A,
       (
        -- 생산 계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY -- 당일 계획량
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'PDC'
		   AND OPER IN ('OP03020', 'OP05020')
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
       ) B,
       (
        -- 재공
        SELECT SUM(QTY_1) WIP_QTY
          FROM MWIPLOTSTS
         WHERE OPER IN (
                        SELECT DISTINCT B.OPER
                          FROM MWIPFLWDEF A, MWIPFLWOPR B, MWIPOPRDEF C
                         WHERE B.FACTORY = 'IJDK1'
                           AND B.FLOW = A.FLOW
                           AND B.OPER = C.OPER
                           AND A.FLOW IN ('FP030', 'FP040', 'FP050')
                       )
           AND LOT_DEL_FLAG = ' '
       ) C
;

-- 생산현황
-- 소결
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                            -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                            -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE, -- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0)TOD_PLAN_QTY,                                              -- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,     -- 당일달성률
       0 WIP_QTY                                                   -- 재공
	   ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T                                                -- 재공
  FROM (
        -- 소결 생산 실적
        -- 소결 Move량
        SELECT SUM(PROD_QTY) MONTH_PROD_QTY,  -- 당월 실적
               SUM(DECODE(WORK_DATE, F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), PROD_QTY, 0)) TOD_PROD_QTY -- 당일 실적
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'PDC'
           AND OPER IN ('OP06010')
       ) A,
       (
        -- 생산 계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY -- 당일 계획량
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'PDC'
		   AND OPER IN ('OP06010')
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
       ) B
;

-- 생산현황
-- Lapping
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                            -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                            -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE, -- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0)TOD_PLAN_QTY,                                              -- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,     -- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY                                                   -- 재공
	   ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T                                                   -- 재공
  FROM (
        -- 랩핑 Move량
        SELECT SUM(PROD_QTY) MONTH_PROD_QTY,  -- 당월 실적
               SUM(DECODE(WORK_DATE, F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), PROD_QTY, 0)) TOD_PROD_QTY -- 당일 실적
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'PDC'
           AND OPER IN ('OP07020')
       ) A,
       (
        -- 생산 계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY -- 당일 계획량
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'PDC'
		   AND OPER IN ('OP07020')
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
       ) B,
       (
        -- 재공
        SELECT SUM(QTY_1) WIP_QTY
          FROM MWIPLOTSTS
         WHERE OPER IN (
                        SELECT DISTINCT B.OPER
                          FROM MWIPFLWDEF A, MWIPFLWOPR B, MWIPOPRDEF C
                         WHERE B.FACTORY = 'IJDK1'
                           AND B.FLOW = A.FLOW
                           AND B.OPER = C.OPER
                           AND A.FLOW IN ('FP070')
                       )
           AND LOT_DEL_FLAG = ' '
       ) C
;

-- 생산현황
-- 외경/두께 가공
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                            -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                            -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE, -- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0)TOD_PLAN_QTY,                                              -- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,     -- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY                                                   -- 재공
	   ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T                                               -- 재공
  FROM (
        -- 두께가공
        -- Brazing 전 연삭 Move량 + 1차 두께 연삭 Move량 + 외경 황삭 Move량 + 외경 정삭 Move량 + 최종 두께 연삭 Move량
        SELECT SUM(PROD_QTY) MONTH_PROD_QTY,  -- 당월 실적
               SUM(DECODE(WORK_DATE, F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), PROD_QTY, 0)) TOD_PROD_QTY -- 당일 실적
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'PDC'
           AND OPER IN ('OP08010', 'OP08030', 'OP08040', 'OP08060', 'OP08080')
       ) A,
       (
        -- 생산 계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY -- 당일 계획량
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'PDC'
		   AND OPER IN ('OP08010', 'OP08030', 'OP08040', 'OP08060', 'OP08080')
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
       ) B,
       (
        -- 재공
        SELECT SUM(QTY_1) WIP_QTY
          FROM MWIPLOTSTS
         WHERE OPER IN (
                        SELECT DISTINCT B.OPER
                          FROM MWIPFLWDEF A, MWIPFLWOPR B, MWIPOPRDEF C
                         WHERE B.FACTORY = 'IJDK1'
                           AND B.FLOW = A.FLOW
                           AND B.OPER = C.OPER
                           AND A.FLOW IN ('FP080')
                           AND B.OPER NOT IN ('OP08090', 'OP08100', 'OP08110', 'OP08120', 'PP-PNL')
                       )
           AND LOT_DEL_FLAG = ' '
       ) C
;

-- 생산현황
-- 챔퍼가공
SELECT NVL(A.MONTH_PROD_QTY,0) MONTH_PROD_QTY,                                            -- 당월실적
       NVL(B.MONTH_PLAN_QTY,0) MONTH_PLAN_QTY,                                            -- 당월계획
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100),0) MONTH_RATE, -- 당월달성률
       NVL(A.TOD_PROD_QTY,0) TOD_PROD_QTY,                                              -- 당일실적
       NVL(B.TOD_PLAN_QTY,0)TOD_PLAN_QTY,                                              -- 당일계획
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TODAY_RATE,     -- 당일달성률
       NVL(C.WIP_QTY,0) WIP_QTY                                                   -- 재공
	   ,CASE WHEN MONTH_PLAN_QTY > MONTH_PROD_QTY THEN MONTH_PLAN_QTY
             WHEN MONTH_PLAN_QTY < MONTH_PROD_QTY THEN MONTH_PROD_QTY
             ELSE MONTH_PLAN_QTY END
        AS MAX_VAL_M
       ,CASE WHEN TOD_PLAN_QTY > TOD_PROD_QTY THEN TOD_PLAN_QTY
             WHEN TOD_PLAN_QTY < TOD_PROD_QTY THEN TOD_PROD_QTY
             ELSE TOD_PLAN_QTY END
        AS MAX_VAL_T                                               -- 재공
  FROM (
        -- 챔퍼가공
        -- 1차 Dia 챔퍼 Move량 + 최종 다이아 챔퍼 Move량 + 초경 챔퍼 Move량
        SELECT SUM(PROD_QTY) MONTH_PROD_QTY,  -- 당월 실적
               SUM(DECODE(WORK_DATE, F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), PROD_QTY, 0)) TOD_PROD_QTY -- 당일 실적
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'PDC'
           AND OPER IN ('OP08050', 'OP08070', 'OP08090')
       ) A,
       (
        -- 생산 계획
        SELECT SUM(QTY) MONTH_PLAN_QTY,        -- 당월 계획량
               SUM(TO_NUMBER(DECODE(PLAN_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(QTY)))) TOD_PLAN_QTY -- 당일 계획량
          FROM CORDPRDPLN
         WHERE FACTORY = 'IJDK1'
           AND AREA_ID = 'PDC'
		    AND OPER IN ('OP08050', 'OP08070', 'OP08090')
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
       ) B,
       (
        -- 재공
        SELECT SUM(QTY_1) WIP_QTY
          FROM MWIPLOTSTS
         WHERE OPER IN (
                        SELECT DISTINCT B.OPER
                          FROM MWIPFLWDEF A, MWIPFLWOPR B, MWIPOPRDEF C
                         WHERE B.FACTORY = 'IJDK1'
                           AND B.FLOW = A.FLOW
                           AND B.OPER = C.OPER
                           AND A.FLOW IN ('FP080')
                           AND B.OPER IN ('OP08090', 'OP08100', 'OP08110', 'OP08120', 'PP-PNL')
                       )
           AND LOT_DEL_FLAG = ' '
       ) C
;

-- 생산성
-- 전처리
WITH CAL AS (
			SELECT PLAN_WEEK, CAL_CMF_1  WEEK_OF_MONTH
			  FROM MWIPCALDEF
			 WHERE CALENDAR_ID = 'IJDK1'
			   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
)
SELECT ROUND(NVL(GOAL_YEAR,0),2) GOAL_M,                                                                                                                                                        -- 월계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) MONTH_PROD_RESULT,                                                                        -- 월실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2) / GOAL_YEAR,0) MONTH_PROD_RATE,                                                      -- 월달성률
       ROUND(NVL(GOAL_WEEK,0),2) GOAL_W,                                                                                                                                                                  -- 주계획
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) WEEK_PROD_RESULT,                                                      -- 주실적
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2) / GOAL_WEEK,0)  WEEK_PROD_RATE                                             -- 주달성률
            ,CASE WHEN NVL(GOAL_YEAR,0) > NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(GOAL_YEAR,0)
                  WHEN NVL(GOAL_YEAR,0) < NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0)
                            ELSE NVL(GOAL_YEAR,0) END
                  AS MAX_VAL_MON
            ,CASE WHEN NVL(GOAL_WEEK,0) > NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(GOAL_WEEK,0)
                  WHEN NVL(GOAL_WEEK,0) < NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0)
                            ELSE NVL(GOAL_WEEK,0) END
                  AS MAX_VAL_WEEK         
  FROM (
        -- 전처리 생산 실적
        -- (컵 완조립 Move량 + 셀 완조립 Move량)
        SELECT SUM(PROD_QTY) PROD_QTY,
               SUM(CASE WHEN A.WEEK_OF_YEAR = B.PLAN_WEEK THEN A.PROD_QTY END) PROD_QTY_W
          FROM CSUMWIPOPR A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('OP03020', 'OP05020')
       ) A,
       (
        --  투입 공수
        SELECT SUM(A.TOTAL_WORK_TIME) TOTAL_WORK_TIME,
               SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN A.TOTAL_WORK_TIME END) TOTAL_WORK_TIME_W
          FROM CWIPWRKINP A, MWIPCALDEF B, CAL C
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('PP002', 'PP003')  -- 컵조립, 셀조립
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND A.FACTORY = B.CALENDAR_ID
		   AND A.WORK_DATE = B.SYS_DATE
       ) B,
       (
        --  목표 생산성
        SELECT MAX(CASE WHEN A.CLASS = 'MONTH' AND A.WEEK_OF_MONTH = '1' THEN A.GOAL_PRODUCTVITY END) GOAL_YEAR,
               MAX(CASE WHEN A.CLASS = 'WEEK' AND A.WEEK_OF_MONTH = B.WEEK_OF_MONTH THEN A.GOAL_PRODUCTVITY END) GOAL_WEEK
          FROM CWIPPRDGOL A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.SHOP = 'PL001'      -- 전처리
           AND A.OPER_GRP = 'PP002'  -- 셀조립
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) C
;

-- 생산성
-- 소결
WITH CAL AS (
			SELECT PLAN_WEEK, CAL_CMF_1  WEEK_OF_MONTH
			  FROM MWIPCALDEF
			 WHERE CALENDAR_ID = 'IJDK1'
			   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
)
SELECT ROUND(NVL(GOAL_YEAR,0),2) GOAL_M,                                                                                                                                                        -- 월계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) MONTH_PROD_RESULT,                                                                        -- 월실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2) / GOAL_YEAR,0) MONTH_PROD_RATE,                                                      -- 월달성률
       ROUND(NVL(GOAL_WEEK,0),2) GOAL_W,                                                                                                                                                                  -- 주계획
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) WEEK_PROD_RESULT,                                                      -- 주실적
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2) / GOAL_WEEK,0)  WEEK_PROD_RATE                                             -- 주달성률
            ,CASE WHEN NVL(GOAL_YEAR,0) > NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(GOAL_YEAR,0)
                  WHEN NVL(GOAL_YEAR,0) < NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0)
                            ELSE NVL(GOAL_YEAR,0) END
                  AS MAX_VAL_MON
            ,CASE WHEN NVL(GOAL_WEEK,0) > NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(GOAL_WEEK,0)
                  WHEN NVL(GOAL_WEEK,0) < NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0)
                            ELSE NVL(GOAL_WEEK,0) END
                  AS MAX_VAL_WEEK         
  FROM (
        -- 소결 생산 실적
        -- 소결 Move량
        SELECT SUM(PROD_QTY) PROD_QTY,
               SUM(CASE WHEN A.WEEK_OF_YEAR = B.PLAN_WEEK THEN A.PROD_QTY END) PROD_QTY_W
          FROM CSUMWIPOPR A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('OP06010')
       ) A,
       (
        -- 투입 공수
        SELECT SUM(A.TOTAL_WORK_TIME) TOTAL_WORK_TIME,
               SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN A.TOTAL_WORK_TIME END) TOTAL_WORK_TIME_W
          FROM CWIPWRKINP A, MWIPCALDEF B, CAL C
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('CP004')  -- 소결
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND A.FACTORY = B.CALENDAR_ID
		   AND A.WORK_DATE = B.SYS_DATE
       ) B,
       (
        --  목표 생산성
        SELECT MAX(CASE WHEN A.CLASS = 'MONTH' AND A.WEEK_OF_MONTH = '1' THEN A.GOAL_PRODUCTVITY END) GOAL_YEAR,
               MAX(CASE WHEN A.CLASS = 'WEEK' AND A.WEEK_OF_MONTH = B.WEEK_OF_MONTH THEN A.GOAL_PRODUCTVITY END) GOAL_WEEK
          FROM CWIPPRDGOL A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.SHOP = 'PL002'      -- 소결
           AND A.OPER_GRP = 'CP004'  -- 소결
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) C
;

-- 생산성
-- Lapping
WITH CAL AS (
			SELECT PLAN_WEEK, CAL_CMF_1  WEEK_OF_MONTH
			  FROM MWIPCALDEF
			 WHERE CALENDAR_ID = 'IJDK1'
			   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
)
SELECT ROUND(NVL(GOAL_YEAR,0),2) GOAL_M,                                                                                                                                                        -- 월계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) MONTH_PROD_RESULT,                                                                        -- 월실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2) / GOAL_YEAR,0) MONTH_PROD_RATE,                                                      -- 월달성률
       ROUND(NVL(GOAL_WEEK,0),2) GOAL_W,                                                                                                                                                                  -- 주계획
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) WEEK_PROD_RESULT,                                                      -- 주실적
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2) / GOAL_WEEK,0)  WEEK_PROD_RATE                                             -- 주달성률
            ,CASE WHEN NVL(GOAL_YEAR,0) > NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(GOAL_YEAR,0)
                  WHEN NVL(GOAL_YEAR,0) < NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0)
                            ELSE NVL(GOAL_YEAR,0) END
                  AS MAX_VAL_MON
            ,CASE WHEN NVL(GOAL_WEEK,0) > NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(GOAL_WEEK,0)
                  WHEN NVL(GOAL_WEEK,0) < NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0)
                            ELSE NVL(GOAL_WEEK,0) END
                  AS MAX_VAL_WEEK         
  FROM (
        -- Lapping 생산 실적
        -- 랩핑 Move량
        SELECT SUM(PROD_QTY) PROD_QTY,
               SUM(CASE WHEN A.WEEK_OF_YEAR = B.PLAN_WEEK THEN A.PROD_QTY END) PROD_QTY_W
          FROM CSUMWIPOPR A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('OP07020')
       ) A,
       (
        -- 투입 공수
        SELECT SUM(A.TOTAL_WORK_TIME) TOTAL_WORK_TIME,
               SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN A.TOTAL_WORK_TIME END) TOTAL_WORK_TIME_W
          FROM CWIPWRKINP A, MWIPCALDEF B, CAL C
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('PP007')  -- Lapping
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND A.FACTORY = B.CALENDAR_ID
		   AND A.WORK_DATE = B.SYS_DATE
       ) B,
       (
        -- 목표 생산성
        SELECT MAX(CASE WHEN A.CLASS = 'MONTH' AND A.WEEK_OF_MONTH = '1' THEN A.GOAL_PRODUCTVITY END) GOAL_YEAR,
               MAX(CASE WHEN A.CLASS = 'WEEK' AND A.WEEK_OF_MONTH = B.WEEK_OF_MONTH THEN A.GOAL_PRODUCTVITY END) GOAL_WEEK
          FROM CWIPPRDGOL A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.SHOP = 'PL003'      -- 가공
           AND A.OPER_GRP = 'PP007'  -- Lapping
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) C
;

-- 생산성
-- 두께가공
WITH CAL AS (
			SELECT PLAN_WEEK, CAL_CMF_1  WEEK_OF_MONTH
			  FROM MWIPCALDEF
			 WHERE CALENDAR_ID = 'IJDK1'
			   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
)
SELECT ROUND(NVL(GOAL_YEAR,0),2) GOAL_M,                                                                                                                                                        -- 월계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) MONTH_PROD_RESULT,                                                                        -- 월실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2) / GOAL_YEAR,0) MONTH_PROD_RATE,                                                      -- 월달성률
       ROUND(NVL(GOAL_WEEK,0),2) GOAL_W,                                                                                                                                                                  -- 주계획
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) WEEK_PROD_RESULT,                                                      -- 주실적
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2) / GOAL_WEEK,0)  WEEK_PROD_RATE                                             -- 주달성률
            ,CASE WHEN NVL(GOAL_YEAR,0) > NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(GOAL_YEAR,0)
                  WHEN NVL(GOAL_YEAR,0) < NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0)
                            ELSE NVL(GOAL_YEAR,0) END
                  AS MAX_VAL_MON
            ,CASE WHEN NVL(GOAL_WEEK,0) > NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(GOAL_WEEK,0)
                  WHEN NVL(GOAL_WEEK,0) < NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0)
                            ELSE NVL(GOAL_WEEK,0) END
                  AS MAX_VAL_WEEK         
  FROM (
        -- 두께가공 생산 실적
        -- Brazing 전 연삭 Move량 + 1차 두께 연삭 Move량 + 외경 황삭 Move량 + 외경 정삭 Move량 + 최종 두께 연삭 Move량
        SELECT SUM(PROD_QTY) PROD_QTY,
               SUM(CASE WHEN A.WEEK_OF_YEAR = B.PLAN_WEEK THEN A.PROD_QTY END) PROD_QTY_W
          FROM CSUMWIPOPR A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('OP08010', 'OP08030', 'OP08040', 'OP08060', 'OP08080')
       ) A,
       (
        --  투입 공수
        SELECT SUM(A.TOTAL_WORK_TIME) TOTAL_WORK_TIME,
               SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN A.TOTAL_WORK_TIME END) TOTAL_WORK_TIME_W
          FROM CWIPWRKINP A, MWIPCALDEF B, CAL C
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('PP006')  -- 외경/두께가공
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND A.FACTORY = B.CALENDAR_ID
		   AND A.WORK_DATE = B.SYS_DATE
       ) B,
       (
        --  목표 생산성
        SELECT MAX(CASE WHEN A.CLASS = 'MONTH' AND A.WEEK_OF_MONTH = '1' THEN A.GOAL_PRODUCTVITY END) GOAL_YEAR,
               MAX(CASE WHEN A.CLASS = 'WEEK' AND A.WEEK_OF_MONTH = B.WEEK_OF_MONTH THEN A.GOAL_PRODUCTVITY END) GOAL_WEEK
          FROM CWIPPRDGOL A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.SHOP = 'PL003'      -- 가공
           AND A.OPER_GRP = 'PP006'  -- Lapping
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) C
;

-- 생산성
-- 챔퍼가공
WITH CAL AS (
			SELECT PLAN_WEEK, CAL_CMF_1  WEEK_OF_MONTH
			  FROM MWIPCALDEF
			 WHERE CALENDAR_ID = 'IJDK1'
			   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
)
SELECT ROUND(NVL(GOAL_YEAR,0),2) GOAL_M,                                                                                                                                                        -- 월계획
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) MONTH_PROD_RESULT,                                                                        -- 월실적
       NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2) / GOAL_YEAR,0) MONTH_PROD_RATE,                                                      -- 월달성률
       ROUND(NVL(GOAL_WEEK,0),2) GOAL_W,                                                                                                                                                                  -- 주계획
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) WEEK_PROD_RESULT,                                                      -- 주실적
       NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2) / GOAL_WEEK,0)  WEEK_PROD_RATE                                             -- 주달성률
            ,CASE WHEN NVL(GOAL_YEAR,0) > NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(GOAL_YEAR,0)
                  WHEN NVL(GOAL_YEAR,0) < NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY / B.TOTAL_WORK_TIME * 100, 2),0)
                            ELSE NVL(GOAL_YEAR,0) END
                  AS MAX_VAL_MON
            ,CASE WHEN NVL(GOAL_WEEK,0) > NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(GOAL_WEEK,0)
                  WHEN NVL(GOAL_WEEK,0) < NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0) THEN NVL(ROUND(A.PROD_QTY_W / B.TOTAL_WORK_TIME_W * 100, 2),0)
                            ELSE NVL(GOAL_WEEK,0) END
                  AS MAX_VAL_WEEK         
  FROM (
        -- 챔퍼가공
        -- 1차 Dia 챔퍼 Move량 + 최종 다이아 챔퍼 Move량 + 초경 챔퍼 Move량
        SELECT SUM(PROD_QTY) PROD_QTY,
               SUM(CASE WHEN A.WEEK_OF_YEAR = B.PLAN_WEEK THEN A.PROD_QTY END) PROD_QTY_W
          FROM CSUMWIPOPR A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('OP08050', 'OP08070', 'OP08090')
       ) A,
       (
        --  투입 공수
        SELECT SUM(A.TOTAL_WORK_TIME) TOTAL_WORK_TIME,
               SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN A.TOTAL_WORK_TIME END) TOTAL_WORK_TIME_W
          FROM CWIPWRKINP A, MWIPCALDEF B, CAL C
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.OPER IN ('PP009')  -- Chamfering
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
		   AND A.FACTORY = B.CALENDAR_ID
		   AND A.WORK_DATE = B.SYS_DATE
       ) B,
       (
        --  목표 생산성
        SELECT MAX(CASE WHEN A.CLASS = 'MONTH' AND A.WEEK_OF_MONTH = '1' THEN A.GOAL_PRODUCTVITY END) GOAL_YEAR,
               MAX(CASE WHEN A.CLASS = 'WEEK' AND A.WEEK_OF_MONTH = B.WEEK_OF_MONTH THEN A.GOAL_PRODUCTVITY END) GOAL_WEEK
          FROM CWIPPRDGOL A, CAL B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
           AND A.SHOP = 'PL003'      -- 가공
           AND A.OPER_GRP = 'PP009'  -- Chamfering
           AND A.WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) C
;
