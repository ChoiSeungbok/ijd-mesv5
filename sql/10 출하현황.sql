-- 출하현황
-- 출하현황
SELECT AREA_ID,                                       -- 사업부
       QTY,                                           -- 전사 출하지시 수량
       WAIT,                                          -- 전사 출하대기 수량
       SHIP,                                          -- 전사 출하 수량
       (CASE WHEN QTY>0 THEN ROUND(SHIP / QTY * 100, 1) ELSE 0 END) RATE,                  -- 전사 출하률
       DOM_QTY,                                       -- 전략 출하지시 수량
       DOM_WAIT_QTY                                   -- 전략 출하대기 수량
       DOM_SHIP_QTY,                                  -- 전략 출하 수량
       (CASE WHEN DOM_QTY>0 THEN ROUND(DOM_SHIP_QTY / DOM_QTY * 100,1) ELSE 0 END) DOM_RATE,  -- 전략 출하률
       CHN_QTY,                                       -- 중국 출하지시 수량
       CHN_WAIT_QTY,                                  -- 중국 출하대기 수량
       CHN_SHIP_QTY,                                  -- 중국 출하 수량
       (CASE WHEN CHN_QTY>0 THEN ROUND(CHN_SHIP_QTY / CHN_QTY * 100,1) ELSE 0 END) CHN_RATE,  -- 중국 출하률
       JPN_QTY,                                       -- 일본 출하지시 수량
       JPN_WAIT_QTY,                                  -- 일본 출하대기 수량
       JPN_SHIP_QTY,                                  -- 일본 출하 수량
       (CASE WHEN JPN_QTY>0 THEN ROUND(JPN_SHIP_QTY / JPN_QTY * 100,1) ELSE 0 END) JPN_RATE,  -- 일본 출하률
       EUR_QTY,                                       -- 유럽 출하지시 수량
       EUR_WAIT_QTY,                                  -- 유럽 출하대기 수량
       EUR_SHIP_QTY,                                  -- 유럽 출하 수량
       (CASE WHEN EUR_QTY>0 THEN ROUND(EUR_SHIP_QTY / EUR_QTY * 100,1) ELSE 0 END) EUR_RATE,  -- 유럽 출하률
       USA_QTY,                                       -- 미국 출하지시 수량
       USA_WAIT_QTY,                                  -- 미국 출하대기 수량
       USA_SHIP_QTY,                                  -- 미국 출하 수량
       (CASE WHEN USA_QTY>0 THEN ROUND(USA_SHIP_QTY / USA_QTY * 100,1) ELSE 0 END) USA_RATE   -- 미국 출하률
  FROM (
        SELECT AREA_ID,
               SUM(QTY) QTY,                                            -- 전사 출하지시 수량
               SUM(WAIT) WAIT,                                          -- 전사 출하대기 수량
               SUM(SHIP) SHIP,                                          -- 전사 출하 수량
               SUM(CASE WHEN LOC_TYPE NOT IN ('CHN', 'JPN', 'EUR', 'USA') THEN
                 QTY
               ELSE
                  0
               END)  DOM_QTY,                                  -- 전략 출하지시 수량
               SUM(CASE WHEN LOC_TYPE NOT IN ('CHN', 'JPN', 'EUR', 'USA') THEN
                 WAIT
               ELSE
                  0
               END)  DOM_WAIT_QTY,                             -- 전략 출하대기 수량
               SUM(CASE WHEN LOC_TYPE NOT IN ('CHN', 'JPN', 'EUR', 'USA') THEN
                 SHIP
               ELSE
                  0
               END)    DOM_SHIP_QTY,                           -- 국내 출하 수량
               SUM(DECODE(LOC_TYPE, 'CHN', QTY, 0) ) CHN_QTY,      -- 중국 출하지시 수량
               SUM(DECODE(LOC_TYPE, 'CHN', WAIT, 0)) CHN_WAIT_QTY, -- 중국 출하대기 수량
               SUM(DECODE(LOC_TYPE, 'CHN', SHIP, 0)) CHN_SHIP_QTY, -- 중국 출하 수량
               SUM(DECODE(LOC_TYPE, 'JPN', QTY, 0) ) JPN_QTY,      -- 일본 출하지시 수량
               SUM(DECODE(LOC_TYPE, 'JPN', WAIT, 0)) JPN_WAIT_QTY, -- 일본 출하대기 수량
               SUM(DECODE(LOC_TYPE, 'JPN', SHIP, 0)) JPN_SHIP_QTY, -- 일본 출하 수량
               SUM(DECODE(LOC_TYPE, 'EUR', QTY, 0) ) EUR_QTY,      -- 유럽 출하지시 수량
               SUM(DECODE(LOC_TYPE, 'EUR', WAIT, 0)) EUR_WAIT_QTY, -- 유럽 출하대기 수량
               SUM(DECODE(LOC_TYPE, 'EUR', SHIP, 0)) EUR_SHIP_QTY, -- 유럽 출하 수량
               SUM(DECODE(LOC_TYPE, 'USA', QTY, 0) ) USA_QTY,      -- 미국 출하지시 수량
               SUM(DECODE(LOC_TYPE, 'USA', WAIT, 0)) USA_WAIT_QTY, -- 미국 출하대기 수량
               SUM(DECODE(LOC_TYPE, 'USA', SHIP, 0)) USA_SHIP_QTY  -- 미국 출하 수량
          FROM (
                SELECT A.AREA_ID,
                       C.DATA_3 LOC_TYPE,
                       SUM(B.QTY) QTY,
                       SUM(TO_NUMBER(CASE WHEN B.SHIP_ORD_STATUS = 'WAIT' THEN TO_CHAR(B.QTY) ELSE '0' END)) WAIT,
                       SUM(TO_NUMBER(CASE WHEN B.SHIP_ORD_STATUS = 'SHIPPED' THEN TO_CHAR(B.QTY) ELSE '0' END)) SHIP
                  FROM CSHPORDMST A, CSHPORDDTL B, MGCMTBLDAT C
                 WHERE A.FACTORY = B.FACTORY
                   AND A.SHIP_ORDER_ID = B.SHIP_ORDER_ID
                   --AND A.SHIP_ORD_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
                   AND A.SHIP_ORD_DATE BETWEEN TO_CHAR(SYSDATE, 'YYYYMMDD')|| '000000' AND  TO_CHAR(SYSDATE, 'YYYYMMDD')|| '235959'
                   AND A.FACTORY = C.FACTORY
                   AND A.CUSTOMER_ID = C.KEY_1
                   AND C.TABLE_NAME = 'C_CUSTOMER'
                 GROUP BY A.AREA_ID, C.DATA_3
               )
         GROUP BY AREA_ID
       )
