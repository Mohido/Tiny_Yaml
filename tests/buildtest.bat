
REM Build test scripts. The first parameter is the file for the build.
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Test filename


ECHO "Building %assembly%%..."
clang++ ./%1 -g -Wno-return-type -Wno-pragma-once-outside-header -o out/test.exe -target x86_64-pc-windows-msvc
@REM cl.exe ../yaml/yaml.cpp ./test1.cpp /EHsc /MD /Feout\test.exe /I../yaml/


