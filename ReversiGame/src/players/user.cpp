//project includes
#include "user.h"
#include "reversigame.h"
#include "reversiboard.h"

//external includes
#include <iostream>
#include <cctype>

#include "macros.h"
#include "log.h"

User::User() {}

void User::chooseColor()
{
  char userColor;
  std::cin >> userColor;
  setUserColor(userColor);
}

void User::move(ReversiGame *game)
{
  ReversiBoard *reversiboard = game->getReversiBoard();
  LOG(INFO) << "User::move()";
  string alpha = "";
  string charBib = "ABCDEFGH";
  string numBib = "01234567";

  if (true == Player::getUserTurn()) {
    std::cout << "\nPossible Inputs:";
    std::cout << "\n - Call menu: hh/HH";
    std::cout << "\n - Pause game: pp/PP";
    std::cout << "\n - Place a disc in a position (upper case char A-H & number 0-7): i.e. B3";
    std::cout << "\nYour Input: ";
    cin.clear();
    cin.ignore(10000,'\n');
    std::cin >> alpha;
    
    if (alpha == "HH" || alpha == "hh") {
      game->openHelpMenu();
    } else if (alpha == "PP" || alpha == "pp") {      
      game->openPauseMenu();
    } else if (charBib.find(alpha[0])!= string::npos && numBib.find(alpha[1])!= string::npos) {
      int i = alpha[0] - 'A';
      int j = alpha[1] - '0';
      LOG(INFO) << "input coordinates with integers = board[" << i << "][" << j << "]";
      LOG(INFO) << "input coordinates with board chars = board[" << alpha[0] << "][" << alpha[1] << "]";

      if (reversiboard->getBoardCell(i, j) != '+') {
        LOG(WARN) << "Forbidden move! Try again!\n";
        cout << "Forbidden move! Try again!\n";
        this->move(game);        
      }

      reversiboard->setBoardCell(i, j, Player::getUserColor());
      reversiboard->setupDiscRulesForUser(i,j, game);
      //Player::changeTurn();
    } else {
      cout << "\nUnknown command! Try again!\n";
      this->move(game);
    }        
  }
}

User::~User() {

}

