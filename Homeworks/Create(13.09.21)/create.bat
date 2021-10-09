@echo off
chcp 65001 >nul

if not "%~1"=="" goto var
set name=%~dp0\semester1
goto begin
:var
set name=%1
:begin

md %name% 

md %name%\"Алгебра и геометрия"
echo Ведякова Анастасия Олеговна > %name%\"Алгебра и геометрия"\readme.txt
echo Начало занятий: %date% >> %name%\"Алгебра и геометрия"\readme.txt

md %name%\"Матанализ"
echo Евстафьева Виктория Викторовна > %name%\"Матанализ"\readme.txt
echo Начало занятий: %date% >> %name%\"Матанализ"\readme.txt

md %name%\"Основы программирования"
echo Погожев Сергей Владимирович > %name%\"Основы программирования"\readme.txt
echo Начало занятий: %date% >> %name%\"Основы программирования"\readme.txt

md %name%\"Дискретная математика"
echo Максимов Алексей Юрьевич > %name%\"Дискретная математика"\readme.txt
echo Начало занятий: %date% >> %name%\"Дискретная математика"\readme.txt

echo @echo off > %name%\algem.bat
echo chcp 65001 >nul >> %name%\algem.bat
echo copy con "Алгебра и геометрия"\%date%.log >> %name%\algem.bat

echo @echo off > %name%\op.bat
echo chcp 65001 >nul >> %name%\op.bat
echo copy con "Основы программирования"\%date%.log >> %name%\op.bat