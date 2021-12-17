@echo off

set k=0

:ak

if %1==0 goto m_0
if %2==0 goto n_0
:else
set /a n=%2-1
set /a k+=1

call :ak %1 %n%
set n0=%errorlevel%

set /a m=%1-1
call :ak %m% %n0%
set res=%errorlevel%

set /a k-=1
if %k%==0 (
	echo %res%
	goto :end
) else (
	exit /b %res%
)	
 
:m_0

set /a res=%2+1

if %k%==0 (
	echo %res%
	goto :end
) else (
	exit /b %res%
)	

:n_0

set /a m=%1-1
set /a k+=1
call :ak %m% 1
set res=%errorlevel%
set /a k-=1

if %k%==0 (
	echo %res%
	goto :end
) else (
	exit /b %res%
)

:end
exit /b