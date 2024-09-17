#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>

using namespace std;
char board[8][8] = {};


void checkVerticalPlaceholder(int i, int j, char opponentPiece) {
    //down check
    cout << "checkVerticalPlaceholder : down check";
    int count = 1;
    while(board[i-count][j] == opponentPiece && 8 != count && i-count>=0) {
        count++;
    }

    if ('W' != board[i-count][j] && 
        'B' != board[i-count][j] &&
        8 > count && 1 != count && i-count>=0) {
        cout << "placeholder piece at ["<< i-count << "][" << j << "]";   
        board[i-count][j] = '+';
    }

    cout << "checkVerticalPlaceholder : upper check";
    //upper check
    count = 1;
    while(board[i+count][j] == opponentPiece && 8 != count) {
        count++;
    }

    if ('W' != board[i+count][j] &&
        'B' != board[i+count][j] &&
        8 > count && 1 != count) {
        cout << "placeholder piece at ["<< i+count << "][" << j << "]";   
        board[i+count][j] = '+';;
    }
}

void checkHorizontalPlaceholder(int i, int j, char opponentPiece) {
    //check left side of the stone
    cout << "checkHorizontalPlaceholder : check left side of the placed stone";
    int count = 1;
    while(j-count>=0 && board[i][j-count] == opponentPiece && 8 != count) {
        count++;
    }

    if ('W' != board[i][j-count] &&
        'B' != board[i][j-count] &&
        8 > count && 1 != count && j-count>=0) {
        cout << "placeholder piece at ["<< i << "][" << j-count << "]";   
        board[i][j-count]='+';
    }

    //check right side of the piece
    cout << "checkHorizontalPlaceholder : check right side of the placed stone";
    count = 1;
    while(board[i][j+count] == opponentPiece && 8 != count) {
        count++;
    }

    if ('W' != board[i][j+count] &&
        'B' != board[i][j+count] &&
        8 > count && 1 != count) {
        cout << "placeholder piece at ["<< i << "][" << j+count << "]";   
        board[i][j+count]='+';
    }
}

void checkDiagonalPlaceholder(int i, int j, char opponentPiece) {
    cout << "checkDiagonalPlaceholder : first diagonal '\'";
    //************ first diagonal '\'
    //check left diagonal side of the stone
    cout << "  checkDiagonalPlaceholder : check left diagonal side of the stone";
    int count = 1;
    while(j-count>=0 && board[i-count][j-count] == opponentPiece && 8 != count) {
        count++;
    }

    if ('W' != board[i-count][j-count] &&
        'B' != board[i-count][j-count] &&
        8 > count && 1 != count && j-count>=0) {
        cout << "placeholder piece at ["<< i-count << "][" << j-count << "]";   
        board[i-count][j-count] = '+';
    }

    //check right diagonal side of the piece
    cout << "  checkDiagonalPlaceholder : check right diagonal side of the stone";
    count = 1;
    while(board[i+count][j+count] == opponentPiece && 8 != count) {
        count++;
    }

    if ('W' != board[i+count][j+count] &&
        'B' != board[i+count][j+count] &&
        8 > count && 1 != count) {
        cout << "placeholder piece at ["<< i-count << "][" << j+count << "]";   
        board[i+count][j+count] = '+'; //TO FIX IN THE REAL CODE
    }

    cout << "checkDiagonalPlaceholder : first diagonal '/'";
    //************ second diagonal '/'
    //check left diagonal side of the stone
    cout << "  checkDiagonalPlaceholder : check left diagonal side of the stone";
    count = 1;
    while(j-count>=0 && board[i+count][j-count] == opponentPiece && 8 != count) {
        count++;
    }

    if ('W' != board[i+count][j-count]  &&
        'B' != board[i+count][j-count] &&
        8 > count && 1 != count && j-count>=0) {
        cout << "placeholder piece at ["<< i+count << "][" << j-count << "]";   
        board[i+count][j-count] = '+';
    }

    //check right diagonal side of the piece
    cout << "  checkDiagonalPlaceholder : check right diagonal side of the stone";
    count = 1;
    while(board[i-count][j+count] == opponentPiece && 8 != count) {
        count++;
    }

    if ('W' != board[i-count][j+count] &&
        'B' != board[i-count][j+count] &&
        8 > count && 1 != count && i-count>=0 ) {
        cout << "placeholder piece at ["<< i-count << "][" << j+count << "]";   
        //cout << "placeholder piece at ["<< i-count << "][" << j+count << "]";
        board[i-count][j+count] = '+';
    }
}

void resetPlaceholderPlaces(){
    cout << "Reset placeholder places";
    for (int i = 0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if ('+' == board[i][j])
                board[i][j] = '-';
        }
    }
}

void calculatePlaceholderPlacesForPlayer(int i, int j, char playerPiece){
    char opponentPiece;
    
    if ('B' == playerPiece) {
        opponentPiece = 'W';
    } else if ('W' == playerPiece) {
        opponentPiece = 'B';
    } else {
        cout << "playerPiece is unknown";
        exit(1);
    }   

    /****************************** vertical check *****************************/
    checkVerticalPlaceholder(i, j, opponentPiece);
    /****************************** horizontal check ***************************/
    checkHorizontalPlaceholder(i, j, opponentPiece);
    /****************************** diagonal check *****************************/
    checkDiagonalPlaceholder(i, j, opponentPiece);
}


void setupPlaceholderRules(char player){    
    //for black pieces - for the player
    cout << "**************************** Begin Calculating placeholder places ******************************************************";
    resetPlaceholderPlaces();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            if ('B' == board[i][j] && 'B' == player) {
                calculatePlaceholderPlacesForPlayer(i, j, 'B');
            } else if ('W' == board[i][j] && 'W' == player) {
                calculatePlaceholderPlacesForPlayer(i, j, 'W');
            }
        }
    }
    cout << "**************************** Finished calculating placeholder places ******************************************************";
}

int main()
{  
    // Use current time as seed for random generator
    srand( static_cast<unsigned int>(time(nullptr))); 

    //get board from data
    std::string fileContentSaved;

    //files to get the input from
    //ifstream file ("data/corners_test.txt");
    //ifstream file ("data/danger_zone.txt");
    //ifstream file ("data/csquare_test.txt");
    ifstream file ("data/random_test.txt");


    if (file.is_open()) {
        std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());  
        //std::cout << fileContent;
        fileContentSaved = fileContent;      
        file.close();
    }

    //std::cout << fileContentSaved;

    int counter = 0;

    //save board in an array TODO
    for (int col=0; col<8; col++)
    {
        for (int row=0; row<8; row++)
        {   
            board[col][row] = fileContentSaved[counter];
            cout << board[col][row] << " ";
            counter++;
        }
        cout << "\n";
        counter++;
    }

    cout << endl;
    //print board
    for (int col=0; col<8; col++)
    {
        for (int row=0; row<8; row++)
        {   
            cout << board[col][row] << " ";
        }
        cout << "\n";
    }

    return 0;
}


/* TODOs
 * sets only [0][0] ; why ?
 */