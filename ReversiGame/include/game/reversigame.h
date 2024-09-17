#pragma once
/************************************************
 * Class ReversiGame 
 ***********************************************/

#include "reversiboard.h"
#include "menu.h"
#include "log.h"

class Player;

class ReversiGame
{
public:
    ReversiGame();

    /**
     * @brief display the menu at the start the game 
     * 
    */
    void startMenu();

    /**
     * @brief chack if there is a winer  
     * 
    */
    virtual void updateGameState();

    /**
     * @brief display the result of the game  
     * 
    */
    void showResult();

    /**
     * @brief open the menu 
     * 
    */
    void openHelpMenu();

    /**
     * \brief Opens the pause menu.
     */
    void openPauseMenu();

    /**
     * @brief check if there is wrong input from the user  
     * 
    */
    void checkCommands();

    /**
     * @brief return the Reversi board  
     * 
    */
    ReversiBoard* getReversiBoard();

    /**
     * @brief return the state of gameOver.
     * gameOver will be set true if one of the players
     * won the game. 
     * 
    */
    virtual bool getGameState(){ return gameOver;}
    
    virtual Player* getUser() { return user; }
    virtual Player* getComputer() { return computer;}
    
    virtual ~ReversiGame();

private:
    bool userTurn; // true: user's turn / false: computer's turn
    bool doubleCheck; // true: one Player has no available moves / false: normal state 
    bool gameOver;
    
    ReversiBoard *reversiboard;
    Menu *menu;
    Player *user;
    Player *computer; 
    
};

