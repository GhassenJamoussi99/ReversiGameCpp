#include "placeholder_test.h"

TEST_F(PlaceholderTest, checkHorizontalPlaceholder) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(3, 4, 'B', NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }

  //Test case 1: Not entering 'while' and 'if' statements
  {
    EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(7, 0)).WillRepeatedly(Return('B'));
    
    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 0, '+')).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(6, 0, '+')).Times(0);

    // if player uses 'B' stones then opponentPiece = 'W'
    // checkHorizontalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *board)
    placeholder_uut->checkHorizontalPlaceholder(0, 0, 'W', &mockBoard);
    placeholder_uut->checkHorizontalPlaceholder(7, 0, 'W', &mockBoard);
  }

  //Test case 2: test placeholder - down check ^
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->checkHorizontalPlaceholder(2, 0, 'W', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(2, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(2, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(2, 2, '+')).Times(1);

    placeholder_uut->checkHorizontalPlaceholder(2, 0, 'B', &mockBoard);
   }

  //Test case 2: test placeholder - upper check v
  {
    //clear
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
    //player 'B'
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 2, '+')).Times(1);

    placeholder_uut->checkHorizontalPlaceholder(1, 0, 'W', &mockBoard);

    //player 'W'
    EXPECT_CALL(mockBoard, getBoardCell(1, 0)).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockBoard, getBoardCell(1, 1)).WillRepeatedly(Return('B'));

    EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
    EXPECT_CALL(mockBoard, setBoardCell(1, 2, '+')).Times(1);

    placeholder_uut->checkHorizontalPlaceholder(1, 0, 'B', &mockBoard);
   }


   //Test case 3: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
     /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | W | - | - | - | - | - | - | - |   |
        2  C | W | - | - | - | - | - | - | - |  Down check  
        3  D | W | - | - | - | - | - | - | - | 
        4  E | W | - | - | - | - | - | - | - |   |
        5  F | W | - | - | - | - | - | - | - |  \_/ 
        6  G | W | - | - | - | - | - | - | - | Upper check
        7  H | B | - | - | - | - | - | - | - | 
     */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 3)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('W'));

      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 0, '+')).Times(1);
      
      placeholder_uut->checkHorizontalPlaceholder(0, 7, 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(0, 7)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 3)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('B'));

      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(0, 0, '+')).Times(1);
      
      placeholder_uut->checkHorizontalPlaceholder(0, 7, 'B', &mockBoard);
   }

   //Test case 4: test specific cases
   {
     //clear
     EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
     
     //player 'B'
     EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('W'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('W'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('W'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 3)).WillRepeatedly(Return('W'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('W'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('W'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('B'));

     EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
     EXPECT_CALL(mockBoard, setBoardCell(0, 7, '+')).Times(1);
    
     placeholder_uut->checkHorizontalPlaceholder(0, 0, 'W', &mockBoard);

     //player 'W'
     EXPECT_CALL(mockBoard, getBoardCell(0, 6)).WillRepeatedly(Return('B'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 5)).WillRepeatedly(Return('B'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 4)).WillRepeatedly(Return('B'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 3)).WillRepeatedly(Return('B'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 2)).WillRepeatedly(Return('B'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 1)).WillRepeatedly(Return('B'));
     EXPECT_CALL(mockBoard, getBoardCell(0, 0)).WillRepeatedly(Return('W'));

     EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
     EXPECT_CALL(mockBoard, setBoardCell(0, 7, '+')).Times(1);
    
     placeholder_uut->checkHorizontalPlaceholder(0, 0, 'B', &mockBoard);
   }


    //Test case 4: test specific cases
   {
      //clear
      EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));
    
      /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | B | W | B | - | - | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
      */

      //player 'B'
      EXPECT_CALL(mockBoard, getBoardCell(2, 1)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 3)).WillRepeatedly(Return('B'));

      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 0, '+')).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 1, '+')).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 3, '+')).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 4, '+')).Times(0);

      placeholder_uut->checkHorizontalPlaceholder(2, 1, 'W', &mockBoard);
      placeholder_uut->checkHorizontalPlaceholder(2, 3, 'W', &mockBoard);

      //player 'W'
      EXPECT_CALL(mockBoard, getBoardCell(2, 1)).WillRepeatedly(Return('W'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 2)).WillRepeatedly(Return('B'));
      EXPECT_CALL(mockBoard, getBoardCell(2, 3)).WillRepeatedly(Return('W'));

      EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 0, '+')).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 1, '+')).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 3, '+')).Times(0);
      EXPECT_CALL(mockBoard, setBoardCell(2, 4, '+')).Times(0);

      placeholder_uut->checkHorizontalPlaceholder(2, 1, 'B', &mockBoard);
      placeholder_uut->checkHorizontalPlaceholder(2, 3, 'B', &mockBoard);
    }

   //Testcase 5: test corner cases
   {
     EXPECT_CALL(mockBoard, setBoardCell(_, _, _)).Times(0);

     //test undefined stones
     EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(0, 0, 'F', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(0, 0, 'D', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     //test undefined indices
     EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(-1, -1, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(8, 8, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");


     EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(7, -1, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");

     EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(-1, 7, 'B', &mockBoard),
                ::testing::ExitedWithCode(1),
                "");
    
   }
   // Verify that the mock objects were called as expected and then clear it
   testing::Mock::VerifyAndClearExpectations(&mockBoard);
}

