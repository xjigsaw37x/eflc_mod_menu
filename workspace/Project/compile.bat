@echo off
if not exist *.c goto nofile
if exist *.sco (
echo Cleaning prior scripts ...
del -f *.sco
)
if exist *.s (
echo Cleaning prior scripts ...
del -f *.s
)
if not defined %%1 goto compile_menu
goto compile_custom

:compile_menu
echo.
echo Compiling menu.sco ...
echo.
..\..\bin\scocl_old.exe GTAIV "menu.c" "..\Project/"
if not exist *.sco goto err_build
pause
exit 1

:compile_custom
echo.
if %%1 NEQ *.c goto err_custom
echo Compiling %%1 ...
..\..\bin\scocl_old.exe GTAIV "%%1" "..\Project/"
if not exist *.sco goto err_build
pause
exit 1

:err_custom
cls
echo Your custom script is not a .c file, please try again
pause 
exit 1

:err_build
echo.
echo.
echo ERROR ABOVE
echo Your custom script did not build
pause 
exit 1

:nofile
cls
echo No .c Files found in local directory
pause 
exit 1