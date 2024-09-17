#!/bin/bash

#should be modified for your computer
TARGET_FILE="/home/gaston/2022ws_team2a/ReversiGame/src/game/placeholder.cpp"
#TARGET_FILE="/home/gaston/2022ws_team2a/ReversiGame/src/game/*"
#TARGET_FILE="/home/gaston/2022ws_team2a/ReversiGame/src/*"

echo "clean old data..."
rm -rf coverage.info html
make clean 

echo "compiling tests..."
make

echo "running tests..."
./reversi_testrunner_whitebox

# echo "generating coverage reports..."
lcov --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1
lcov -e coverage.info -o coverage.info $TARGET_FILE --rc lcov_branch_coverage=1
genhtml --branch-coverage --highlight -legend coverage.info --output-directory html --rc lcov_branch_coverage=1

#change dir
cd html

if [[ "$(uname -r)" =~ "WSL" ]]; then 
    #when using WSL ubuntu
    explorer.exe index.html
else
    #when using ubuntu
    open index.html 
fi


