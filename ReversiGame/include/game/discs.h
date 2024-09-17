/**
 * \class Discs
 * \brief A class for handling the rules and logic for placing discs on a Reversi board.
 */

class ReversiBoard;

class Discs
{
public:
    /**
     * \brief Default constructor for the Discs class.
     */
    Discs(){};
    
    /**
     * \brief Method for setting up the rules for placing a disc on the board.
     * 
     * \param i The row position of the disc being placed.
     * \param j The column position of the disc being placed.
     * \param playerPiece The character representation of the disc being placed.
     * \param reversiboard A pointer to the ReversiBoard object the disc is being placed on.
     */
    virtual void setupDiscsRules(int i, int j, char playerPiece, ReversiBoard *reversiboard);

    /**
     * \brief Method for checking the vertical positions of a disc on a Reversi board.
     * 
     * \param row The row position of the disc being checked.
     * \param col The column position of the disc being checked.
     * \param playerPiece The character representation of the disc being checked.
     * \param opponentPiece The character representation of the opponent's disc (the opposite of playerPiece).
     * \param reversiboard A pointer to the ReversiBoard object the disc is being placed on.
     */
    void checkVerticalDiscs(int row, int col, char playerPiece, char opponentPiece, ReversiBoard *reversiboard);

    /**
     * \brief Method for checking the horizontal positions of a disc on a Reversi board.
     * 
     * \param i The row position of the disc being checked.
     * \param j The column position of the disc being checked.
     * \param playerPiece The character representation of the disc being checked.
     * \param opponentPiece The character representation of the opponent's disc (the opposite of playerPiece).
     * \param reversiboard A pointer to the ReversiBoard object the disc is being placed on.
     */
    void checkHorizontalDiscs(int i, int j, char playerPiece, char opponentPiece, ReversiBoard *reversiboard);

    /**
     * \brief Method for checking the diagonal positions of a disc on a Reversi board.
     * 
     * \param i The row position of the disc being checked.
     * \param j The column position of the disc being checked.
     * \param playerPiece The character representation of the disc being checked.
     * \param opponentPiece The character representation of the opponent's disc (the opposite of playerPiece).
     * \param reversiboard A pointer to the ReversiBoard object the disc is being placed on.
     */
    void checkDiagonalDiscs(int i, int j, char playerPiece, char opponentPiece, ReversiBoard *reversiboard);
    
    /**
     * \brief Virtual destructor for the Discs class.
     */
    virtual ~Discs(){};
};
