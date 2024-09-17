#include "log.h"
#include "placeholder.h"
#include "reversiboard.h"

void Placeholder::calculatePlaceholderPlacesForPlayer(int i, int j, char playerPiece, ReversiBoard *reversiboard){
    char opponentPiece;

    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined"; //LCOV_EXCL_LINE
        exit(1);
    }
    
    if (i<0 || i>7 || j<0 || j>7)
    {
        LOG(ERROR) << "indices out of scope"; //LCOV_EXCL_LINE
        exit(1);        
    }

    int row = i;
    int col = j;

    if ('B' == playerPiece) {
        opponentPiece = 'W';
    } else if ('W' == playerPiece) {
        opponentPiece = 'B';
    } else {
        LOG(ERROR) << "playerPiece is unknown"; //LCOV_EXCL_LINE
        exit(1);
    }   

    
    /****************************** vertical check *****************************/
    checkVerticalPlaceholder(row, col, opponentPiece, reversiboard);
    /****************************** horizontal check ***************************/
    checkHorizontalPlaceholder(row, col, opponentPiece, reversiboard);
    /****************************** diagonal check *****************************/
    checkDiagonalPlaceholder(row, col, opponentPiece, reversiboard);
}


void Placeholder::setupPlaceholderRules(char player, ReversiBoard *reversiboard){
    
    //for black pieces - for the player
    LOG(INFO) << "**************************** Begin Calculating placeholder places ******************************************************";  //LCOV_EXCL_LINE
    resetPlaceholderPlaces(reversiboard);

    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined";  //LCOV_EXCL_LINE
        exit(1);
    }

    if (player != 'B' && player !='W') {
        LOG(ERROR) << "player is undefined";  //LCOV_EXCL_LINE
        exit(1);
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            if ('B' == reversiboard->getBoardCell(i,j) && 'B' == player) {
                calculatePlaceholderPlacesForPlayer(i, j, 'B', reversiboard);
            } else if ('W' == reversiboard->getBoardCell(i,j) && 'W' == player) {
                calculatePlaceholderPlacesForPlayer(i, j, 'W', reversiboard);
            }
        }
    }
    LOG(INFO) << "**************************** Finished calculating placeholder places ******************************************************"; //LCOV_EXCL_LINE
}


void Placeholder::checkVerticalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *reversiboard) {
    int count = 1;

    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined";  //LCOV_EXCL_LINE
        exit(1);
    }

    if (opponentPiece != 'B' && opponentPiece !='W') {
        LOG(ERROR) << "player is undefined";  //LCOV_EXCL_LINE
        exit(1); 
    }

    if (i<0 || i>7 || j<0 || j>7)
    {
        LOG(ERROR) << "indices out of scope";  //LCOV_EXCL_LINE
        exit(1);        
    }

    //down check
    while(i-count>=0 && reversiboard->getBoardCell(i-count,j) == opponentPiece) {
        LOG(INFO) << "down: count = " << count;  //LCOV_EXCL_LINE
        count++;
    }

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i-count,j) && 
         1 != count && i-count>=0) {
        LOG(INFO) << "placeholder piece at ["<< i-count << "][" << j << "]";   //LCOV_EXCL_LINE
        reversiboard->setBoardCell(i-count,j,'+');
    }

    LOG(INFO) << "checkVerticalPlaceholder : upper check";  //LCOV_EXCL_LINE
    //upper check
    count = 1;
    while(i+count < 8 && reversiboard->getBoardCell(i+count,j) == opponentPiece) {
        LOG(INFO) << "upper: count = " << count; //LCOV_EXCL_LINE
        count++;
    }

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i+count,j) &&
        8 > i+count && 1 != count) {
        LOG(INFO) << "placeholder piece at ["<< i+count << "][" << j << "]"; //LCOV_EXCL_LINE 
        reversiboard->setBoardCell(i+count,j,'+');
    }
}

void Placeholder::checkHorizontalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *reversiboard) {
    //check left side of the stone
    LOG(INFO) << "checkHorizontalPlaceholder : check left side of the placed stone";  //LCOV_EXCL_LINE
    int count = 1;

    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined"; //LCOV_EXCL_LINE
        exit(1);
    }

    if (opponentPiece != 'B' && opponentPiece !='W') {
        LOG(ERROR) << "player is undefined"; //LCOV_EXCL_LINE
        exit(1);
    }

    if (i<0 || i>7 || j<0 || j>7)
    {
        LOG(ERROR) << "indices out of scope"; //LCOV_EXCL_LINE
        exit(1);        
    }

    while(j-count>=0 && reversiboard->getBoardCell(i,j-count) == opponentPiece) {
        count++;
    }

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i,j-count) &&
         1 != count && j-count>=0) {
        LOG(INFO) << "placeholder piece at ["<< i << "][" << j-count << "]"; //LCOV_EXCL_LINE   
        reversiboard->setBoardCell(i,j-count,'+');
    }

    //check right side of the piece
    LOG(INFO) << "checkHorizontalPlaceholder : check right side of the placed stone"; //LCOV_EXCL_LINE
    count = 1;
    while(j+count < 8 && reversiboard->getBoardCell(i,j+count) == opponentPiece) {
        count++;
    }

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i,j+count) &&
        8 > j+count && 1 != count) {
        LOG(INFO) << "placeholder piece at ["<< i << "][" << j+count << "]";  //LCOV_EXCL_LINE
        reversiboard->setBoardCell(i, j+count, '+');
    }
}

