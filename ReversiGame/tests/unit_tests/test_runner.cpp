//run all tests
#include <iostream>

#include "gtest/gtest.h"
#include "macros.h"
#include "log.h"
#include "globals.h"

int main(int argc, char **argv) {
    //setup logger for debugging
    LOGCFG.headers = true; 
    LOGCFG.ENABLE = true;
    LOGCFG.level = DEBUG;

    //start unit tests
    LOG(INFO) << "Start box tests";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



/* TODOs:
 * Add scenarios for unit tests that are out of scope e.g cell 8 9 10 or -1 -2 -3
 * Placeholder::calculatePlaceholderPlacesForPlayer TODO
 * Optimize tests
 * 
 * Most bugs found for:
 * - corner cases - fixed
 * - disc case: right diagonal side '/' - fixed
 */