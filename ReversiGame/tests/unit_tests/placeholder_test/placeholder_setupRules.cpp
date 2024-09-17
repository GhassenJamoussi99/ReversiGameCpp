#include "placeholder_test.h"

TEST_F(PlaceholderTest, setupPlaceholderRules) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(placeholder_uut->setupPlaceholderRules('B', NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }

  // Test case 1: check if calculatePlaceholderPlacesForPlayer is called
  {
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 2, '+')).Times(1);

    placeholder_uut->setupPlaceholderRules('B', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 2, '+')).Times(1);

    placeholder_uut->setupPlaceholderRules('W', &mockBoard);
  }

  // Test case 2: test corner cases
  {
    //player 'F' ?
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    EXPECT_EXIT(placeholder_uut->setupPlaceholderRules('F', &mockBoard),
                ::testing::ExitedWithCode(1), 
                "");

    //player 'D' ?
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    EXPECT_EXIT(placeholder_uut->setupPlaceholderRules('D', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");
  }

  // Verify that the mock objects were called as expected and then clear it
  testing::Mock::VerifyAndClearExpectations(&mockBoard);
}