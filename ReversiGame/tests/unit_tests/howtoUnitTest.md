# Unit tests with google tests

## Introduction

Google Test (gtest) is a unit testing framework for C++ that allows you to define and run tests to verify the behavior of your code. It provides tools and interfaces for setting up test environments, defining test cases and fixtures, and making assertions about the expected behavior of your code. It is open source, actively maintained by Google, and widely used in the C++ community.

### Install Google tests

Google tests can be installed on ubuntu using the following commands:

To install gtest and gmock using `apt`, follow these steps:

1. Install the necessary build tools and dependencies:

    ```
    sudo apt-get update
    sudo apt-get install build-essential
    ```

2. Install gtest and gmock:
    ```
    sudo apt-get install libgtest-dev
    sudo apt-get install libgmock-dev
    ```

### Usage 

Gtest and gmock should now be installed on your system and ready to use in your C++ projects. You can include the necessary headers in your code and link to the gtest and gmock libraries when building your tests.

In our case we just add `-lgtest -lgmock -lpthread` to `LDLIBS` in our `Makefile`. Then we can run the makefile as usual.

## Takeaways 

### Use virtual functions with mocks

It is generally necessary to make a method virtual when you want to mock it using Google Mock or a similar library. This is because mock objects work by subclassing the original class and overriding the methods that you want to mock. In order to override a method, it must be declared as virtual in the base class.

For example, consider the following code:

    class Base {
    public:
    virtual int foo() { return 42; }
    };

    class MockBase : public Base {
    public:
    MOCK_METHOD(int, foo, (), (override));
    };

In this example, the Base class has a virtual method foo, which can be overridden in the MockBase mock class using the MOCK_METHOD macro. This allows you to define custom behavior for the foo method in your test code, such as returning a specific value or setting up an expectation for how many times the method will be called.

If the foo method was not declared as virtual in the Base class, it would not be possible to override it in the MockBase class and the mock object would not work as expected.

So, in general, it is a good idea to make methods virtual if you want to mock them using Google Mock or a similar library. This will allow you to override the methods in the mock object and define custom behavior for them in your tests.
