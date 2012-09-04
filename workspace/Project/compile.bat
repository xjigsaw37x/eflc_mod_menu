@echo off
if exist *.sco (
echo Cleaning prior scripts ...
del -f *.sco
)
if not defined %%1 goto compile_menu
goto compile_custom

:compile_menu
echo Compiling menu.sco ...
echo.
..\..\bin\scocl_old.exe GTAIV "menu.c" "..\Project/"
if not exist *.sco goto err_build
pause
exit 1

:compile_custom
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
echo Your custom script did not build
pause 
exit 1