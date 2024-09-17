#include "placeholder_test.h"

TEST_F(PlaceholderTest, CheckVerticalPlaceholderMCDC) {
    reversiboard.cleanBoard();
    int i,j;
    char opponentPiece;

    /************************* Test for valid input ********************************/
    //////////////// down
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | B | - | - | - |   |
        2  C | - | - | - | - | W | - | - | - |  Down check  
        3  D | - | - | - | - | B | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    //TRUE TRUE
    i = 3, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    //MCDC
    //FALSE TRUE - not possible

    //TRUE FALSE
    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | - | - | B | - | - | - |  Down check  
    3   D | - | - | - | - | B | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 3, j = 4;
    opponentPiece = 'B';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    //FALSE FALSE
    i = 3, j = 4;
    opponentPiece = 'B';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(0, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | B | - | - | - |   |
    2   C | - | - | - | - | W | - | - | - |  Down check  
    3   D | - | - | - | - | B | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 3, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(1,4,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | - | - | - | - | - | - |  Down check  
    3   D | - | - | - | - | B | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 3, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | W | - | - |  / \
    1   B | - | - | - | - | - | W | - | - |   |
    2   C | - | - | - | - | - | W | - | - |  Down check  
    3   D | - | - | - | - | - | W | - | - | 
    4   E | - | - | - | - | - | W | - | - |   |
    5   F | - | - | - | - | - | W | - | - |  \_/ 
    6   G | - | - | - | - | - | W | - | - | Upper check
    7   H | - | - | - | - | - | B | - | - | 
    */
    i = 7, j = 5;
    opponentPiece = 'W';
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(0,5,'W');
    reversiboard.setBoardCell(1,5,'W');
    reversiboard.setBoardCell(2,5,'W');
    reversiboard.setBoardCell(3,5,'W');
    reversiboard.setBoardCell(4,5,'W');
    reversiboard.setBoardCell(5,5,'W');
    reversiboard.setBoardCell(6,5,'W');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    //////////////// upper
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

    //MCDC
    //FALSE TRUE - not possible

    //TRUE FALSE
    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | - | - | B | - | - | - |  Down check  
    3   D | - | - | - | - | B | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 2, j = 4;
    opponentPiece = 'B';
    reversiboard.setBoardCell(3,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    //FALSE FALSE
    i = 3, j = 4;
    opponentPiece = 'B';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkVerticalPlaceholder(0, j, opponentPiece, &reversiboard);

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | B | - | - | - |   |
    2   C | - | - | - | - | W | - | - | - |  Down check  
    3   D | - | - | - | - | B | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 3, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(1,4,'B');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | B | - | - |  / \
    1   B | - | - | - | - | - | W | - | - |   |
    2   C | - | - | - | - | - | W | - | - |  Down check  
    3   D | - | - | - | - | - | W | - | - | 
    4   E | - | - | - | - | - | W | - | - |   |
    5   F | - | - | - | - | - | W | - | - |  \_/ 
    6   G | - | - | - | - | - | W | - | - | Upper check
    7   H | - | - | - | - | - | W | - | - | 
    */
    i = 0, j = 5;
    opponentPiece = 'W';
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(1,5,'W');
    reversiboard.setBoardCell(2,5,'W');
    reversiboard.setBoardCell(3,5,'W');
    reversiboard.setBoardCell(4,5,'W');
    reversiboard.setBoardCell(5,5,'W');
    reversiboard.setBoardCell(6,5,'W');
    reversiboard.setBoardCell(7,5,'W');
    placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard);
    reversiboard.cleanBoard();

    //Test for out of scope indices
    i = 1;
    j = 8;
    EXPECT_EXIT(placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = 1;
    j = -1;
    EXPECT_EXIT(placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = 8;
    j = 1;
    EXPECT_EXIT(placeholder_uut->checkVerticalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = -1;
    j = 1;
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

TEST_F(PlaceholderTest, CheckHorizontalPlaceholderMCDC) {
    reversiboard.cleanBoard();
    int i,j;
    char opponentPiece;

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
    i = 2, j = 3;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,5),'+');
    reversiboard.cleanBoard();

    //FALSE FALSE
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
    i = 2, j = 3;
    opponentPiece = 'B';
    reversiboard.setBoardCell(2,4,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,5),'-');
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | B | W | B | - | - | - |  Down check  
    3   D | - | - | - | - | - | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 2, j = 2;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,3,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(2,4,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,4),'B');
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | - | - | - | - | - | - |  Down check  
    3   D | - | - | - | - | B | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 3, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,4),'B');
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | B | W | W | W | W | W | W | W |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | - | - | - | - | - | - |  Down check  
    3   D | - | - | - | - | - | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 0, j = 0;
    opponentPiece = 'W';
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(0,1,'W');
    reversiboard.setBoardCell(0,2,'W');
    reversiboard.setBoardCell(0,3,'W');
    reversiboard.setBoardCell(0,4,'W');
    reversiboard.setBoardCell(0,5,'W');
    reversiboard.setBoardCell(0,6,'W');
    reversiboard.setBoardCell(0,7,'W');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(0,7),'W');
    reversiboard.cleanBoard();

    //left
    //TRUE TRUE
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | W | B | - | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 2;
    j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,3,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,2),'+');
    reversiboard.cleanBoard();

    //FALSE FALSE
    /*
               0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
        0  A | - | - | - | - | - | - | - | - |  / \
        1  B | - | - | - | - | - | - | - | - |   |
        2  C | - | - | - | W | B | - | - | - |  Down check  
        3  D | - | - | - | - | - | - | - | - | 
        4  E | - | - | - | - | - | - | - | - |   |
        5  F | - | - | - | - | - | - | - | - |  \_/ 
        6  G | - | - | - | - | - | - | - | - | Upper check
        7  H | - | - | - | - | - | - | - | - | 
    */
    i = 2, j = 4;
    opponentPiece = 'B';
    reversiboard.setBoardCell(2,3,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(0, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,2),'-');
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | B | W | B | - | - | - |  Down check  
    3   D | - | - | - | - | - | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 2, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(2,3,opponentPiece);
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(2,2,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(2,2),'B');
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | - | - | - | - | - | - | - | - |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | - | - | - | - | - | - |  Down check  
    3   D | - | - | - | - | B | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 3, j = 4;
    opponentPiece = 'W';
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(3,3),'-');
    reversiboard.cleanBoard();

    /*
            0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |   _
    0   A | W | W | W | W | W | W | W | B |  / \
    1   B | - | - | - | - | - | - | - | - |   |
    2   C | - | - | - | - | - | - | - | - |  Down check  
    3   D | - | - | - | - | - | - | - | - | 
    4   E | - | - | - | - | - | - | - | - |   |
    5   F | - | - | - | - | - | - | - | - |  \_/ 
    6   G | - | - | - | - | - | - | - | - | Upper check
    7   H | - | - | - | - | - | - | - | - | 
    */
    i = 0, j = 7;
    opponentPiece = 'W';
    reversiboard.setBoardCell(i,j,'B');
    reversiboard.setBoardCell(0,0,'W');
    reversiboard.setBoardCell(0,1,'W');
    reversiboard.setBoardCell(0,2,'W');
    reversiboard.setBoardCell(0,3,'W');
    reversiboard.setBoardCell(0,4,'W');
    reversiboard.setBoardCell(0,5,'W');
    reversiboard.setBoardCell(0,6,'W');
    placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard);
    EXPECT_EQ(reversiboard.getBoardCell(0,0),'W');
    reversiboard.cleanBoard();

    //Test for out of scope indices
    i = 1;
    j = 8;
    EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = 1;
    j = -1;
    EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = 8;
    j = 1;
    EXPECT_EXIT(placeholder_uut->checkHorizontalPlaceholder(i, j, opponentPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = -1;
    j = 1;
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

TEST_F(PlaceholderTest, setupPlaceholderRulesMCDC) {
    char playerPiece;
    int i,j;

    // Test for valid input
    playerPiece = 'B';
    i = 4;
    j = 4;
    reversiboard.setBoardCell(i,j,playerPiece);
    placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard);

    playerPiece = 'W';
    i = 4;
    j = 4;
    reversiboard.setBoardCell(i,j,playerPiece);
    placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard);

    // Test for valid input but opponent playerPiece
    playerPiece = 'B';
    i = 4;
    j = 4;
    reversiboard.setBoardCell(i,j,'W');
    placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard);

    playerPiece = 'W';
    i = 4;
    j = 4;
    reversiboard.setBoardCell(i,j,'B');
    placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard);

    // Test for unknown playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, &reversiboard),
                 ::testing::ExitedWithCode(1), "");

    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}

TEST_F(PlaceholderTest, calculatePlaceholderPlacesForPlayerMCDC) {
    int i,j;
    char playerPiece;

    // Test for valid input
    i = 3;
    j = 4;
    playerPiece = 'B';
    placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard);

    i = 3;
    j = 4;
    playerPiece = 'W';
    placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard);

    // Test for unknown playerPiece
    playerPiece = 'X';
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard),
                 ::testing::ExitedWithCode(1), "");

    //Test for out of scope indices
    i = 1;
    j = 8;
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = 1;
    j = -1;
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = 8;
    j = 1;
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");

    i = -1;
    j = 1;
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, &reversiboard),
                ::testing::ExitedWithCode(1), "");


    // Test for undefined reversiboard
    ReversiBoard* reversiboard_null = NULL;
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");

    // Test for undefined reversiboard
    EXPECT_EXIT(placeholder_uut->calculatePlaceholderPlacesForPlayer(i, j, playerPiece, reversiboard_null),
                ::testing::ExitedWithCode(1), "");
}
