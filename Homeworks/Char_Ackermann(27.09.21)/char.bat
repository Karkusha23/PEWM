@echo off
chcp 1251 >nul

for /l %%i in (33,1,126) do (
	call :tab %%i
)

exit /b

:tab
setlocal
cmd /c exit %1
echo %1 "%=exitcodeAscii%"
exit /b
