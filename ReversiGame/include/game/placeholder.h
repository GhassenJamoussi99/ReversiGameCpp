#pragma once

class ReversiBoard;

/**
 *
 * \class Placeholder
 * \brief Placeholder class for calculating and setting placeholder places in the Reversi reversiboard
 */
class Placeholder
{
public:
 /**
  * @brief Constructor for Placeholder class
  */
 Placeholder(){};

/**
 * @brief Calculates placeholder places for the given player
 * @param player Player for which placeholder places are to be calculated
 * @param reversiboard ReversiBoard object
 */
 virtual void setupPlaceholderRules(char player, ReversiBoard *reversiboard);

/**
 *
 * @brief Resets placeholder places in the given ReversiBoard object
 * @param reversiboard ReversiBoard object
 */
 void resetPlaceholderPlaces(ReversiBoard *reversiboard);
 
/**
 *
 * @brief Check if it is possible to place the disc at the given position for the given player
 * @param i Row position on the board
 * @param j Column position on the board
 * @param playerPiece Color of the player's piece
 * @param reversiboard ReversiBoard object
 */
 void calculatePlaceholderPlacesForPlayer(int i, int j, char playerPiece, ReversiBoard *reversiboard);

/**
 * @brief Check for possible vertical placeholder places for the player
 * @param i Row position on the board
 * @param j Column position on the board
 * @param opponentPiece Color of the opponent player's piece
 * @param reversiboard ReversiBoard object
 */
 void checkVerticalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *reversiboard);

/**
 * @brief Check for possible horizontal placeholder places for the player
 * @param i Row position on the board
 * @param j Column position on the board
 * @param opponentPiece Color of the opponent player's piece
 * @param reversiboard ReversiBoard object
*/
 void checkHorizontalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *reversiboard);

/**
* @brief Check for possible diagonal placeholder places for the player
* @param i Row position on the board
* @param j Column position on the board
* @param opponentPiece Color of the opponent player's piece
* @param reversiboard ReversiBoard object
*/
 void checkDiagonalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *reversiboard);

/**
 * @brief Destructor for Placeholder class
 */
 virtual ~Placeholder();
};