void Placeholder::checkDiagonalPlaceholder(int i, int j, char opponentPiece, ReversiBoard *reversiboard) {
    LOG(INFO) << "checkDiagonalPlaceholder : first diagonal '\\'";  //LCOV_EXCL_LINE
    //************ first diagonal '\'
    //check left diagonal side of the stone
    LOG(INFO) << "  checkDiagonalPlaceholder : check left diagonal side of the stone";  //LCOV_EXCL_LINE

    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined";  //LCOV_EXCL_LINE
        exit(1);
    }

    if (opponentPiece != 'B' && opponentPiece !='W') {
        LOG(ERROR) << "player is undefined"; //LCOV_EXCL_LINE
        exit(1);
    }

    if (i<0 || i>7 || j<0 || j>7)
    {
        LOG(ERROR) << "indices out of scope"; //LCOV_EXCL_LINE
        exit(1);        
    }

    int count = 1;
    while(i-count>=0 && j-count>=0 && reversiboard->getBoardCell(i-count, j-count) == opponentPiece) {
        count++;
    }

    LOG(INFO) << "count = " << count; //LCOV_EXCL_LINE

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i-count, j-count) &&
        1 != count && j-count>=0 && i-count>=0) {
        LOG(INFO) << "placeholder piece at ["<< i-count << "][" << j-count << "]";  //LCOV_EXCL_LINE  
        reversiboard->setBoardCell(i-count, j-count, '+');
    }

    //check right diagonal side of the piece
    LOG(INFO) << "  checkDiagonalPlaceholder : check right diagonal side of the stone"; //LCOV_EXCL_LINE
    count = 1;
    while(j+count<=7 &&
          i+count<=7 && 
          reversiboard->getBoardCell(i+count, j+count) == opponentPiece) {
        count++;
    }

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i+count, j+count) &&
        1 != count && j+count<=7 && i+count<=7) {
        LOG(INFO) << "placeholder piece at ["<< i-count << "][" << j+count << "]";    //LCOV_EXCL_LINE
        reversiboard->setBoardCell(i+count, j+count, '+');
    }

    LOG(INFO) << "checkDiagonalPlaceholder : second diagonal '/'"; //LCOV_EXCL_LINE
    //************ second diagonal '/'
    //check left diagonal side of the stone
    LOG(INFO) << "  checkDiagonalPlaceholder : check left diagonal side of the stone"; //LCOV_EXCL_LINE
    count = 1;
    while(j-count>=0 &&
          i+count<=7 && 
          reversiboard->getBoardCell(i+count, j-count) == opponentPiece) {
        count++;
    }

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i+count, j-count) &&
        1 != count && j-count>=0 && i+count<=7) {
        LOG(INFO) << "placeholder piece at ["<< i+count << "][" << j-count << "]";    //LCOV_EXCL_LINE
        reversiboard->setBoardCell(i+count, j-count, '+');
    }

    //check right diagonal side of the piece
    LOG(INFO) << "  checkDiagonalPlaceholder : check right diagonal side of the stone"; //LCOV_EXCL_LINE
    count = 1;
    while(i-count>=0 &&
          j+count<=7 && 
          reversiboard->getBoardCell(i-count, j+count) == opponentPiece) {
        count++;
    }

    // if this square is empty and less than [0][j], then set placeholder in it
    if ('-' == reversiboard->getBoardCell(i-count, j+count) &&
        1 != count && j+count<=7 && i-count>=0) {
        LOG(INFO) << "placeholder piece at ["<< i-count << "][" << j+count << "]";    //LCOV_EXCL_LINE
        //LOG(INFO) << "placeholder piece at ["<< i-count << "][" << j+count << "]";
        reversiboard->setBoardCell(i-count, j+count, '+');
    }
}

void Placeholder::resetPlaceholderPlaces(ReversiBoard *reversiboard){
    LOG(INFO) << "Reset placeholder places"; //LCOV_EXCL_LINE
    
    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined"; //LCOV_EXCL_LINE
        exit(1);
    }
    
    for (int i = 0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if ('+' == reversiboard->getBoardCell(i,j))
                reversiboard->setBoardCell(i,j,'-');
        }
    }
}

Placeholder::~Placeholder()
{
}



