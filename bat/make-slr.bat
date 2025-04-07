@echo off
setlocal enabledelayedexpansion
echo Opening generator.exe

set pro2=generator.exe
if NOT exist %pro2% (
    echo No generator.exe
    pause >nul
    exit /b
)

echo Opening std.exe

set pro1=std.exe
if NOT exist %pro1% (
    echo No std.exe
    pause >nul
    exit /b
)

set /p s=Subtask: 
set /p left=Left: 
set /p right=Right:

if not exist data mkdir data

for /L %%i in (%left%,1,%right%) do (
    echo Making data: %s%-%%i.in
    %pro2% >data\%s%-%%i.in
    echo Making data: %s%-%%i.out
    %pro1% <data\%s%-%%i.in >data\%s%-%%i.out
)

set "newname=generator(subtask %s%,%left%-%right%).cpp"
set "prename=generator.cpp"

echo Saving !prename! to !newname!

if exist !prename! (
    (
        echo // Subtask: %s%
        type !prename!
    ) > data\!newname!
    echo Copied !prename! to data\!newname!
) else (
    echo !prename! does not exist!
)

echo Finish

pause >nul