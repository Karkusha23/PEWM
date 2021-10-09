@echo off

set /a a=1
:loop
set /a b=(%a%*%a%)%%1000000
if "%b%"=="269696" (goto :exit)
set /a a=%a%+1
goto :loop
:exit
echo %a%
