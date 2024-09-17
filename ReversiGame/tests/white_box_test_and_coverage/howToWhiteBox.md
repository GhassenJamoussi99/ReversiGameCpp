Instructions to install White-Box testing via gcov:

1. check for 
$ gcov -v
(should be included with gcc)

2. install lcov
$ apt-get install lcov

3. Go to the projects folder: '../2022ws_team2a/ReversiGame'

4. edit the Makefile
go to line 24 (CPP_COMPILER_FLAGS) and add the following arguments:
-fprofile-arcs -ftest-coverage
the result should look like this:
CPP_COMPILER_FLAGS = -fprofile-arcs -ftest-coverage -g -O0 -std=$(CPP_STANDARD)
save.

5. $ make
now in the '../build' folder should be a *.gcno file for each *.o file

6. Start the game to test "manually"
$ ./reversi_game
and play a bit around, try to use as many functionalities as possible to maximize the coverage rate

7. End/Exit the game
now in the '../build' folder should be *.gcda file for each file as well 

8. Use while in '../ReversiGame' 
$ lcov --capture --directory . --output-file coverage.info  --rc lcov_branch_coverage=1
this should create coverage.info

optional 8.1. now filter the files/functions, that shall be tested. BEWARE: change the absolute path!
$ lcov -e coverage.info -o coverage.info '/home/marvin/Dokumente/M14_VV/git/2022ws_team2a/ReversiGame/src/*' --rc lcov_branch_coverage=1
in this example, only the files within the /src folder will be tested!

9. Now use:
$ genhtml --branch-coverage --highlight -legend coverage.info --output-directory html --rc lcov_branch_coverage=1

10. Navigate into the /html folder, open the index.htmland take a look.

11. Be done!

For more instructions look into the presentation of both teams.
Team 1D has a detailed way to do White Box tests on Google unit tests.
