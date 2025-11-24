const { execSync, spawnSync } = require("child_process");
const fs = require("fs");
const path = require("path");

const exe = ".exe";

const compile = (source, output) => {
    const sourcePath = path.join(__dirname, source);
    const outputPath = path.join(__dirname, output + exe);

    try {
        execSync(`g++ -std=c++23 -O2 "${sourcePath}" -o "${outputPath}"`, { stdio: "inherit" });
    } catch (error) {
        console.error(`Compilation failed for ${source}.`);
        process.exit(1);
    }
};

const runCommand = (command, input) => {
    const commandPath = path.join(__dirname, command + exe);
    const result = spawnSync(commandPath, { input, encoding: "utf-8" });

    if (result.error) {
        console.error(`Error running ${command}. Ensure the executable exists.`);
        process.exit(1);
    }
    return result.stdout.trim();
};

const main = () => {
    compile("gen.cpp", "gen");
    compile("stupid.cpp", "stupid");
    compile("checker.cpp", "checker");

    let testCounter = 1;

    while (true) {
        const testCase = runCommand("gen", testCounter.toString());
        const stupidOutput = runCommand("stupid", testCase);

        // Run checker
        const checkerResult = spawnSync(path.join(__dirname, "checker" + exe), {
            input: `${testCase}\n${stupidOutput}`,
            encoding: "utf-8",
        });

        if (checkerResult.status !== 0) {
            console.log(`Test failed on case ${testCounter}`);
            console.log("\nTest Case:");
            console.log(testCase);
            console.log("\nYour Answer (stupid):");
            console.log(stupidOutput);
            console.log("\nChecker Output:");
            console.log(checkerResult.stdout.trim());
            process.exit(1);
        }

        console.log(`Passed test: ${testCounter}`);
        console.log(testCase);
        testCounter++;
    }
};

main();
