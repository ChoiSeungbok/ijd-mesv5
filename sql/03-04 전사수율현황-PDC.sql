SELECT NVL(C.YIELD,0) YIELD,                                    -- 수율 월 실적
       NVL(D.GOAL_YIELD,0) GOAL_YIELD,                              -- 수율 월 계획
       NVL(ROUND(C.YIELD / D.GOAL_YIELD * 100, 1),0) YIED_RATE, -- 수율 월 달성율
       NVL(C.YIELD_W,0) YIELD_W                                  -- 수율 실적 주간   
  FROM (
        SELECT WORK_MONTH, 
               ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD,
               ROUND(EXP(SUM(LN(MAT_YIELD_W))) * 100, 1) YIELD_W
          FROM (
                SELECT WORK_MONTH, 
                       DECODE(PROD_IN_QTY, 0, 1, NVL(PROD_OUT_QTY / PROD_IN_QTY, 1)) MAT_YIELD,
                       DECODE(PROD_IN_W_QTY, 0, 1, NVL(PROD_OUT_W_QTY / PROD_IN_W_QTY, 1))  MAT_YIELD_W
                  FROM (
                        SELECT SUBSTR(A.WORK_DATE,0,6) AS WORK_MONTH, MAT_CLASS,
                            SUM(PROD_QTY) AS PROD_OUT_QTY,
                            SUM(PROD_IN_QTY) AS PROD_IN_QTY,
                            SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN PROD_QTY END) PROD_OUT_W_QTY,                            
                            SUM(CASE WHEN C.PLAN_WEEK = B.PLAN_WEEK THEN PROD_IN_QTY END) PROD_IN_W_QTY
                          FROM CSUMWIPOPR A, MWIPCALDEF B,
                               (
                                SELECT PLAN_WEEK
                                  FROM MWIPCALDEF
                                 WHERE CALENDAR_ID = 'IJDK1'
                                   AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                               ) C
                         WHERE A.FACTORY = 'IJDK1'
                           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                           AND A.AREA_ID = 'PDC'                                              
                           AND A.OPER IN ('OP08120','OP90040')
                           AND A.FACTORY = B.CALENDAR_ID
                           AND A.WORK_DATE = B.SYS_DATE
                         GROUP BY SUBSTR(A.WORK_DATE,0,6), A.MAT_CLASS
                       )
               )
               GROUP BY WORK_MONTH
       ) C,
       (
        -- 수율 계획
        SELECT WORK_MONTH, GOAL_YIELD
          FROM CWIPPRDGOL
         WHERE FACTORY = 'IJDK1'
           AND KIND = 'Y'
            AND CLASS='MONTH'
           AND WEEK_OF_MONTH = 1
           AND AREA_ID = 'PDC'
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) D
 WHERE C.WORK_MONTH=D.WORK_MONTH(+)
;

-- 일간 수율
SELECT TO_CHAR(TO_DATE(A.WORK_DATE,'YYYYMMDD'),'MM-DD') AS WORK_DATE
          , NVL(B.YIELD,0) T_YIELD
  FROM (
        SELECT /*+ INDEX_DESC(A MWIPCALDEF_PK) */ SYS_DATE WORK_DATE
          FROM MWIPCALDEF A
         WHERE CALENDAR_ID = 'IJDK1'
           AND SYS_YEAR = TO_NUMBER(SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 4))
           AND HOLIDAY_FLAG = ' '
           AND SYS_DATE <= F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
        FETCH FIRST 9 ROW ONLY
       ) A,
       (
        SELECT WORK_DATE, ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
          FROM (              
                SELECT WORK_DATE, DECODE(PROD_IN_QTY, 0, 1, NVL(PROD_OUT_QTY / PROD_IN_QTY, 1)) MAT_YIELD
                FROM (
                    SELECT WORK_DATE,
                        SUM(PROD_QTY) AS PROD_OUT_QTY,
                        SUM(PROD_IN_QTY) AS PROD_IN_QTY
                      FROM CSUMWIPOPR
                     WHERE FACTORY = 'IJDK1'
                       AND WORK_DATE BETWEEN TO_CHAR(TO_DATE(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 'YYYYMMDD') - 15, 'YYYYMMDD') AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                       AND AREA_ID = 'PDC'                                                       
                       AND OPER IN ('OP08120','OP90040')
                     GROUP BY WORK_DATE 
                   )                 
          )      
         GROUP BY WORK_DATE
       ) B
 WHERE A.WORK_DATE = B.WORK_DATE(+)
 ORDER BY A.WORK_DATE
 ;


-- 월간 Worst Loss
SELECT B.WORK_DATE, B.LOSS_CODE, B.LOSS_DESC, B.SEQ, ROUND(B.LOSS_QTY / A.PROD_QTY * 100, 1) LOSS_RATE
  FROM (
        -- 월간 작업량
        SELECT SUM(A.PROD_QTY + A.LOSS_QTY) PROD_QTY
          FROM CSUMWIPOPR A
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'PDC'            
       ) A,
       (
        SELECT A.WORK_DATE, A.LOSS_CODE, B.DATA_1 LOSS_DESC, B.DATA_2 SEQ, SUM(A.LOSS_QTY) LOSS_QTY
          FROM CSUMWIPLOS A, MGCMTBLDAT B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'PDC'
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
   AND A.AREA_ID(+) = 'PDC'
   AND A.FACTORY(+) = B.FACTORY
   AND A.AREA_ID(+) = B.KEY_1
   AND A.LOSS_CODE(+) = B.KEY_2
   AND B.TABLE_NAME = 'C_WORST_LOSS'
 GROUP BY ROLLUP(C.WORK_DATE, B.KEY_2, B.DATA_1, B.DATA_2)
 HAVING GROUPING_ID(C.WORK_DATE, B.KEY_2, B.DATA_1, B.DATA_2) IN (0, 7)
 ;