#include "placeholder_test.h"

TEST_F(PlaceholderTest, calculatePlaceholderPlacesForPlayer) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(0, 0, 'B', NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }

  // Test case 2: check if checkVerticalPlaceholder is called
  {
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 0, '+')).Times(1);

    placeholder_uut->calculatePlaceholderPlacesForPlayer(2, 0, 'B', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 0, '+')).Times(1);

    placeholder_uut->calculatePlaceholderPlacesForPlayer(2, 0, 'W', &mockBoard);
  }

  // Test case 3: check if checkHorizontalPlaceholder is called
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->calculatePlaceholderPlacesForPlayer(2, 0, 'B', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->calculatePlaceholderPlacesForPlayer(2, 0, 'W', &mockBoard);
   
  }

    // Test case 4: check if checkDiagonalPlaceholder is called
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->calculatePlaceholderPlacesForPlayer(0, 0, 'B', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->calculatePlaceholderPlacesForPlayer(0, 0, 'W', &mockBoard);
  }

  // Test case 5: test corner cases
  {
    //player 'F' ?
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(0, 0, 'F', &mockBoard),
                ::testing::ExitedWithCode(1), 
                "");

    //player 'D' ?
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(0, 0, 'D', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");
  }

  // Verify that the mock objects were called as expected and then clear it
  testing::Mock::VerifyAndClearExpectations(&mockBoard);
}