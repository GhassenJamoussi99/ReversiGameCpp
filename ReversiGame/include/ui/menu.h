#pragma once

#include "filemanager.h"

/**
 * \class Menu
 *
 * @brief Represents the menu of a Reversi game.
 *
 * This class provides the functionality for starting a new game, 
 * restarting the current game, pausing the game, displaying help information, 
 * and exiting the game. It also includes a private member variable, files, 
 * which is a pointer to a FileManager object.
 */
class Menu 
{
public:
    /**
     * @brief Constructs a new Menu object.
     */
    Menu();

    /**
     * @brief Starts a new game.
     * 
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void startGame(ReversiGame *game);

     /**
     * @brief Restarts the current game with a new game.
     * 
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void restartGame(ReversiGame *game);

    /**
     * @brief Pauses the current game.
     * 
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void pauseGameMenu(ReversiGame *game);

    /**
     * @brief Displays help menu.
     * 
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void helpMenu(ReversiGame *game);

     /**
     * @brief Displays help information for how to play the game.
     */   
    void help();

    /**
     * @brief Exits the current game.
     * 
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void exitGame(ReversiGame *game);
    
    /**
     * @brief Destroys a Menu object.
     */
    ~Menu();

private:
    FileManager *files;
};
