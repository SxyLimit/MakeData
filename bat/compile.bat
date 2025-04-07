@echo off
echo Compiling std.cpp
g++ std.cpp -o std -std=c++14 -O2 >nul 2>&1
if errorlevel 1 (
    echo Failed to compile std.cpp
    pause >nul
    exit /b
)

echo Compiling generator.cpp
g++ generator.cpp -o generator -std=c++14 -O2 >nul 2>&1
if errorlevel 1 (
    echo Failed to compile generator.cpp
    pause >nul
    exit /b
)
echo Compilation successful
pause >nul