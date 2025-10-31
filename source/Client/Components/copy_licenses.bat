REM %1 : Solution Path
REM %2 : Project Path
REM %3 : Configuration Name

IF NOT %3 == Release_QI (
GOTO EOF
)

echo xcopy "%1..\Components\licenses.licx" "%2Properties" /r/y
xcopy "%1..\Components\licenses.licx" "%2Properties" /r/y

:EOF
