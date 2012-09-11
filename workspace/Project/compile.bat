@echo off
if not exist *.c goto nofile
if not exist ../../out_sco (
cd ../../
mkdir out_sco
cd workspace/Project/
)
if exist ../../out_sco/*.sco (
echo Cleaning prior scripts ...
cd ../../out_sco/
del -f *.sco
cd ../workspace/Project/
)
if exist ../../out_sco/*.s (
echo Cleaning prior failed scripts ...
cd ../../out_sco/
del -f *.s
cd ../workspace/Project/
)
if not defined %%1 goto compile_menu
goto compile_custom

:compile_menu
echo.
echo Compiling menu.sco ...
echo.
..\..\bin\scocl_old.exe TBOGT "menu.c" "..\..\out_sco/"
if not exist ../../out_sco/*.sco goto err_build
set "outsco=../../out_sco/*.sco"
echo.
cd ../../out_sco/
ren "menu.sco" "xmc_modmenu.sco"
cd ../workspace/Project/
for %%A in (%outsco%) do echo.Size of "%%A" is %%~zA bytes
pause
exit 1

:compile_custom
echo.
if %%1 NEQ *.c goto err_custom
echo Compiling %%1 ...
..\..\bin\scocl_old.exe TBOGT "%%1" "..\..\out_sco/" -fnested-functions
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