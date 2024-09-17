#pragma once

#include "reversigame.h"

/**
 * \class Player
 *
 * \brief Represents a player in a Reversi game.
 *
 * This class provides functionality for switching turns, setting and getting the colors
 * of the user and computer players, and making a move (implemented in derived classes).
 */
class Player
{
    public:
        /**
         * \brief Constructs a new Player object.
         */
        Player(){};

        /**
         * \brief Switches the current player's turn.
         */
        void changeTurn();

        /**
         * \brief Gets the current player's turn.
         *
         * \return True if it is the user's turn, false if it is the computer's turn.
         */
        virtual bool getUserTurn();

        /**
         * \brief Sets the user's color.
         *
         * \param color The user's color, either 'B' for black or 'W' for white.
         */
        void setUserColor(char color);

        /**
         * \brief Sets the computer's color.
         *
         * \param color The computer's color, either 'B' for black or 'W' for white.
         */
        void setComputerColor(char color);

        /**
         * \brief Gets the user's color.
         *
         * \return The user's color, either 'B' for black or 'W' for white.
         */
        virtual char getUserColor();

        /**
         * \brief Gets the computer's color.
         *
         * \return The computer's color, either 'B' for black or 'W' for white.
         */
        virtual char getComputerColor();

        /**
         * \brief Makes a move for the current player.
         * 
         * This function is implemented in derived classes.
         * 
         * \param game Pointer to the ReversiGame object representing the current state of the game.
         */
        virtual void move([[maybe_unused]] ReversiGame *game){};

        /**
         * \brief Destroys a Player object.
         */
        virtual ~Player(){};

    private: 
       bool userTurn = true; // Stores the current player's turn (true for user, false for computer)
       char userColor; // Stores the user's color
       char computerColor; // Stores the computer's color
};
