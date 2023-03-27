@echo off

:: NOTE: Using :: for comments is problematic inside (...) blocks, so I'll be using rem
:: See https://stackoverflow.com/questions/12407800/which-comment-style-should-i-use-in-batch-files

setlocal
set THISFOLDER=%~dp0
pushd %THISFOLDER%

if not exist "./temp" (
	md temp
	git clone https://github.com/ruifig/czmuc ./temp/czmuc
	cd temp
	cd czmuc
	git reset --hard c05eb36
	cd ..\..
)

if not exist "./build" (
	md build
	cd build
	echo ***Generating Visual Studio project***
	echo on
	cmake -G "Visual Studio 17 2022" -A x64 ..
	echo off
	cd ..
	if %errorlevel% neq 0 goto error
)

:: Everything ok
endlocal
goto end

:: Error
:error
endlocal
echo ERROR!!
exit /b %errorlevel%

:end
popd
pause


