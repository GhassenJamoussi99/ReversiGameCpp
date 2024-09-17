//extern includes
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "log.h"
#include "macros.h"

//project includes
#include "reversiboard.h"
#include "reversigame.h"
#include "user.h"
#include "player.h"
#include "computer.h"
#include "discs.h"
#include "placeholder.h"

using ::testing::_;
using ::testing::Return;

class MockReversiGame : public ReversiGame {
 public:
  MOCK_METHOD(Player*, getUser, (), (override));
  MOCK_METHOD(Player*, getComputer, (), (override));  
  MOCK_METHOD(void, updateGameState, (), (override));  
  MOCK_METHOD(bool, getGameState, (), (override)); 
};

class MockPlayer : public Player {
 public:
  MOCK_METHOD(char, getUserColor, (), (override));
  MOCK_METHOD(char, getComputerColor, (), (override));  
  MOCK_METHOD(void, move, (ReversiGame *game), (override));  
  MOCK_METHOD(bool, getUserTurn, (), (override));   
};

class MockDiscs : public Discs {
 public:
  MOCK_METHOD(void, setupDiscsRules, (int i, int j, char playerPiece , ReversiBoard* reversiboard), (override));
};

class MockPlaceholder : public Placeholder {
 public:
  MOCK_METHOD(void, setupPlaceholderRules, (char playerPiece , ReversiBoard* reversiboard), (override));
};

class ReversiBoardTest: public ::testing::Test {
protected:
 virtual void SetUp() override {
   ::testing::Mock::AllowLeak(&mockPlayer);
   ::testing::Mock::AllowLeak(&mockReversiGame); 
   mockDiscs = new MockDiscs();
   mockPlaceholder = new MockPlaceholder();
   reversiboard_uut = new ReversiBoard(mockDiscs, mockPlaceholder);
 }

 virtual void TearDown() override
 {
   delete reversiboard_uut;
   //The others will be deleted in the destructor of reversiboard
 }

  ReversiBoard *reversiboard_uut;

  //mockups
  MockPlayer mockPlayer;
  MockReversiGame mockReversiGame;
  MockDiscs *mockDiscs;
  MockPlaceholder *mockPlaceholder;
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

