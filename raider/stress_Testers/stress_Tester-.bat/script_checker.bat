@echo off
setlocal enabledelayedexpansion

rem Compile the C++ files into executables
g++ gen.cpp -o gen
g++ stupid.cpp -o stupid
@REM g++ smart.cpp -o smart
g++ checker.cpp -o checker

rem Initialize the test counter
set /a testCounter=1

:loop
    rem Generate input file using gen.exe
    gen !testCounter! > testcase

    rem Run the generated test case through both stupid.exe and smart.exe
    stupid < testcase > stupidOutput
    @REM smart < testcase > smartOutput

    @REM type testcase stupidOutput
    rem Pass testcase, stupidOutput
    checker testcase stupidOutput


    rem Check if checker returned an error
    if %errorlevel% neq 0 (
        echo "Test failed on case: !testCounter!"
        type testcase
        echo "Your answer (stupid):"
        type stupidOutput
        @REM echo "Correct answer (brute):"
        @REM type smartOutput
        echo "Checker output:"
        type checkerOutput
        goto end
    )

    rem Log the result of the test case if no errors
    echo Passed test: !testCounter!
    type testcase

    rem Increment the test counter for the next iteration
    set /a testCounter+=1

    rem Loop back for the next test case
    goto loop

:end
echo "Testing completed."
