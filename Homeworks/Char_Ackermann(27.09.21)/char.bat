@echo off

for /l %%i in (33,1,255) do (
	call :tab %%i
)

:tab
setlocal
cmd /c exit %1
echo %1 %=exitcodeAscii%
exit /b
