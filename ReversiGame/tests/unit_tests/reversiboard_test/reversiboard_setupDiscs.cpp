#include "reversiboard_test.h"
#include "log.h"

TEST_F(ReversiBoardTest, setupDiscRulesForUser) {  
 // Set up mock behaviors
  EXPECT_CALL(mockPlayer, getComputerColor()).WillOnce(Return('W'));
  EXPECT_CALL(mockReversiGame, getComputer()).WillOnce(Return(&mockPlayer));
   

   // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForUser(0, 0, NULL),
                ::testing::ExitedWithCode(1),
                "");
  }

   // Test case 2: test corner cases
  {
    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForUser(-1, -1, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");

    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForUser(-1, 7, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");

    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForUser(8, 1, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");

    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForUser(-2, -2, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");
  }

  // Testcase 3: Test if setupDiscRulesForUser is called
  // Note: no need to retest the logic of this function since 
  // it's already tested seperately. 
  EXPECT_CALL(*mockDiscs, setupDiscsRules(3, 4, 'W', reversiboard_uut)).Times(1);
  // Create test object and call function
  reversiboard_uut->setupDiscRulesForComputer(3, 4, &mockReversiGame);
  // Verify that the correct values were set in the board
  EXPECT_EQ(reversiboard_uut->getBoardCell(3, 4), 'W');
  

// Verify that the mock objects were called as expected and then clear it
  testing::Mock::VerifyAndClearExpectations(&mockPlayer);
  testing::Mock::VerifyAndClearExpectations(&mockReversiGame);
  testing::Mock::VerifyAndClearExpectations(mockDiscs);
}


TEST_F(ReversiBoardTest, setupDiscRulesForComputer) {
  // Set up mock behaviors
  EXPECT_CALL(mockPlayer, getComputerColor()).WillOnce(Return('W'));
  EXPECT_CALL(mockReversiGame, getComputer()).WillOnce(Return(&mockPlayer));
   

   // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForComputer(0, 0, NULL),
                ::testing::ExitedWithCode(1),
                "");
  }

   // Test case 2: test corner cases
  {
    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForComputer(-1, -1, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");

    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForComputer(-1, 7, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");

    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForComputer(8, 1, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");

    EXPECT_EXIT(reversiboard_uut->setupDiscRulesForComputer(-2, -2, &mockReversiGame),
                ::testing::ExitedWithCode(1),
                "");
  }

  // Testcase 3: Test if setupDiscRulesForComputer is called
  // Note: no need to retest the logic of this function since 
  // it's already tested seperately.    
  EXPECT_CALL(*mockDiscs, setupDiscsRules(3, 4, 'W', reversiboard_uut)).Times(1);
  // Create test object and call function
  reversiboard_uut->setupDiscRulesForComputer(3, 4, &mockReversiGame);
  // Verify that the correct values were set in the board
  EXPECT_EQ(reversiboard_uut->getBoardCell(3, 4), 'W');


// Verify that the mock objects were called as expected and then clear it
  testing::Mock::VerifyAndClearExpectations(&mockPlayer);
  testing::Mock::VerifyAndClearExpectations(&mockReversiGame);
  testing::Mock::VerifyAndClearExpectations(mockDiscs);
}