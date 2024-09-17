#include "discs_test.h"


TEST_F(DiscsTest, setupDiscsRules) {
    char playerPiece;
    int i,j;

    // Test for valid input
    playerPiece = 'B';
    i = 4;
    j = 4;
    reversiboard.setBoardCell(i,j,playerPiece);
    discs_uut->setupDiscsRules(i, j, playerPiece, &reversiboard);

    playerPiece = 'W';
    i = 4;
    j = 4;
    reversiboard.setBoardCell(i,j,playerPiece);
    discs_uut->setupDiscsRules(i, j, playerPiece, &reversiboard);

    // Test for unknown playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(discs_uut->setupDiscsRules(i, j, playerPiece, &reversiboard),
                 ::testing::ExitedWithCode(1), "");

    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(discs_uut->setupDiscsRules(i, j, playerPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");

    // Test for out of scope indices
    i = -1;
    j = 8;
    EXPECT_EXIT(discs_uut->setupDiscsRules(i, j, playerPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");   
}


TEST_F(DiscsTest, CheckHorizontalDiscs) {
    reversiboard.cleanBoard();
    int row,col;
    char playerPiece, opponentPiece;

    /************************* Test for valid input ********************************/
    //left check
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | W | B | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    playerPiece = 'B';
    opponentPiece = 'W';
    row = 2;
    col = 5;
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(2,3,'B');
    discs_uut->checkHorizontalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,4),'B');

    //right check
    reversiboard.cleanBoard();

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | W | B | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    row = 2;
    col = 3;
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(2,5,'B');
    discs_uut->checkHorizontalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,4),'B');

    // Test for null reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(discs_uut->checkHorizontalDiscs(row, col, playerPiece, opponentPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");

    // Test for out of scope indices
    row = -1;
    col = 8;
    EXPECT_EXIT(discs_uut->checkHorizontalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for invalid playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(discs_uut->checkHorizontalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for invalid opponentPiece
    playerPiece = 'B';
    opponentPiece = 'X';
    EXPECT_EXIT(discs_uut->checkHorizontalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

}


TEST_F(DiscsTest, CheckVerticalDiscs) {
    reversiboard.cleanBoard();
    int row,col;
    char playerPiece, opponentPiece;

    /************************* Test for valid input ********************************/
    //down check

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | - | - | - | - |  Down check  
        3  D | - | - | - | W | - | - | - | - | 
        4  E | - | - | - | B | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    playerPiece = 'B';
    opponentPiece = 'W';
    row = 4;
    col = 3;
    reversiboard.setBoardCell(3,3,opponentPiece);
    reversiboard.setBoardCell(2,3,'B');
    discs_uut->checkVerticalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,3),'B');

    //upper check
    reversiboard.cleanBoard();

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | - | - | - | - |  Down check  
        3  D | - | - | - | W | - | - | - | - | 
        4  E | - | - | - | B | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    row = 2;
    col = 3;
    reversiboard.setBoardCell(3,3,opponentPiece);
    reversiboard.setBoardCell(4,3,'B');
    discs_uut->checkVerticalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,3),'B');

    // Test for null reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(discs_uut->checkVerticalDiscs(row, col, playerPiece, opponentPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");

    // Test for out of scope indices
    row = -1;
    col = 8;
    EXPECT_EXIT(discs_uut->checkVerticalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for invalid playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(discs_uut->checkVerticalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for invalid opponentPiece
    playerPiece = 'B';
    opponentPiece = 'X';
    EXPECT_EXIT(discs_uut->checkVerticalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");
}



TEST_F(DiscsTest, CheckDiagonalDiscs) {
    reversiboard.cleanBoard();
    int row,col;
    char playerPiece, opponentPiece;

    /************************* Test for valid input ********************************/
    //************ first diagonal '\'
    //check left diagonal side of the stone

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | - | - | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | - | - | B | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    playerPiece = 'B';
    opponentPiece = 'W';
    row = 4;
    col = 5;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(2,3,'B');
    discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,4),'B');

    //check right diagonal side of the stone
    reversiboard.cleanBoard();
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | - | - | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | - | - | B | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    playerPiece = 'B';
    opponentPiece = 'W';
    row = 2;
    col = 3;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(4,5,'B');
    discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,4),'B');

    //************ second diagonal '/'
    //check left diagonal side of the stone 
    reversiboard.cleanBoard();

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | B | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | B | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    row = 2;
    col = 5;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(4,3,'B');
    discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,4),'B');

    //check right diagonal side of the stone
    reversiboard.cleanBoard();

        /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | B | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | B | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    row = 4;
    col = 3;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(2,5,'B');
    discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,4),'B');

    // Test for null reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");

    // Test for out of scope indices
    row = -1;
    col = 8;
    EXPECT_EXIT(discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for invalid playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for invalid opponentPiece
    playerPiece = 'B';
    opponentPiece = 'X';
    EXPECT_EXIT(discs_uut->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

}