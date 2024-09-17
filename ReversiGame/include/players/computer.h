#pragma once
#include "player.h"
#include <vector>

/**
 * \class Computer
 *
 * @brief Represents the computer player in a Reversi game.
 *
 * This class is derived from the Player class and implements the move() function, which represents 
 * the computer's decision-making process when it's its turn to play. Additionally, this class 
 * includes several helper functions that assist the computer in making its move: cornersRules(), 
 * dangerZoneRules(), isolatedCSquareRules(), and randomRules().
 *
 */
class Computer: public Player
{
public:
    /**
     * @brief Constructs a new Computer object.
     */
    Computer(){};

    /**
     * @brief Makes a move for the computer based on the current state of the game.
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void move(ReversiGame *game);

    /**
     * @brief Tries to find a valid move that would allow the computer to capture a corner square.
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void cornersRules(ReversiGame *game);

    /**
     * @brief Tries to find a valid move that would allow the computer to capture a square in the "danger zone" (i.e., squares adjacent to a corner square).
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void dangerZoneRules(ReversiGame *game);

    /**
     * @brief Tries to find a valid move that would allow the computer to capture an isolated C-square (a square that is not adjacent to any corner squares).
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void isolatedCSquareRules(ReversiGame *game);

    /**
     * \brief Chooses a random valid move when the computer has no other options.
     * @param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void randomRules(ReversiGame *game);
    
    /**
     * \brief Destroys a Computer object.
     */
    ~Computer(){};

private:
    std::vector<std::pair <int,int>> valid_moves;
    std::vector<std::pair <int,int>> valid_moves_safe;
    bool priority_1 = true;
    bool priority_2 = true;
    bool priority_3 = true;
    bool priority_4 = true;
    bool priority_5 = true;
};


