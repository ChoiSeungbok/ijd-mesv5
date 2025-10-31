cd c:\MESplusV5\cmd

start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "01"
start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "02"
start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "03"
start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "04"

timeout  3

start ..\bin\MESServer.exe 01
start ..\bin\MESServer.exe 02
start ..\bin\MESServer.exe 03
start ..\bin\MESServer.exe 04

timeout  3

start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "05"
start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "06"
start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "07"
start ..\bin\MESStopProc.exe "MESServer" "/STOP/MPT1/MESServer" "localhost:10101" "08"

timeout  3

start ..\bin\MESServer.exe 05
start ..\bin\MESServer.exe 06
start ..\bin\MESServer.exe 07
start ..\bin\MESServer.exe 08
