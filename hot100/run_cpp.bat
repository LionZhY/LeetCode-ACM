@echo off
REM 检查是否传入cpp文件参数
if "%~1"=="" (
    echo Please provide a .cpp file as argument.
    pause
    exit /b
)

REM 获取文件完整路径与文件名（无扩展名）
set "cppfile=%~1"
set "filename=%~n1"

REM 检查文件是否存在
if not exist "%cppfile%" (
    echo Error: file "%cppfile%" not found.
    pause
    exit /b
)


REM 编译文件
echo Compiling %cppfile% ...
g++ "%cppfile%" -o "%filename%.exe"
if %errorlevel% neq 0 (
    echo Compile failed!
    pause
    exit /b
)


REM 运行可执行文件
echo Compile success. Running %filename%.exe ...
echo -------------------------------------
"%filename%.exe"
echo -------------------------------------
pause


REM 只需要执行 ./run_cpp.bat leetcode239.cpp (cpp文件名称)