;

-- 오늘 출하 대상
SELECT A.SHIP_ORDER_ID, C.MAT_DESC, B.QTY, A.SHIP_ORD_DATE
  FROM CSHPORDMST A, CSHPORDDTL B, MWIPMATDEF C
 WHERE A.FACTORY = 'IJDK1'
   AND B.SHIP_ORD_STATUS = 'WAIT'
   --AND A.SHIP_ORD_DATE = F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS'))
   AND A.SHIP_ORD_DATE BETWEEN TO_CHAR(SYSDATE, 'YYYYMMDD') || '000000' AND  TO_CHAR(SYSDATE, 'YYYYMMDD') || '235959'
   AND A.FACTORY = B.FACTORY
   AND A.SHIP_ORDER_ID = B.SHIP_ORDER_ID
   AND B.FACTORY = C.FACTORY
   AND B.MAT_ID = C.MAT_ID
   AND B.MAT_VER = C.MAT_VER
  ORDER BY B.QTY
 FETCH FIRST 3 ROWS ONLY;

 -- 내일 출하 대상
SELECT A.SHIP_ORDER_ID, C.MAT_DESC, B.QTY, A.SHIP_ORD_DATE
  FROM CSHPORDMST A, CSHPORDDTL B, MWIPMATDEF C
 WHERE A.FACTORY = 'IJDK1'
   AND B.SHIP_ORD_STATUS = 'WAIT'
   --AND A.SHIP_ORD_DATE = TO_CHAR(TO_DATE(F_GET_WORK_DATE(TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS')), 'YYYYMMDD') + 1, 'YYYYMMDD')
    AND A.SHIP_ORD_DATE BETWEEN TO_CHAR(SYSDATE+1, 'YYYYMMDD') || '000000' AND  TO_CHAR(SYSDATE+1, 'YYYYMMDD') || '235959'
   AND A.FACTORY = B.FACTORY
   AND A.SHIP_ORDER_ID = B.SHIP_ORDER_ID
   AND B.FACTORY = C.FACTORY
   AND B.MAT_ID = C.MAT_ID
   AND B.MAT_VER = C.MAT_VER
  ORDER BY B.QTY
 FETCH FIRST 3 ROWS ONLY;

