@echo off

call :ak %1 %2 a 
echo %a%

:ak
if "%1"=="0" (set /a %3=%2 + 1)
if %1 gtr 0 (
	if "%2"=="0" (
		set /a m1=%1 - 1
		call :ak %m1% 1 a1
		set /a %3=%a1%
	)
	if %2 gtr 0 (
		set /a m1=%1 - 1
		set /a n1=%2 - 1
		call :ak %1 %n1% a1
		call :ak %m1% %a1% a2
		set /a %3=%a2%
	)
)
exit /b