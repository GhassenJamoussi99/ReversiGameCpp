# How to run static code analysis on your code

## Steps

### 1.Install CppCheck

CppCheck is an open source static code analysis tool for C/C++ code. It can be installed on ubuntu using the following command:

    sudo apt-get update && sudo apt-get -y install cppcheck

### 2.Analyze your code

Once CppCheck is installed, you can analyze your code by running the cppcheck command with the input file as an argument.

The cppcheck command is already written under a shell script with the needed parameters so
if you want to run static code analysis, you can run:

    ./run_cppcheck.sh

A well detailled HTML report will be generated under **tests/static/cppcheck/cppcheck_reports** with the filename **index.html**.

### 3.Read the output

CppCheck will output a list of errors and warnings that it finds in your code. These can be either syntax errors or warnings about potential problems in your code.

### 4.Fix the errors

Once you have identified the errors, you can fix them either manually or using an automated refactoring tool.

### 5.Repeat

Once the errors have been fixed, you can re-run CppCheck to make sure that all the issues have been resolved. If any new errors are found, you can repeat the process until your code is free of static code analysis warnings.
