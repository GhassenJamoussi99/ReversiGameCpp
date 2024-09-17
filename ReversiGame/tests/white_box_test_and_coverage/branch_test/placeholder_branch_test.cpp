#include "placeholder_test.h"

TEST_F(PlaceholderTest, CheckVerticalPlaceholderBranch) {
    reversiboard.cleanBoard();

    /************************* Test for valid input ********************************/
    //down
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | W | - | - | - |  Down check  
        3  D | - | - | - | - | B | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    int i = 3, j = 4;
    char opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(1,4),'+');
    reversiboard.cleanBoard();

    i = 3, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(1,4),'-');
    reversiboard.cleanBoard();

    //upper
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | - | - | - |  Down check  
        3  D | - | - | - | - | B | - | - | - | 
        4  E | - | - | - | - | W | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 3;
    j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(4,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(5,4),'+');
    reversiboard.cleanBoard();

    i = 3;
    j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(4,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(5,4),'-');
    reversiboard.cleanBoard();
    
    // Test for out of scope indices
    i = -1;
    j = 8;
    EXPECT_EXIT(placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for undefined player
    opponentPiece = 'X';
    EXPECT_EXIT(placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}

TEST_F(PlaceholderTest, CheckHorizontalPlaceholderBranch) {
    reversiboard.cleanBoard();

    /************************* Test for valid input ********************************/
    //right
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | W | - | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    int i = 2, j = 3;
    char opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,5),'+');
    reversiboard.cleanBoard();

    i = 2, j = 3;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,5),'-');
    reversiboard.cleanBoard();

    //left

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | - | - | - |  Down check  
        3  D | - | - | - | - | W | B | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 3;
    j = 5;
    opponentPiece = 'W';
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,3),'+');
    reversiboard.cleanBoard();

    opponentPiece = 'W';
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,3),'-');
    reversiboard.cleanBoard();

    // Test for out of scope indices
    i = -1;
    j = 8;
    EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for undefined player
    opponentPiece = 'X';
    EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}


TEST_F(PlaceholderTest, CheckDiagonalPlaceholderBranch) {
    int i,j;
    char opponentPiece;
    reversiboard.cleanBoard();

    /************************* Test for valid input ********************************/
    //************ first diagonal '\'
    //down
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | B | - | - | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 2, j = 3;
    opponentPiece = 'W';
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(4,5),'+');
    reversiboard.cleanBoard();

    i = 2, j = 3;
    opponentPiece = 'W';
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(4,5),'-');
    reversiboard.cleanBoard();

    //upper

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | - | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | - | - | B | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 4;
    j = 5;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,3),'+');
    reversiboard.cleanBoard();

    i = 4;
    j = 5;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,3),'-');
    reversiboard.cleanBoard();

    //************ second diagonal '/'
    //down
    reversiboard.cleanBoard();

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | B | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 2;
    j = 5;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(4,3),'+');
    reversiboard.cleanBoard();

    i = 2;
    j = 5;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(4,3),'-');
    reversiboard.cleanBoard();

    //upper

    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | - | - | - | - | - |  Down check  
        3  D | - | - | - | - | W | - | - | - | 
        4  E | - | - | - | B | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 4;
    j = 3;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,5),'+');
    reversiboard.cleanBoard();

    i = 4;
    j = 3;
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkDiagonalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,5),'-');
    reversiboard.cleanBoard();

    // Test for out of scope indices
    i = -1;
    j = 8;
    EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for undefined player
    opponentPiece = 'X';
    EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->checkDiagonalPlaceholder(i, j, opponentPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}


TEST_F(PlaceholderTest, resetPlaceholderPlacesBranch) {
    int i,j;
    reversiboard.cleanBoard();

    // Test for valid input
    i = 4;
    j = 4;
    reversiboard.setBoardCell(i,j,'+');
    placeholder_uut->resetPlaceholderPlaces(&reversiboard);
    for (int i = 0; i<8; i++) {
        for (int j=0; j<8; j++) {
                EXPECT_EQ(reversiboard.getBoardCell(i,j),'-');
        }
    }

    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->resetPlaceholderPlaces(reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}

TEST_F(PlaceholderTest, calculatePlaceholderPlacesForPlayerBranch) {
    int i,j;
    char playerPiece;

    // Test for valid input
    i = 3;
    j = 4;
    playerPiece = 'B';
    reversiboard.setBoardCell(2,4,'W');
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(1,4),'+');

    i = 3;
    j = 4;
    playerPiece = 'W';
    reversiboard.setBoardCell(2,4,'B');
    reversiboard.setBoardCell(i,j,'W');
    placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(1,4),'+');


    // Test for unknown playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard),
                 ::testing::ExitedWithCode(1), "");

    // Test for out of scope indices
    i = -1;
    j = 8;
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");


    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}

TEST_F(PlaceholderTest, setupPlaceholderRulesBranch) {
    char playerPiece;
    int i,j;

    // Test for valid input
    i = 3;
    j = 4;
    playerPiece = 'B';
    reversiboard.setBoardCell(2,4,'W');
    reversiboard.setBoardCell(i,j,playerPiece);
    placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(1,4),'+');

    i = 3;
    j = 4;
    playerPiece = 'W';
    reversiboard.setBoardCell(2,4,'B');
    reversiboard.setBoardCell(i,j,playerPiece);
    placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(1,4),'+');

    //placeholder not set
    i = 3;
    j = 4;
    playerPiece = 'W';
    reversiboard.setBoardCell(2,4,'B');
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(4,4),'-');

    // Test for unknown playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard),
                 ::testing::ExitedWithCode(1), "");

    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}