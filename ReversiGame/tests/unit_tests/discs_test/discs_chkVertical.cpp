#include "discs_test.h"

TEST_F(DiscsTest, checkVerticalDiscs) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(discs_uut->checkVerticalDiscs(3, 4, 'B', 'W' ,NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }

  //Test case 1: Not entering 'while' and 'if' statements
  {
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

    //if player uses 'B' stones then opponentPiece = 'W'
    discs_uut->checkVerticalDiscs(0, 0, 'B', 'W', &mockBoard);
    discs_uut->checkVerticalDiscs(7, 0, 'B', 'W', &mockBoard);
  }

  //Test case 2: test if there's a flip in the vertical side
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 0, 'B')).Times(2);

    discs_uut->checkVerticalDiscs(0, 0, 'B', 'W', &mockBoard);
    discs_uut->checkVerticalDiscs(2, 0, 'B', 'W', &mockBoard);

    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 0, 'W')).Times(2);

    discs_uut->checkVerticalDiscs(0, 0, 'W', 'B', &mockBoard);
    discs_uut->checkVerticalDiscs(2, 0, 'W', 'B', &mockBoard);
   }

   //Test case 3: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | B | - | - | - | - | - | - | - |  / \
        1  B | W | - | - | - | - | - | - | - |   |
        2  C | W | - | - | - | - | - | - | - |  Down check  
        3  D | W | - | - | - | - | - | - | - | 
        4  E | W | - | - | - | - | - | - | - |   |
        5  F | W | - | - | - | - | - | - | - |  \_/ 
        6  G | W | - | - | - | - | - | - | - | Upper check
        7  H | B | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(_, 0, 'B')).Times(12);
      EXPECT_CALL(mockBoard, setBoardCell(7, 0, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 0, _)).Times(0);

      discs_uut->checkVerticalDiscs(0, 0, 'B', 'W', &mockBoard);
      discs_uut->checkVerticalDiscs(7, 0, 'B', 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(_, 0, 'W')).Times(12);
      EXPECT_CALL(mockBoard, setBoardCell(7, 0, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 0, _)).Times(0);

      discs_uut->checkVerticalDiscs(0, 0, 'W', 'B', &mockBoard);
      discs_uut->checkVerticalDiscs(7, 0, 'W', 'B', &mockBoard);
   }

   //Test case 4: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | B | - | - | - | - | - | - | - |  / \
        1  B | W | - | - | - | - | - | - | - |   |
        2  C | W | - | - | - | - | - | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | W | - | - | - | - | - | - | - |   |
        5  F | W | - | - | - | - | - | - | - |  \_/ 
        6  G | W | - | - | - | - | - | - | - | Upper check
        7  H | B | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

      discs_uut->checkVerticalDiscs(0, 0, 'B', 'W', &mockBoard);
      discs_uut->checkVerticalDiscs(7, 0, 'B', 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

      discs_uut->checkVerticalDiscs(0, 0, 'W', 'B', &mockBoard);
      discs_uut->checkVerticalDiscs(7, 0, 'W', 'B', &mockBoard);
   }


  //  Testcase 5: test corner cases
   {
     EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

     //test undefined stones
     EXPECT_EXIT(discs_uut->checkVerticalDiscs(0, 0, 'F', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkVerticalDiscs(0, 0, 'B', 'D', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     //test undefined indices
     EXPECT_EXIT(discs_uut->checkVerticalDiscs(-1, -1, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkVerticalDiscs(8, 8, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkVerticalDiscs(7, -1, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(discs_uut->checkVerticalDiscs(-1, 7, 'W', 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");    
   }
   
   // Verify that the mock objects were called as expected and then clear it
   testing::Mock::VerifyAndClearExpectations(&mockBoard);
}

