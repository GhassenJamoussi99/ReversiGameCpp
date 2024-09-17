#pragma once

#include "player.h"

/**
 * \class User
 *
 * \brief Represents a human player in a Reversi game.
 *
 * This class is derived from the Player class and implements the move() function, 
 * which allows the user to make a move by selecting a position on the board. 
 * It also includes a chooseColor() function that allows the user to choose which 
 * color they want to play as.
 */
class User : public Player
{
public:
    /**
     * \brief Constructs a new User object.
     */
    User();

    /**
     * \brief Allows the user to choose which color they want to play as.
     */
    void chooseColor();

    /**
     * \brief Allows the user to make a move by selecting a position on the board.
     * 
     * \param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void move(ReversiGame *game) override;

    /**
     * \brief Destroys a User object.
     */
    ~User();
};
