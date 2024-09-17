#include "reversigame_test.h"

TEST_F(ReversiGameTest, startMenu) {
   EXPECT_CALL(mockBoard, getBoardCell(_, _)).WillRepeatedly(Return('-'));

  // Test case 1: reversiboard is NULL
  /**{
    EXPECT_EXIT(reversigame_uut->startMenu(),
                ::testing::ExitedWithCode(1), 
                "");
  }

  // Test case 2: User inputs 1
  {
    std::stringstream test_input;
    test_input << "1";
    std::cin.rdbuf(test_input.rdbuf());

    
    reversigame_uut->startMenu();
    EXPECT_CALL(mockMenu,startGame);
    
  }  

    // Test case 3: User inputs 2
  {
    

    std::stringstream test_input;
    test_input << "2";
    std::cin.rdbuf(test_input.rdbuf());

    reversigame_uut->startMenu();
    EXPECT_CALL(mockMenu,help);
    
    
  }*/  

    // Test Case 4: user inputs 3
  {
    std::stringstream test_input;
    test_input << "3\n";
    std::cin.rdbuf(test_input.rdbuf());

    //reversigame_uut->startMenu();
    //check for exit code == 0
  }

}