@echo off
setlocal enabledelayedexpansion

rem Compile the C++ files into executables
g++ gen.cpp -o gen
g++ stupid.cpp -o stupid
g++ smart.cpp -o smart

rem Infinite loop for testing
set /a testCounter=1
:loop
    rem Generate input file using gen.exe
    gen !testCounter! > testcase
    
    rem Get output from stupid.exe and smart.exe
    stupid < testcase > stupidOutput
    smart < testcase > smartOutput
    
    rem Compare outputs
    fc /b stupidOutput smartOutput > nul || goto end
    
    rem Log the result of the test case
    echo Passed test: !testCounter!
    type testcase
    echo:
    
    rem Increment the test counter
    set /a testCounter+=1
    goto loop

:end
echo WA on the following test:
type testcase
echo:
echo Your answer is:
type stupidOutput
echo Correct answer is:
type smartOutput
