#pragma once
#include <memory>

/************************************************
 * Class ReversiBoard 
 ***********************************************/

class Placeholder;
class Discs;
class ReversiGame;

class ReversiBoard
{
public:
    ReversiBoard();

    /**
     * @brief Construct a new Reversi Board object for unit tests.
     * 
     * Instantiating objects directly in the constructor as shown in the following 
     * code can make it more difficult to write unit tests for 
     * the ReversiBoard class.
     * 
     * @param discs 
     * @param placeholder 
     */
    ReversiBoard(Discs *m_discs, Placeholder *m_placeholder);
   
    /**
     *   
     * SpaceBoard the Array where the pieces can be placed on it. 
     * 
    */
    void setupSpaceBoard();

    /**
     *   
     * BorderBoard the Array where the Border of ReversiBoard will be designed. 
     * 
    */
    void setupBorderBoard();

    /**
     *   
     * Border will be cleaned. 
     * 
    */
    void cleanBoard();

    /**
     * @brief the Board will be updated. 
     * 
    */
    void updateBoard(ReversiGame *game);  

    /**
     * @brief initial of standard Board.  
     * 
    */  
    void setup(ReversiGame * game);

    /**
     * @brief  get the current piece on the position [row,col]
     * @param i row position on the Array
     * @param j col position on the Array
     * 
    */
    virtual char getBoardCell(int i, int j);

    /**
     * @brief place the  disc on the Board  
     * @param i row position on the Array
     * @param j position on the Array
     * @param piece is the color of Piece for the Player 
     * 
    */
    virtual void setBoardCell(int i, int j, char piece);

    //not clean: to refactor
    void setupDiscRulesForComputer(int i, int j, ReversiGame *game);
    void setupDiscRulesForUser(int i, int j, ReversiGame *game);

    char getUserColor(ReversiGame *game);
    char getComputerColor(ReversiGame *game);

    //void flipPieces(int i, int j, char playerPiece);
    //void placeDisc();// for testing purposes
   virtual ~ReversiBoard();

private:
    bool trigTurn = false; //for debugging purposes;
    char board[8][8];
    Discs *discs;
    Placeholder *placeholder;
};