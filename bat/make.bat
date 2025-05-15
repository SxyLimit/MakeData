@echo off
setlocal enabledelayedexpansion
echo Opening generator.exe

set pro2=generator.exe
if NOT exist %pro2% (
    echo No generator.exe
    exit /b
)

echo Opening std.exe

set pro1=std.exe
if NOT exist %pro1% (
    echo No std.exe
    exit /b
)

if not exist data mkdir data

set /p left=Left: 
set /p right=Right: 

for /L %%i in (%left%, 1, %right%) do (
    echo Making data: %%i.in
    %pro2% %%i>data\%%i.in
    echo Making data: %%i.out
    %pro1% <data\%%i.in >data\%%i.out
)

set "newname=generator(%left%-%right%).cpp"
set "prename=generator.cpp"

echo Saving !prename! to !newname!

if exist !prename! (
    copy /Y !prename! data\!newname!>nul
    echo Copied !prename! to data\!newname!
) else (
    echo !prename! does not exist!
)

echo Finish
