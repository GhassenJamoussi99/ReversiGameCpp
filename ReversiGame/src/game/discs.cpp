#include "discs.h"
#include "reversiboard.h"
#include "log.h"

void Discs::setupDiscsRules(int i, int j, char playerPiece, ReversiBoard *reversiboard){
    char opponentPiece;

    if (i<0 || i>7 || j<0 || j>7)
    {
        LOG(ERROR) << "indices out of scope";
        exit(1);        
    }

    int row = i;
    int col = j;

    if ('B' == playerPiece)
    {
        opponentPiece = 'W';
    } else if ('W' == playerPiece) {
        opponentPiece = 'B';
    } else {
        LOG(ERROR) << "playerPiece is unknown";
        exit(1);
    }


    LOG(INFO) << "**************** Checking discs to flip ****************";
    /****************************** vertical check *****************************/
    this->checkVerticalDiscs(row, col, playerPiece, opponentPiece, reversiboard);
    /****************************** horizontal check ***************************/
    this->checkHorizontalDiscs(row, col, playerPiece, opponentPiece, reversiboard);
    /****************************** diagonal check *****************************/
    this->checkDiagonalDiscs(row, col, playerPiece, opponentPiece, reversiboard);
    /***************************************************************************/
    LOG(INFO) << "**************** Finished flipping the discs ****************";

}


void Discs::checkVerticalDiscs(int row, int col, char playerPiece, char opponentPiece, ReversiBoard *reversiboard) {
    
    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined";
        exit(1);
    }

    if (playerPiece != 'B' && playerPiece !='W') {
        LOG(ERROR) << "playerPiece is undefined";
        exit(1);
    }

    if (opponentPiece != 'B' && opponentPiece !='W') {
        LOG(ERROR) << "opponentPiece is undefined";
        exit(1);
    }

    if (row<0 || row>8 || col<0 || col>7)
    {
        LOG(ERROR) << "indices out of scope";
        exit(1);        
    }

    //upper check
    int count = 1;
    while(reversiboard->getBoardCell(row-count,col) == opponentPiece && 8 != count && row-count>=0) {
        count++;
    }

    if (reversiboard->getBoardCell(row-count,col)== playerPiece &&
        8 > count && 1 != count && row-count>=0) {

        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row-i, col, playerPiece);

        }
    }

    //down check
    count = 1;
    while(reversiboard->getBoardCell(row+count, col) == opponentPiece && 8 != count) {
        count++;
    }

    if (reversiboard->getBoardCell(row+count, col)== playerPiece &&
        8 > count && 1 != count) {
        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row+i, col, playerPiece);
        }
    }
}

void Discs::checkHorizontalDiscs(int row, int col, char playerPiece, char opponentPiece, ReversiBoard *reversiboard) {
    
    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined";
        exit(1);
    }

    if (playerPiece != 'B' && playerPiece !='W') {
        LOG(ERROR) << "playerPiece is undefined";
        exit(1);
    }

    if (opponentPiece != 'B' && opponentPiece !='W') {
        LOG(ERROR) << "opponentPiece is undefined";
        exit(1);
    }

    if (row<0 || row>8 || col<0 || col>7)
    {
        LOG(ERROR) << "indices out of scope";
        exit(1);        
    }

    //left check
    int count = 1;
    while(reversiboard->getBoardCell(row, col-count) == opponentPiece && 8 != count && col-count>=0) {
        count++;
    }

    if (reversiboard->getBoardCell(row, col-count)== playerPiece &&
        8 > count && 1 != count && col-count>=0) {

        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row, col-i, playerPiece);
        }
    }

    //right check
    count = 1;
    while(reversiboard->getBoardCell(row, col+count) == opponentPiece && 8 != count) {
        count++;
    }

    if (reversiboard->getBoardCell(row, col+count)== playerPiece &&
        8 > count && 1 != count) {
        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row, col+i, playerPiece);
        }
    }
}

void Discs::checkDiagonalDiscs(int row, int col, char playerPiece, char opponentPiece, ReversiBoard *reversiboard){
    if (reversiboard == NULL)
    {
        LOG(ERROR) << "reversiboard is undefined";
        exit(1);
    }

    if (playerPiece != 'B' && playerPiece !='W') {
        LOG(ERROR) << "playerPiece is undefined";
        exit(1);
    }

    if (opponentPiece != 'B' && opponentPiece !='W') {
        LOG(ERROR) << "opponentPiece is undefined";
        exit(1);
    }
    
    if (row<0 || row>8 || col<0 || col>7)
    {
        LOG(ERROR) << "indices out of scope";
        exit(1);        
    }

    //************ first diagonal '\'
    //check left diagonal side of the stone
    int count = 1;
    while(reversiboard->getBoardCell(row-count, col-count) == opponentPiece && 8 != count && col-count>=0 && row-count>=0) {
        count++;
    }

    if (reversiboard->getBoardCell(row-count, col-count)== playerPiece &&
        8 > count && 1 != count && col-count>=0 && row-count>=0) {

        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row-i, col-i, playerPiece);
        }
    }

    //check right diagonal side of the stone
    count = 1;
    while(reversiboard->getBoardCell(row+count, col+count) == opponentPiece && 8 != count) {
        count++;
    }

    if (reversiboard->getBoardCell(row+count, col+count)== playerPiece &&
        8 > count && 1 != count && col+count<8) {
        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row+i, col+i, playerPiece);
        }
    }


    //************ second diagonal '/'
    //check left diagonal side of the stone
    count = 1;
    while(reversiboard->getBoardCell(row+count, col-count) == opponentPiece && 8 != count) {
        count++;
    }

    if (reversiboard->getBoardCell(row+count, col-count)== playerPiece &&
        8 > count && 1 != count && col-count>=0 && row+count<8) {
        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row+i, col-i, playerPiece);
        }
    }

    //check right diagonal side of the stone
    count = 1;
    while(reversiboard->getBoardCell(row-count, col+count) == opponentPiece && 8 != count && row-count>=0 && col+count<8) {
        count++;
    }

    if (reversiboard->getBoardCell(row-count, col+count)== playerPiece &&
        8 > count && 1 != count && row-count>=0 && col+count<8) {

        for (int i = 1; i<count;i++)
        {
            reversiboard->setBoardCell(row-i, col+i, playerPiece);
        }
    }
    /***************************************************************************/
}