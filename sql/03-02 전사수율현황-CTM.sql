/*CTM 사업부  월간/주간 종합 수율  */
--월간수율
WITH PROD_LIST AS (
        SELECT WORK_MONTH, WORK_WEEK, WORK_DATE,  
               NVL(SUM(PRESS_OUT_QTY),0) AS PRESS_OUT_QTY,
               NVL(SUM(PRESS_IN_QTY),0) AS PRESS_IN_QTY,
               NVL(SUM(LP_OUT_QTY),0) AS LP_OUT_QTY,
               NVL(SUM(LP_IN_QTY),0) AS LP_IN_QTY,
               NVL(SUM(FINAL_OUT_QTY),0) AS FINAL_OUT_QTY,
               NVL(SUM(FINAL_IN_QTY),0) AS FINAL_IN_QTY
            FROM (
                SELECT SUBSTR(A.WORK_DATE,1,6) AS WORK_MONTH,    
                        SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W' AS WORK_WEEK,
                        A.WORK_DATE,                                       
                         -- 프레스 양품수량
                           (CASE WHEN OPER IN ('OC03160') THEN PROD_QTY END) PRESS_OUT_QTY,
                           -- 프레스 투입수량
                           (CASE WHEN OPER IN ('OC03160') THEN PROD_IN_QTY END) PRESS_IN_QTY,
                           -- L/P검사 양품수량
                           (CASE WHEN OPER IN ('OC04120') THEN SUM_QTY_1 END) LP_OUT_QTY,
                           -- L/P검사 투입수량
                           (CASE WHEN OPER IN ('OC04120') THEN (SUM_QTY_1+SUM_QTY_2+SUM_QTY_3+LOSS_QTY) END) LP_IN_QTY,
                           -- 최종검사 양품수량
                           (CASE WHEN OPER IN ('OC05060') THEN SUM_QTY_1 END) FINAL_OUT_QTY,
                           -- 최종검사 투입수량
                           (CASE WHEN OPER IN ('OC05060') THEN (SUM_QTY_1+SUM_QTY_2+SUM_QTY_3+LOSS_QTY) END) FINAL_IN_QTY                     
                FROM CSUMWIPOPR A,  MWIPCALDEF B
                WHERE FACTORY = 'IJDK1'
                    AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                    AND AREA_ID = 'CTM'
                    AND OPER IN ('OC03160', 'OC04120', 'OC05060')                                       
                    AND A.FACTORY = B.CALENDAR_ID
                    AND A.WORK_DATE = B.SYS_DATE
     )
     GROUP BY WORK_MONTH, WORK_WEEK, WORK_DATE 
)

