#include "placeholder_test.h"

TEST_F(PlaceholderTest, checkDiagonalPlaceholder) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(3, 4, 'B', NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }
  
  //Test case 1: Not entering 'while' and 'if' statements
  {
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, setBoardCell(1, 0, '+')).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(6, 0, '+')).Times(0);

    // if player uses 'B' stones then opponentPiece = 'W'
    // checkDiagonalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *board)
    placeholder_uut->checkDiagonalPlaceholder(0, 0, 'W', &mockBoard);
    placeholder_uut->checkDiagonalPlaceholder(7, 0, 'W', &mockBoard);
  }
  
  //Test case 2: test placeholder - first diagonal check '\' - left side 
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(0, 0, 'W', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(0, 0, 'B', &mockBoard);
   }

  //Test case 3: test placeholder - first diagonal check '\' - right side 
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 0, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(2, 2, 'W', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(0, 0, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(2, 2, 'B', &mockBoard);
   }


  //Test case 4: test placeholder - second diagonal check '/' - left side 
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('W'));
    
    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(5, 2, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(7, 0, 'W', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(5, 2, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(7, 0, 'B', &mockBoard);
   }

  //Test case 5: test placeholder - first diagonal check '\' - right side 
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(5, 2)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('W'));
    
    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(7, 0, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(5, 2, 'W', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(5, 2)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('B'));
    
    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(7, 0, '+')).Times(1);

    placeholder_uut->checkDiagonalPlaceholder(5, 2, 'B', &mockBoard);
   }

   //Test case 6: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | W | - |   |
        2  C | - | - | - | - | - | W | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | W | - | - | - | - |   |
        5  F | - | - | W | - | - | - | - | - |  \_/ 
        6  G | - | W | - | - | - | - | - | - | Upper check
        7  H | B | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 2)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 3)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 4)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 5)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 6)).WillRepeatedly(Return('W'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 7, '+')).Times(1);
      
      placeholder_uut->checkDiagonalPlaceholder(7, 0, 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 2)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 3)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 4)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 5)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 6)).WillRepeatedly(Return('B'));

      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 7, '+')).Times(1);
      
      placeholder_uut->checkDiagonalPlaceholder(7, 0, 'B', &mockBoard);
   }

   //Test case 6: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | B |  / \
        1  B | - | - | - | - | - | - | W | - |   |
        2  C | - | - | - | - | - | W | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | W | - | - | - | - |   |
        5  F | - | - | W | - | - | - | - | - |  \_/ 
        6  G | - | W | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 2)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 3)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 4)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 5)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 6)).WillRepeatedly(Return('W'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);   
      EXPECT_CALL(mockBoard, setBoardCell(7, 0, '+')).Times(1);
      
      placeholder_uut->checkDiagonalPlaceholder(0, 7, 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(6, 1)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 2)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 3)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 4)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 5)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 6)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('W'));

      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(7, 0, '+')).Times(1);
      
      placeholder_uut->checkDiagonalPlaceholder(0, 7, 'B', &mockBoard);
   }

      //Test case 6: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | B | - | - | - | - | - | - | - |  / \
        1  B | - | W | - | - | - | - | - | - |   |
        2  C | - | - | W | - | - | - | - | - |  Down check  
        3  D | - | - | - | W | - | - | - | - | 
        4  E | - | - | - | - | W | - | - | - |   |
        5  F | - | - | - | - | - | W | - | - |  \_/ 
        6  G | - | - | - | - | - | - | W | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 3)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 4)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 5)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 6)).WillRepeatedly(Return('W'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);      
      EXPECT_CALL(mockBoard, setBoardCell(7, 7, '+')).Times(1);
      
      placeholder_uut->checkDiagonalPlaceholder(0, 0, 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(3, 3)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(4, 4)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(5, 5)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(6, 6)).WillRepeatedly(Return('B'));
      
      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(7, 7, '+')).Times(1);
      
      placeholder_uut->checkDiagonalPlaceholder(0, 0, 'B', &mockBoard);
   }

   //Testcase 7: test corner cases
   {
     EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

     //test undefined stones
     EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(0, 0, 'F', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(0, 0, 'D', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     //test undefined indices
     EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(-1, -1, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(8, 8, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");


     EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(7, -1, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(-1, 7, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");
    
   }

   // Verify that the mock objects were called as expected and then clear it
   testing::Mock::VerifyAndClearExpectations(&mockBoard);
}

