cd c:\MESplusV5\cmd

start ..\bin\MESStopProc.exe "INFServer" "/STOP/MPT1/INFServer" "localhost:10101" "01"
start ..\bin\MESStopProc.exe "INFServer" "/STOP/MPT1/INFServer" "localhost:10101" "02"
start ..\bin\MESStopProc.exe "INFServer" "/STOP/MPT1/INFServer" "localhost:10101" "03"

timeout  3

start ..\bin\INFServer.exe 01
start ..\bin\INFServer.exe 02
start ..\bin\INFServer.exe 03

timeout  3

start ..\bin\MESStopProc.exe "INFServer" "/STOP/MPT1/INFServer" "localhost:10101" "04"
start ..\bin\MESStopProc.exe "INFServer" "/STOP/MPT1/INFServer" "localhost:10101" "05"
start ..\bin\MESStopProc.exe "INFServer" "/STOP/MPT1/INFServer" "localhost:10101" "06"

timeout  3

start ..\bin\INFServer.exe 04
start ..\bin\INFServer.exe 05
start ..\bin\INFServer.exe 06
