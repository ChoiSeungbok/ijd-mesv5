/*LINE 현황 (GRIT)*/

--전체 설비 현황
SELECT  RES_TOT_CNT, --총수량
        STOP_CNT,    --정지
        WAIT_CNT,    --대기
        RUN_CNT,     --가동
       (CASE WHEN RES_TOT_CNT>0 THEN ROUND(STOP_CNT / RES_TOT_CNT *100,1) END)AS RUN_RATE  --가동율
FROM (
    SELECT  COUNT(RES_ID) AS RES_TOT_CNT,
            SUM(CASE WHEN RES_PRI_STS='D' THEN 1 ELSE 0 END) AS STOP_CNT ,   --정지
            SUM(CASE WHEN RES_PRI_STS IN ('I','WAIT') THEN 1 ELSE 0 END) AS WAIT_CNT ,   --대기
            SUM(CASE WHEN RES_PRI_STS='R' THEN 1 ELSE 0 END) AS RUN_CNT     --가동
    FROM MRASRESDEF RES,
         MGCMTBLDAT GRP       
    WHERE RES.FACTORY=GRP.FACTORY
         AND TABLE_NAME='RES_GRP_3' 
         AND RES.RES_GRP_3=GRP.KEY_1
         AND RES.FACTORY='IJDK1'
         AND RES.AREA_ID='GRT'      --AREA:GRT,CTM
)
;
--그룹별 설비 가동 현황 리스트
SELECT RES.RES_GRP_3, GRP.DATA_1 AS RES_GRP_3_DESC, RES_ID, RES_DESC, DECODE(RES_PRI_STS,'WAIT','I',RES_PRI_STS) AS RES_PRI_STS
FROM MRASRESDEF RES,
     MGCMTBLDAT GRP       
WHERE RES.FACTORY=GRP.FACTORY
     AND TABLE_NAME='RES_GRP_3' 
     AND RES.RES_GRP_3=GRP.KEY_1
     AND RES.FACTORY='IJDK1'
     AND RES.AREA_ID='GRT'      --AREA:GRT,CTM
     --AND RES.RES_GRP_3 ='G017'  --그룹 : 진공로 
ORDER BY RES_GRP_3, RES_DESC 
  
  
/*
G017    진공로
G006    L Press(5000T)

G016    전기분해
G015    열처리로  --제외
        
G011    Sputter
G018    진공열처리로
G003    CVD Coating
        
G021    형상분류기(9cup)
G020    형상분류기(15cup)

G012    Wheel 자성분류기

G013    도금장비
*/

