# Unit Testing for Reversi Game Project

This document outlines the procedure used to write and run unit tests for this project, as well as the test results and any issues that were discovered during the testing process. Unit testing is an important part of the software development process, as it helps to ensure that individual units or components of a software application are working correctly and that the application as a whole is functioning as expected. In this project, Google Test and Mock frameworks were used to implement the unit tests and mock objects were used to simulate the behavior of other classes. The test results and any issues that were discovered during the testing process are also discussed in this document.

## Procedure used to write unit tests 
Unit testing is a software testing method in which individual units or components of a software application are tested in isolation from the rest of the application. In the reversi game project, Google Test and Mock frameworks are used to implement the unit tests.

The purpose of these unit tests is to test the functionality of a particular class independently, without considering the rest of the application. For this purpose, mock objects are used for the other classes that the tested class depends on.

A test fixture has been created for each class to be tested. Within the test fixture, test cases are defined using the `TEST_F` macro. These test cases include various scenarios that the tested class should handle correctly. `TEST_F` takes as an argument `TestFixtureName` and the `TestName`. Multiple test cases will be defined within a single a `TestName`.

Before each test case, the `SetUp` function is called to initialize the required objects and variables. After the test case is run, the `TearDown` function is called to clean up any resources that were used during the test case.

Mock objects are created for the other classes that the tested class depends on. These mock objects are used to simulate the behavior of the other classes in order to test the functionality of the tested class.

`EXPECT_CALL` macro is used to specify the expected behavior of the mock objects. The test case will fail if the mock objects do not behave as expected.

Once the test cases have been defined and the mock objects have been set up, the tests are run using the `RUN_ALL_TESTS` macro. The output of the tests indicates whether all the test cases have passed or if any of them have failed.

In this way, it can ensured that the individual units or components of the reversi game application are working correctly and that the application as a whole is functioning as expected.

## Test Report

### Placeholder

| Test Suite | Test name | Meaning |
| ------ | ------ | ------ |
| PlaceholderTest | calculatePlaceholderPlacesForPlayer | Testing the calculation of placeholder positions for a given player |
| PlaceholderTest | checkDiagonalPlaceholder | Testing the diagonal placeholder calculation |
| PlaceholderTest | checkHorizontalPlaceholder | Testing the horizontal placeholder calculation |
| PlaceholderTest | checkVerticalPlaceholder | Testing the vertical placeholder calculation |
| PlaceholderTest | resetPlaceholderPlaces | Testing the resetting of placeholder positions |
| PlaceholderTest | setupPlaceholderRules | Testing the setup of placeholder positions for a given player |

### Discs

| Test Suite | Test name | Meaning |
| ------ | ------ | ------ |
| DiscsTest | checkDiagonalDiscs | Testing the calculation of diagonal discs positions |
| DiscsTest | checkHorizontalDiscs | Testing the calculation of horizontal discs positions |
| DiscsTest | checkVerticalDiscs | Testing the calculation of vertical discs positions |
| DiscsTest | setupDiscsRules | Testing the setup of discs positions for a given player |
| ReversiBoardTest | setupSpaceBoard | Testing the setup of an empty board |

### ReversiBoard

| Test Suite | Test name | Meaning |
| ------ | ------ | ------ |
| ReversiBoardTest | setup | Testing the setup of the board with starting positions |
| ReversiBoardTest | setupDiscRulesForUser | Testing the setup of disc rules for the user |
| ReversiBoardTest | setupDiscRulesForComputer | Testing the setup of disc rules for the computer |
| ReversiBoardTest | UpdateBoard | Testing the updating of the board |


### Computer

| Test Suite | Test name | Meaning |
| ------ | ------ | ------ |
| ComputerTest | move | Test that the function always returns a valid move and follows the correct priority order |
| ComputerTest | TestCornersRules | This test case assumes that the ReversiGame class and the Move struct have been implemented correctly |
| ComputerTest | DangerZoneRules | This test case assumes that the ReversiGame class and the Move struct have been implemented correctly|

### Player

| Test Suite | Test name | Meaning |
| ------ | ------ | ------ |
| Player | NO  | don't need to test this Class, it has only simple Functions|

### Results
During the unit testing process, it was discovered that several corner cases were not being adequately considered in the Reversi logic. In particular, the logic did not properly handle the following scenarios:

1. Checking whether a pointer is null or not: In most of the cases, the Reversi logic was not checking if a pointer was null before attempting to dereference it. This could have led to null pointer exceptions and other issues if the pointer was indeed null.

2. Placeholder placement in rows or columns higher than 7 or lower than 0: The Reversi logic was not adequately considering the possibility of placeholder placement in rows or columns higher than 7. This could have led to incorrect test results or crash in the program if placeholder placement in these locations was allowed in the code being tested.

3. Disc placement in rows or columns higher than 7 or lower than 0: Similar to the issue with placeholder placement, the Reversi logic was not adequately considering the possibility of disc placement in rows or columns higher than 7. This could have resulted in incorrect test results or crash in the program if disc placement in these locations was allowed in the code being tested.


4. move the function handles the "pass" case correctly but the test that the function handles the "pass" case correctly was only by setting up the game board in a way that does not allow any not  valid moves and the user has been placed his disc on the right place.

5. The logic was using a global object in several places, which made it difficult to properly unit test the individual components of the application. To resolve this issue, we decided to change the global object to a parameter that could be passed to the functions that needed it. This allowed us to more easily mock the object and simulate its behavior for the purpose of unit testing. By changing the global object to a parameter, we were able to unit test the individual components of the application more effectively and avoid problems such as null pointer exceptions and other issues that could have occurred if we had not made this change.

To address these issues, the logic of the game was modified to properly handle these corner cases. This helped to ensure that the tests were more comprehensive and reliable. As a result of these modifications, all tests passed successfully and no significant issues were encountered during the testing process.

## Conclusion
Overall, the unit testing process allowed for the identification and resolution of several issues in the reversi game logic, ensuring that the individual units and components of the application were working correctly and the application as a whole was functioning as expected.


## References
Some errors are captured under `unit_tests/errors.txt`


## Screenshots
![](ReversiGame/tests/unit_tests/errors_screenshots/errors00.jpeg)

![](ReversiGame/tests/unit_tests/errors_screenshots/errors01.jpeg)







