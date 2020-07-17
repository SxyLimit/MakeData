@echo off
set pro2=makedata.exe
if NOT exist %pro2% (
 echo No makedata.exe
 pause>nul
 %0
 cls
)
cls
set pro1=std.exe
if NOT exist %pro1% (
 echo No std.exe
 pause>nul
 %0
)
cls
set /p left=l:
set /p right=r:
cls
for /L %%i in (%left%,1,%right%) do (
 echo Making data:%%i.in
 %pro2% >.\%%i.in
 cls
 echo Making data:%%i.out
 %pro1% <.\%%i.in >.\%%i.out
 cls
)
echo Finish
pause>nul
