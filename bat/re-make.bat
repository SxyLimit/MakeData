@echo off

set pro1=std.exe
if NOT exist %pro1% (
    echo No std.exe
    pause>nul
    "%~0"
)

set /p left=Left:
set /p right=Right:

for /L %%i in (%left%,1,%right%) do (
    echo Making data:%%i.out
    %pro1% <.\%%i.in >.\%%i.out
)

echo Finish
pause>nul