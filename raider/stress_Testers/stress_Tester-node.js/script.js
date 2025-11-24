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
    const result = spawnSync(path.join(__dirname, command + exe), { input, encoding: "utf-8" });
    if (result.error) {
        console.error(`Error running ${command}. Ensure the executable exists.`);
        process.exit(1);
    }
    return result.stdout.trim();
};

const main = () => {
    compile("gen.cpp", "gen");
    compile("stupid.cpp", "stupid");
    compile("smart.cpp", "smart");

    let testCounter = 1;

    while (true) {
        console.log(`Running test ${testCounter}...`);

        const testCase = runCommand("./gen", testCounter.toString());

        const stupidOutput = runCommand("./stupid", testCase);
        const smartOutput = runCommand("./smart", testCase);

        // Compare outputs
        if (stupidOutput !== smartOutput) {
            console.log("WA on the following test:");
            console.log(testCase);
            console.log("\nYour answer is:");
            console.log(stupidOutput);
            console.log("\nCorrect answer is:");
            console.log(smartOutput);
            return;
        }

        console.log(`Passed test: ${testCounter}\n`);
        console.log(testCase);
        testCounter++;
    }
};

main();
