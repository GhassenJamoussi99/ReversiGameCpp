#include "discs_test.h"

TEST_F(DiscsTest, checkHorizontalDiscs) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(discs_uut->checkHorizontalDiscs(3, 4, 'B', 'W' ,NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }

  //Test case 1: Not entering 'while' and 'if' statements
  {
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    //if player uses 'B' stones then opponentPiece = 'W'
    discs_uut->checkHorizontalDiscs(0, 0, 'B', 'W', &mockBoard);
    discs_uut->checkHorizontalDiscs(7, 0, 'B', 'W', &mockBoard);
  }

  //Test case 2: test if there's a flip in the horizontal side
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 1, 'B')).Times(2);

    discs_uut->checkHorizontalDiscs(0, 0, 'B', 'W', &mockBoard);
    discs_uut->checkHorizontalDiscs(0, 2, 'B', 'W', &mockBoard);

    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 1, 'W')).Times(2);

    discs_uut->checkHorizontalDiscs(0, 0, 'W', 'B', &mockBoard);
    discs_uut->checkHorizontalDiscs(0, 2, 'W', 'B', &mockBoard);
   }

   //Test case 3: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | B | W | W | W | W | W | W | B |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | - | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 3)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, _, 'B')).Times(12);
      EXPECT_CALL(mockBoard, setBoardCell(0, 0, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 7, _)).Times(0);

      discs_uut->checkHorizontalDiscs(0, 0, 'B', 'W', &mockBoard);
      discs_uut->checkHorizontalDiscs(0, 7, 'B', 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 3)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, _, 'W')).Times(12);
      EXPECT_CALL(mockBoard, setBoardCell(0, 0, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 7, _)).Times(0);

      discs_uut->checkHorizontalDiscs(0, 0, 'W', 'B', &mockBoard);
      discs_uut->checkHorizontalDiscs(0, 7, 'W', 'B', &mockBoard);
    }
   //Test case 3: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | B | W | W | - | W | W | W | B |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | - | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

      discs_uut->checkHorizontalDiscs(0, 0, 'B', 'W', &mockBoard);
      discs_uut->checkHorizontalDiscs(0, 7, 'B', 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

      discs_uut->checkHorizontalDiscs(0, 0, 'W', 'B', &mockBoard);
      discs_uut->checkHorizontalDiscs(0, 7, 'W', 'B', &mockBoard);
    }

  //  Testcase 5: test corner cases
   {
     EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

     //test undefined stones
     EXPECT_EXIT(discs_uut->checkHorizontalDiscs(0, 0, 'F', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkHorizontalDiscs(0, 0, 'B', 'D', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     //test undefined indices
     EXPECT_EXIT(discs_uut->checkHorizontalDiscs(-1, -1, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkHorizontalDiscs(8, 8, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkHorizontalDiscs(7, -1, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkHorizontalDiscs(-1, 7, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");    
   }
   
   // Verify that the mock objects were called as expected and then clear it
   testing::Mock::VerifyAndClearExpectations(&mockBoard);
}

