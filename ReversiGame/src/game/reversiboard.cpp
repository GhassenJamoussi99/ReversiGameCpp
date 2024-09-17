#include <iostream>

//project includes
#include "reversiboard.h"
#include "reversigame.h"
#include "placeholder.h"
#include "discs.h"
#include "user.h"
#include "computer.h"
#include "player.h"

//external includes
#include "macros.h"
#include "log.h"

using namespace std;

ReversiBoard::ReversiBoard(){
    placeholder = new Placeholder();
    discs = new Discs();
}

ReversiBoard::ReversiBoard(Discs *m_discs, Placeholder *m_placeholder) : discs(m_discs), placeholder(m_placeholder) {
}

void ReversiBoard::setupSpaceBoard()
{
    this->cleanBoard();
    
    // Sets the starting positions
    board[4][4] = 'B'; //black
    board[3][3] = 'B';
    board[3][4] = 'W'; //white
    board[4][3] = 'W';
}

void ReversiBoard::cleanBoard()
{
    LOG(INFO) << "Init board";
    for (int i = 0; i<8; i++) {
        for (int j=0; j<8; j++) {
            board[i][j] = '-';
        }
    }
}


void ReversiBoard::setupBorderBoard()
{
#ifndef UNITTEST	
    system("clear");
#endif
    
    cout << " ____                         _\n"; 
    cout << "|  _ \\ _____   _____ _ __ ___(_)\n";
    cout << "| |_) / _ \\ \\ / / _ \\ '__/ __| |\n";
    cout << "|  _ <  __/\\ V /  __/ |  \\__ \\ |\n";
    cout << "|_| \\_\\___| \\_/ \\___|_|  |___/_|\n";
    cout << "\n";
    cout << "    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    char alpha = 'A';
    for (int i=0; i<8; i++)
    {
        cout << alpha++ << " | ";
        for (int j=0; j<8; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n";
    }
}

void ReversiBoard::updateBoard(ReversiGame *game)
{
    if (game == NULL)
    {
        LOG(ERROR) << "game is undefined";
        exit(1);
    }

    Player *user = game->getUser();
    Player *computer = game->getComputer();

    LOG(INFO) << "Update Board";
    
    //Always set placeholders for users only.
    //For computer it's just internal placeholders that the user cannot see
    //placeholder->setupPlaceholderRules(user->getUserColor());
    //this->setupBorderBoard();

    //while (1)
    if (true == user->getUserTurn()){
        LOG(INFO) << "Setup placeholder for user(" << user->getUserColor() << ") ";
        LOGCFG.ENABLE = false;
        placeholder->setupPlaceholderRules(user->getUserColor(), this);
        LOGCFG.ENABLE = true;
#ifndef UNITTEST	
        system("clear");
        this->setupBorderBoard();
#endif    
        user->move(game);
    } else if (false == user->getUserTurn()) {
        LOG(INFO) << "Setup placeholder for computer(" << computer->getComputerColor() << ") ";
        //LOGCFG.ENABLE = false;
        placeholder->setupPlaceholderRules(computer->getComputerColor(), this);
        //LOGCFG.ENABLE = true;
        LOG(INFO) << "computer->move()";
        computer->move(game);
    }

    //gamestate.
    game->updateGameState();
    if (false == game->getGameState())
        this->updateBoard(game);
}
//Needs to be cleaned

void ReversiBoard::setup(ReversiGame *game){
    if (game == NULL)
    {
        LOG(ERROR) << "game is undefined";
        exit(1);
    }

    Player *user = game->getUser();
    LOG(INFO) << "Init Reversi Pieces";
    this->setupSpaceBoard();
    LOG(INFO) << "Init discs and placeholders";
    placeholder->setupPlaceholderRules(user->getUserColor(), this);
    this->updateBoard(game);
}

void ReversiBoard::setBoardCell(int i, int j, char piece){
    board[i][j] = piece;
}

char ReversiBoard::getBoardCell(int i, int j){
    return board[i][j];
}

void ReversiBoard::setupDiscRulesForComputer(int i, int j, ReversiGame *game) {
    if (game == NULL)
    {
        LOG(ERROR) << "game is undefined";
        exit(1);
    }

    if (i<0 || i>7 || j<0 || j>7)
    {
        LOG(ERROR) << "indices out of scope";
        exit(1);        
    }

    Player *computer = game->getComputer();
    discs->setupDiscsRules(i,j, computer->getComputerColor(), this);
}

void ReversiBoard::setupDiscRulesForUser(int i, int j, ReversiGame *game) {
    if (game == NULL)
    {

        LOG(ERROR) << "game is undefined";
        exit(1);
    }

    if (i<0 || i>7 || j<0 || j>7)
    {
        LOG(ERROR) << "indices out of scope";
        exit(1);        
    }
    
    Player *user = game->getUser();
    discs->setupDiscsRules(i,j, user->getUserColor(), this);
}

ReversiBoard::~ReversiBoard(){
    SAFE_DELETE(placeholder);
    SAFE_DELETE(discs);
}