,MONTH_YIELD AS (
    SELECT ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
    FROM (
        SELECT DECODE(PRESS_IN_QTY, 0, 1, NVL(PRESS_OUT_QTY / PRESS_IN_QTY, 1)) *
               DECODE(LP_IN_QTY, 0, 1, NVL(LP_OUT_QTY / LP_IN_QTY, 1)) *
               DECODE(FINAL_IN_QTY, 0, 1, NVL(FINAL_OUT_QTY / FINAL_IN_QTY, 1)) MAT_YIELD
        FROM (   
            SELECT SUM(PRESS_OUT_QTY) AS PRESS_OUT_QTY,
                   SUM(PRESS_IN_QTY) AS PRESS_IN_QTY,
                   SUM(LP_OUT_QTY) AS LP_OUT_QTY,
                   SUM(LP_IN_QTY) AS LP_IN_QTY,
                   SUM(FINAL_OUT_QTY) AS FINAL_OUT_QTY,
                   SUM(FINAL_IN_QTY) AS FINAL_IN_QTY
            FROM PROD_LIST        
            GROUP BY WORK_MONTH
        )    
    )
)
,WEEK_YIELD AS (

    SELECT ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
    FROM (
        SELECT DECODE(PRESS_IN_QTY, 0, 1, NVL(PRESS_OUT_QTY / PRESS_IN_QTY, 1)) *
               DECODE(LP_IN_QTY, 0, 1, NVL(LP_OUT_QTY / LP_IN_QTY, 1)) *
               DECODE(FINAL_IN_QTY, 0, 1, NVL(FINAL_OUT_QTY / FINAL_IN_QTY, 1)) MAT_YIELD
        FROM (   
            SELECT SUM(PRESS_OUT_QTY) AS PRESS_OUT_QTY,
                   SUM(PRESS_IN_QTY) AS PRESS_IN_QTY,
                   SUM(LP_OUT_QTY) AS LP_OUT_QTY,
                   SUM(LP_IN_QTY) AS LP_IN_QTY,
                   SUM(FINAL_OUT_QTY) AS FINAL_OUT_QTY,
                   SUM(FINAL_IN_QTY) AS FINAL_IN_QTY
            FROM PROD_LIST A, MWIPCALDEF B    
            WHERE  B.CALENDAR_ID='IJDK1'
                AND A.WORK_WEEK = (SELECT  SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W'
                      FROM MWIPCALDEF
                     WHERE CALENDAR_ID = 'IJDK1'
                            AND SYS_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')))       
            GROUP BY WORK_WEEK
        )    
    )
)
,TODAY_YIELD AS (
    SELECT ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
    FROM (
        SELECT DECODE(PRESS_IN_QTY, 0, 1, NVL(PRESS_OUT_QTY / PRESS_IN_QTY, 1)) *
               DECODE(LP_IN_QTY, 0, 1, NVL(LP_OUT_QTY / LP_IN_QTY, 1)) *
               DECODE(FINAL_IN_QTY, 0, 1, NVL(FINAL_OUT_QTY / FINAL_IN_QTY, 1)) MAT_YIELD
        FROM (   
            SELECT SUM(PRESS_OUT_QTY) AS PRESS_OUT_QTY,
                   SUM(PRESS_IN_QTY) AS PRESS_IN_QTY,
                   SUM(LP_OUT_QTY) AS LP_OUT_QTY,
                   SUM(LP_IN_QTY) AS LP_IN_QTY,
                   SUM(FINAL_OUT_QTY) AS FINAL_OUT_QTY,
                   SUM(FINAL_IN_QTY) AS FINAL_IN_QTY
            FROM PROD_LIST        
            WHERE WORK_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
            GROUP BY WORK_MONTH
        )    
    ))
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

/*최근 9일 수율 추이(차트)*/
WITH PROD_LIST AS (
         SELECT WORK_MONTH, WORK_WEEK, WORK_DATE,  
               NVL(SUM(PRESS_OUT_QTY),0) AS PRESS_OUT_QTY,
               NVL(SUM(PRESS_IN_QTY),0) AS PRESS_IN_QTY,
               NVL(SUM(LP_OUT_QTY),0) AS LP_OUT_QTY,
               NVL(SUM(LP_IN_QTY),0) AS LP_IN_QTY,
               NVL(SUM(FINAL_OUT_QTY),0) AS FINAL_OUT_QTY,
               NVL(SUM(FINAL_IN_QTY),0) AS FINAL_IN_QTY
            FROM (
                SELECT SUBSTR(A.WORK_DATE,1,6) AS WORK_MONTH,    
                        SYS_YEAR || LPAD(PLAN_WEEK,2,'0') || 'W' AS WORK_WEEK,
                        A.WORK_DATE,                                       
                         -- 프레스 양품수량
                           (CASE WHEN OPER IN ('OC03160') THEN PROD_QTY END) PRESS_OUT_QTY,
                           -- 프레스 투입수량
                           (CASE WHEN OPER IN ('OC03160') THEN PROD_IN_QTY END) PRESS_IN_QTY,
                           -- L/P검사 양품수량
                           (CASE WHEN OPER IN ('OC04120') THEN SUM_QTY_1 END) LP_OUT_QTY,
                           -- L/P검사 투입수량
                           (CASE WHEN OPER IN ('OC04120') THEN (SUM_QTY_1+SUM_QTY_2+SUM_QTY_3+LOSS_QTY) END) LP_IN_QTY,
                           -- 최종검사 양품수량
                           (CASE WHEN OPER IN ('OC05060') THEN SUM_QTY_1 END) FINAL_OUT_QTY,
                           -- 최종검사 투입수량
                           (CASE WHEN OPER IN ('OC05060') THEN (SUM_QTY_1+SUM_QTY_2+SUM_QTY_3+LOSS_QTY) END) FINAL_IN_QTY                     
                FROM CSUMWIPOPR A,  MWIPCALDEF B
                WHERE FACTORY = 'IJDK1'
                    AND WORK_DATE BETWEEN F_GET_WORK_DATE(TO_CHAR(SYSDATE-8, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                    AND AREA_ID = 'CTM'
                    AND OPER IN ('OC03160', 'OC04120', 'OC05060')                                       
                    AND A.FACTORY = B.CALENDAR_ID
                    AND A.WORK_DATE = B.SYS_DATE
     )
     GROUP BY WORK_MONTH, WORK_WEEK, WORK_DATE 
)
, CAL AS (
    SELECT /*+ INDEX_DESC(A MWIPCALDEF_PK) */ SYS_DATE WORK_DATE
          FROM MWIPCALDEF A
         WHERE CALENDAR_ID = 'IJDK1'
           AND SYS_DATE <= F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
        FETCH FIRST 9 ROW ONLY
 )
,DAY_YIELD AS (             
    SELECT A.WORK_DATE,
        NVL(ROUND(((CASE WHEN NVL(PRESS_IN_QTY,0)>0 THEN NVL(PRESS_OUT_QTY,0) / PRESS_IN_QTY END)* 
         (CASE WHEN NVL(LP_IN_QTY,0)>0 THEN NVL(LP_OUT_QTY,0) / LP_IN_QTY END) *
         (CASE WHEN NVL(FINAL_IN_QTY,0)>0 THEN NVL(FINAL_OUT_QTY,0) / FINAL_IN_QTY END)   
        )*100,1),0) YIELD
    FROM CAL A, PROD_LIST B
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


/*월별누적 WORST TOP 3 불량 리스트*/
SELECT B.WORK_DATE, B.LOSS_CODE, B.LOSS_DESC, B.SEQ, ROUND(B.LOSS_QTY / A.PROD_QTY * 100, 1) LOSS_RATE
  FROM (
        -- 월간 작업량
        SELECT SUM(A.PROD_QTY + A.LOSS_QTY) PROD_QTY
          FROM CSUMWIPOPR A
         WHERE A.FACTORY = 'IJDK1'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.AREA_ID = 'CTM'          
       ) A,
       (
        SELECT A.WORK_DATE, A.LOSS_CODE, B.DATA_1 LOSS_DESC, B.DATA_2 SEQ, SUM(A.LOSS_QTY) LOSS_QTY
          FROM CSUMWIPLOS A, MGCMTBLDAT B
         WHERE A.FACTORY = 'IJDK1'
           AND A.AREA_ID = 'CTM'
           AND A.WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND A.FACTORY = B.FACTORY
           AND A.AREA_ID = B.KEY_1
           AND A.LOSS_CODE = B.KEY_2
           AND B.TABLE_NAME = 'C_WORST_LOSS'
         GROUP BY A.WORK_DATE, A.LOSS_CODE, B.DATA_1, B.DATA_2
         ORDER BY A.WORK_DATE, B.DATA_2
       ) B
;
       

/*최근 9일 WORST TOP 3 불량 차트*/
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
   AND A.AREA_ID(+) = 'CTM'
   AND A.FACTORY(+) = B.FACTORY
   AND A.AREA_ID(+) = B.KEY_1
   AND A.LOSS_CODE(+) = B.KEY_2
   AND B.TABLE_NAME = 'C_WORST_LOSS'
 GROUP BY ROLLUP(C.WORK_DATE, B.KEY_2, B.DATA_1, B.DATA_2)
 HAVING GROUPING_ID(C.WORK_DATE, B.KEY_2, B.DATA_1, B.DATA_2) IN (0, 7)