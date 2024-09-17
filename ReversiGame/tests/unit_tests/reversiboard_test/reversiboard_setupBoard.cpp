#include "reversiboard_test.h"
#include <iostream>

TEST_F(ReversiBoardTest, setupSpaceBoard) {
  reversiboard_uut->setupSpaceBoard();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == 3 && j == 3) {
        EXPECT_EQ(reversiboard_uut->getBoardCell(i, j), 'B');
      } else if (i == 3 && j == 4) {
        EXPECT_EQ(reversiboard_uut->getBoardCell(i, j), 'W');
      } else if (i == 4 && j == 3) {
        EXPECT_EQ(reversiboard_uut->getBoardCell(i, j), 'W');
      } else if (i == 4 && j == 4) {
        EXPECT_EQ(reversiboard_uut->getBoardCell(i, j), 'B');
      } else {
        EXPECT_EQ(reversiboard_uut->getBoardCell(i, j), '-');
      }
    }
  }
}

TEST_F(ReversiBoardTest, setup) {

   // Test case 1: game is NULL
  {
    EXPECT_EXIT(reversiboard_uut->setup(NULL),
                ::testing::ExitedWithCode(1),
                "");
  }

  //This does not contain any logic so we stop here.
}