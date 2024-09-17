//extern includes
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "log.h"

//project includes
#include "reversigame.h"
#include "macros.h"
#include "player.h"
#include "menu.h"
#include <../include/ui/menu.h>
#include "user.h"
#include "computer.h"

using ::testing::_;
using ::testing::Return;

class MockReversiBoard : public ReversiBoard {
 public:
  MOCK_METHOD(char, getBoardCell, (int i, int j), (override));
  MOCK_METHOD(void, setBoardCell, (int i, int j, char piece), (override));
};

class MockMenu : public Menu {
 public:
  MOCK_METHOD(void, startGame, (ReversiGame));
  MOCK_METHOD(void, help, ());
};

class ReversiGameTest: public ::testing::Test {
protected:
 virtual void SetUp() override {
	reversigame_uut = new ReversiGame();
    ::testing::Mock::AllowLeak(&mockBoard);
 }

 virtual void TearDown() override
 {
    delete reversigame_uut;
 }

  ReversiGame *reversigame_uut;

  //mockups
  MockReversiBoard mockBoard;
  MockMenu mockMenu;
};

// Template for comments
//       0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
// 0 A | - | - | - | - | - | - | - | - | 
// 1 B | - | - | - | - | - | - | - | - | 
// 2 C | - | - | - | + | - | - | - | - | 
// 3 D | - | - | + | B | W | - | - | - | 
// 4 E | - | - | - | W | B | + | - | - | 
// 5 F | - | - | - | - | + | - | - | - | 
// 6 G | - | - | - | - | - | - | - | - | 
// 7 H | - | - | - | - | - | - | - | - | 