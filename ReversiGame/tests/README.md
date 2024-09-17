# Tests

There are different tests written for the software.

## Test types

* **Adhoc tests** : Ad hoc Testing is an informal or unstructured software testing type that aims to break the testing process in order to find possible defects or errors at an early possible stage. Ad hoc testing is done randomly and it is usually an unplanned activity which does not follow any documentation and test design techniques to create test cases.
* **Static tests**: Static testing is a type of testing that is performed without executing the code. It involves examining the code and the requirements document to ensure the code satisfies the requirements. Static testing techniques include reviews, inspections, walkthroughs, and static analysis. The goal of static testing is to identify defects in the code before testing begins.
* **Unit tests**: Unit tests are small, isolated pieces of code that are used to validate the functionality of a specific unit of code. They are typically written by developers and run automatically as part of the development process to ensure that the code is working as expected and to catch any regressions. Unit tests are run in isolation and use a testing framework to make it easy to write and run the tests. They are an important part of the software development process because they help to identify and fix issues early on, before the code is deployed to production.


* **White box test and coverage** : White box testing, also known as structural testing, is a method of testing software where the internal structure of the code is known and used to design the test cases. The purpose of white box testing is to verify that all **statements**, **branches**, and **paths** in the code have been executed and to ensure that the code meets its specifications. It is typically performed at the unit level and often involves testing individual functions or methods.

    Code coverage is a measure of the percentage of code that has been executed by the test suite. It is commonly used in white box testing to determine how well the test cases are covering the code. There are different types of coverage, such as **statement coverage**, **branch coverage**, and **path coverage**:
    *  **Statement coverage** measures the percentage of lines of code that have been 
    executed.
    
    * **Branch coverage** measures the percentage of branches that have been executed.
    
    * **Path coverage or MCDC** measures the percentage of possible execution paths that have been executed.

    White box testing and code coverage are often used together to ensure that the test suite is thorough and that all parts of the code are being tested. The goal of white box testing is to ensure that the code is working correctly and that there are no defects. And the goal of code coverage is to ensure that all parts of the code have been executed and that the test suite is complete.
