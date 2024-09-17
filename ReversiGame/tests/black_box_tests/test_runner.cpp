//run all tests
#include <iostream>

#include "gtest/gtest.h"
#include "macros.h"
#include "log.h"
#include "globals.h"

int main(int argc, char **argv) {
    //setup logger for debugging
    LOGCFG.headers = true; 
    LOGCFG.ENABLE = false;
    LOGCFG.level = DEBUG;

    //start unit tests
    LOG(INFO) << "Start white box tests";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



/* TODOs:
 */