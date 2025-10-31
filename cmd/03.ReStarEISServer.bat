cd c:\MESplusV5\cmd

start ..\bin\MESStopProc.exe "EISServer" "/STOP/MPT1/EISServer" "localhost:10101" "01"

timeout  3

start ..\bin\EISServer.exe 01

timeout  3

start ..\bin\MESStopProc.exe "EISServer" "/STOP/MPT1/EISServer" "localhost:10101" "02"
start ..\bin\MESStopProc.exe "EISServer" "/STOP/MPT1/EISServer" "localhost:10101" "03"

timeout  3

start ..\bin\EISServer.exe 02
start ..\bin\EISServer.exe 03
