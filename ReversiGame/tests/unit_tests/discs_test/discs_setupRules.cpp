#include "discs_test.h"

TEST_F(DiscsTest, setupDiscsRules) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(discs_uut->setupDiscsRules(0, 0, 'B', NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }

  // Test case 2: check if checkVerticalDiscs is called
  {
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 0, 'B')).Times(2);

    discs_uut->setupDiscsRules(0, 0, 'B', &mockBoard);
    discs_uut->setupDiscsRules(2, 0, 'B', &mockBoard);

    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 0, 'W')).Times(2);

    discs_uut->setupDiscsRules(0, 0, 'W', &mockBoard);
    discs_uut->setupDiscsRules(2, 0, 'W', &mockBoard);
  }

  // Test case 3: check if checkHorizontalDiscs is called
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 1, 'B')).Times(2);

    discs_uut->setupDiscsRules(0, 0, 'B', &mockBoard);
    discs_uut->setupDiscsRules(0, 2, 'B', &mockBoard);

    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 1, 'W')).Times(2);

    discs_uut->setupDiscsRules(0, 0, 'W', &mockBoard);
    discs_uut->setupDiscsRules(0, 2, 'W', &mockBoard);
  }

    // Test case 4: check if checkDiagonalDiscs is called
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 1, 'B')).Times(2);

    discs_uut->setupDiscsRules(0, 0, 'B', &mockBoard);
    discs_uut->setupDiscsRules(2, 2, 'B', &mockBoard);

    //player 'B'    
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 1, 'W')).Times(2);

    discs_uut->setupDiscsRules(0, 0, 'W', &mockBoard);
    discs_uut->setupDiscsRules(2, 2, 'W', &mockBoard);
  }

  // Test case 5: test corner cases
  {
    //player 'F' ?
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    EXPECT_EXIT(discs_uut->setupDiscsRules(0, 0, 'F', &mockBoard),
                ::testing::ExitedWithCode(1), 
                "");

    //player 'D' ?
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    EXPECT_EXIT(discs_uut->setupDiscsRules(0, 0, 'D', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");
  }
}