#include "reversiboard_test.h"


TEST_F(ReversiBoardTest, UpdateBoard) {
    //setup mocks

    // Test case 1: game is NULL
    {
        EXPECT_EXIT(reversiboard_uut->updateBoard(NULL),
                    ::testing::ExitedWithCode(1),
                    "");
    }

    /********************************************************************************/
    // Test case 2: test if it's inside user->getUserTurn
    // Set up mock objects
    EXPECT_CALL(mockReversiGame, updateGameState()).Times(1);
    EXPECT_CALL(mockReversiGame, getGameState()).WillOnce(Return(true));

    EXPECT_CALL(mockPlayer, getUserColor()).WillRepeatedly(Return('B'));
    EXPECT_CALL(mockPlayer, getUserTurn()).WillRepeatedly(Return(true));

    //EXPECT_CALL(mockPlayer, getComputerColor()).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockPlayer, move(_)).Times(1);
    EXPECT_CALL(*mockPlaceholder, setupPlaceholderRules('B', _)).Times(1);
    EXPECT_CALL(mockReversiGame, getUser()).WillRepeatedly(Return(&mockPlayer));
    EXPECT_CALL(mockReversiGame, getComputer()).WillRepeatedly(Return(&mockPlayer));

    //EXPECT_CALL(*mockPlaceholder, setupPlaceholderRules('W', _)).Times(1);

    // Call updateBoard
    reversiboard_uut->updateBoard(&mockReversiGame);

    /********************************************************************************/
    // Test case 3: test if it's inside user->getComputerTurn
    // Set up mock objects
    EXPECT_CALL(mockReversiGame, updateGameState()).Times(1);
    EXPECT_CALL(mockReversiGame, getGameState()).WillOnce(Return(true));

    EXPECT_CALL(mockPlayer, getComputerColor()).WillRepeatedly(Return('W'));
    EXPECT_CALL(mockPlayer, getUserTurn()).WillRepeatedly(Return(false));

    //EXPECT_CALL(mockPlayer, getComputerColor()).WillRepeatedly(Return('W'));

    EXPECT_CALL(mockPlayer, move(_)).Times(1);
    EXPECT_CALL(*mockPlaceholder, setupPlaceholderRules('W', _)).Times(1);
    EXPECT_CALL(mockReversiGame, getUser()).WillRepeatedly(Return(&mockPlayer));
    EXPECT_CALL(mockReversiGame, getComputer()).WillRepeatedly(Return(&mockPlayer));

    // Call updateBoard
    reversiboard_uut->updateBoard(&mockReversiGame);
    /********************************************************************************/

    // Verify that the mock objects were called as expected and then clear them
    testing::Mock::VerifyAndClearExpectations(&mockPlayer);
    testing::Mock::VerifyAndClearExpectations(&mockReversiGame);
    testing::Mock::VerifyAndClearExpectations(mockPlaceholder);
}