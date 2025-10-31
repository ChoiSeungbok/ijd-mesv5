SELECT NVL(CEIL(B.TO_PLAN_QTY),0) TO_PLAN_QTY,                                        -- 계획량
       NVL(CEIL(A.MONTH_PROD_QTY),0) MONTH_PROD_QTY,                                        -- 생산량
       NVL(ROUND(A.MONTH_PROD_QTY / B.MONTH_PLAN_QTY * 100, 1),0) MONTH_RATE,    -- 당월 달성률
       NVL(ROUND(A.PRE_PROD_QTY / B.PRE_PLAN_QTY * 100),0) PRE_RATE,            -- 전일 달성률
       NVL(ROUND(A.TOD_PROD_QTY / B.TOD_PLAN_QTY * 100),0) TOD_RATE,            -- 금일 달성률
       NVL(ROUND(C.YIELD,1),0) YIELD,                                                    -- 수율 실적
       NVL(ROUND(D.GOAL_YIELD,1),0) GOAL_YIELD,                                            -- 수율 계획
       NVL(ROUND(C.YIELD*100 / D.GOAL_YIELD, 1),0) YIED_RATE                        -- 수율 달성율
  FROM (
        -- 생산량
        SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
               SUM(PROD_QTY) MONTH_PROD_QTY,
               SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_PRE_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) PRE_PROD_QTY,
               SUM(TO_NUMBER(DECODE(WORK_DATE , F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), TO_CHAR(PROD_QTY), '0'))) TOD_PROD_QTY
          FROM CSUMWIPOPR
         WHERE FACTORY = 'IJDK1'
           AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
           AND AREA_ID = 'CTM'
           AND OPER IN ('OC05060', 'OC05070', 'OC06020')           -- 최종 검사, W/D급검사, 절단품 검사
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
           AND AREA_ID = 'CTM'
           AND OPER IN ('OC05060', 'OC05070', 'OC06020')  
           AND PLAN_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_LAST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
        GROUP BY SUBSTR(PLAN_DATE,0,6)
       ) B,
       (
        -- 수율 실적
         SELECT WORK_MONTH, ROUND(EXP(SUM(LN(MAT_YIELD))) * 100, 1) YIELD
          FROM (
                SELECT WORK_MONTH,
                   DECODE(PRESS_IN_QTY, 0, 1, NVL(PRESS_OUT_QTY / PRESS_IN_QTY, 1)) *
                   DECODE(LP_IN_QTY, 0, 1, NVL(LP_OUT_QTY / LP_IN_QTY, 1)) *
                   DECODE(FINAL_IN_QTY, 0, 1, NVL(FINAL_OUT_QTY / FINAL_IN_QTY, 1)) MAT_YIELD
                FROM (          
                    SELECT SUBSTR(WORK_DATE,0,6) AS WORK_MONTH,
                           -- 프레스 양품수량
                           SUM(CASE WHEN OPER IN ('OC03160') THEN PROD_QTY END) PRESS_OUT_QTY,
                           -- 프레스 투입수량
                           SUM(CASE WHEN OPER IN ('OC03160') THEN PROD_IN_QTY END) PRESS_IN_QTY,
                           -- L/P검사 양품수량
                           SUM(CASE WHEN OPER IN ('OC04120') THEN SUM_QTY_1 END) LP_OUT_QTY,
                           -- L/P검사 투입수량
                           SUM(CASE WHEN OPER IN ('OC04120') THEN (SUM_QTY_1+SUM_QTY_2+SUM_QTY_3+LOSS_QTY) END) LP_IN_QTY,
                           -- 최종검사 양품수량
                           SUM(CASE WHEN OPER IN ('OC05060') THEN SUM_QTY_1 END) FINAL_OUT_QTY,
                           -- 최종검사 투입수량
                           SUM(CASE WHEN OPER IN ('OC05060') THEN (SUM_QTY_1+SUM_QTY_2+SUM_QTY_3+LOSS_QTY) END) FINAL_IN_QTY
                      FROM CSUMWIPOPR
                     WHERE FACTORY = 'IJDK1'
                       AND WORK_DATE BETWEEN F_GET_FIRST_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')) AND F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                       AND AREA_ID = 'CTM'
                       AND OPER IN ('OC03160', 'OC04120', 'OC05060')
                    GROUP BY SUBSTR(WORK_DATE,0,6)
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
           AND AREA_ID = 'CTM'
           AND WORK_MONTH = SUBSTR(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 1, 6)
       ) D
WHERE A.WORK_MONTH=B.WORK_MONTH(+)
    AND A.WORK_MONTH=C.WORK_MONTH(+)
    AND A.WORK_MONTH=D.WORK_MONTH(+)