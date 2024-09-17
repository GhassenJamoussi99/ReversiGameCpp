#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>

using namespace std;

std::vector<std::pair <int,int>> valid_moves_safe;
std::vector<std::pair <int,int>> valid_moves;

bool priority_1 = true;
bool priority_2 = true;
bool priority_3 = true;
bool priority_4 = true;
bool priority_5 = true;


void cornerRules(char board[8][8]) {
 //Priority 1 : Corners
    bool corner_available = false;
    if (priority_1) {
        std::cout << "Checking priority 1\n";

        if (board[0][0] == '+') {
            valid_moves.push_back(std::make_pair(0,0));
            corner_available = true;
        }
        
        if (board[7][0] == '+') {
            valid_moves.push_back(std::make_pair(7,0));
            corner_available = true;

        }
        
        if (board[0][7] == '+') {
            valid_moves.push_back(std::make_pair(0,7));
            corner_available = true;
        }
        
        if (board[7][7] == '+') {
            valid_moves.push_back(std::make_pair(7,7));
            corner_available = true;
        } 

        if (false == corner_available) 
            priority_1 = false;

        if (priority_1){
            cout << "Priority 1 is valid: Corner(s) is/are available\n";
            unsigned int r = (unsigned int) (rand() % valid_moves.size());
            board[valid_moves[r].first][valid_moves[r].second] = 'W';
            std::cout << "Set in current board for computer "<< valid_moves[r].first << " " << valid_moves[r].second << endl;
            //finished
        }
    }

}


void dangerZone(char board[8][8]) {
    valid_moves.clear();
    if (true == priority_2 && false == priority_1) {
        cout << "Checking priority 2\n";
        for(int i = 0; i < 8; i++) {
            if (false == priority_2)
                break;
            for(int j = 0; j < 8; j++)
            {   
                //first horizontal row of danger zone
                //second horizontal row of danger zone
                //first vertical and left row of danger zone
                //second vertical and right row of danger zone
                bool dangerZone = (j >= 1 && j <= 6 && i == 1) |
                                (j >= 1 && j <= 6 && i == 6) ||
                                (i >= 1 && i <= 6 && j == 1) ||
                                (i >= 1 && i <= 6 && j == 6);

                //if there's a piece to place outside the danger zone
                if (false == dangerZone && board[i][j] == '+'){
                    priority_2 = false;
                    break;
                } else if (true == dangerZone && true == priority_2) {
                    //valid moves in the danger zone
                    valid_moves.push_back(std::make_pair(i,j));
                }    
            }
        }
        
        //if there are places only in the danger zone
        if (priority_2) {
            cout << "Priority 2 is valid: Valid moves are only in the danger zone\n";
            //set piece in random place in the danger zone
            unsigned int r = (unsigned int) (rand() % valid_moves.size());
            board[valid_moves[r].first][valid_moves[r].second] = 'W';
            cout << "Set in current board for computer "<< valid_moves[r].first << " " << valid_moves[r].second;
            //finished
        } 
    }

}

void csquareRules(char board[8][8])
{
        /* Priority 3 : Isolated C-Squares Can be a trouble
     Trigger when : 
      - No valid corners are available.
      - Disc can be placed outside the danger zone.   
    */ 
    valid_moves.clear();
    if (true == priority_3 && false == priority_1 && false == priority_2) {
        cout << "Checking priority 3" << endl;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++)
            {
                bool dangerZoneC = (0 == i && 1 == j) || (1 == i && 0 == j) || (6 == i && 0 == j) || (7 == i && 1 == j) |
                                (0 == i && 6 == j) || (1 == i && 7 == j) || (6 == i && 7 == j) || (7 == i && 6 == j);
                
                //if there's a piece outside the danger zone of C-Square
                if (false == dangerZoneC && board[i][j] == '+'){
                    priority_3 = false;
                    break;
                } else if (true == dangerZoneC && true == priority_3) {
                    //valid moves in the danger zone of C-Square
                    valid_moves.push_back(std::make_pair(i,j));
                }    
            }
        }

        //if there are places only in the danger zone of C-Square
        if (priority_3) {
            cout << "Priority 3 is valid: Valid moves are only in the danger zone of C-Square\n";
            //set piece in random place in the danger zone of C-Square
            unsigned int r = (unsigned int) (rand() % valid_moves.size());
            board[valid_moves[r].first][valid_moves[r].second] = 'W';
            cout << "Set in current board for computer "<< valid_moves[r].first << " " << valid_moves[r].second << endl;
            //finished
        }
    }


}


void saveSafeZoneInVector(char board[8][8]) {
    valid_moves_safe.clear();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            bool dangerZoneC = (0 == i && 1 == j) || (1 == i && 0 == j) || 
                                (6 == i && 0 == j) || (7 == i && 1 == j) ||
                                (0 == i && 6 == j) || (1 == i && 7 == j) || 
                                (6 == i && 7 == j) || (7 == i && 6 == j);

            bool dangerZone = (j >= 1 && j <= 6 && i == 1) ||
                                (j >= 1 && j <= 6 && i == 6) ||
                                (i >= 1 && i <= 6 && j == 1) ||
                                (i >= 1 && i <= 6 && j == 6);

            if (false == dangerZoneC && false == dangerZone && board[i][j] == '+'){
                valid_moves_safe.push_back(std::make_pair(i,j));
            }
               
        }
    }
}


void randomRules(char board[8][8]) {
    if (true == priority_4 && false == priority_3 && false == priority_1 && false == priority_2) {
        cout << "Checking priority 4" << endl;
        if (0 == valid_moves_safe.size()){
            priority_4 = false;
        }
    }

    //if there are valid moveis
    if (priority_4) {
        cout << "Priority 4 is valid: Random square" << endl;

        //set piece in random place in the danger zone of C-Square
        unsigned int r = (unsigned int) (rand() % valid_moves_safe.size());
        board[valid_moves_safe[r].first][valid_moves_safe[r].second] = 'W';
        cout << "Set in current board for computer "<< valid_moves_safe[r].first << " " << valid_moves_safe[r].second << endl;
        //finished
    }
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

    char board[8][8] = {};
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

    //see what the computer will do TODO
    cornerRules(board);
    dangerZone(board);
    csquareRules(board);
    saveSafeZoneInVector(board);
    randomRules(board);

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


     if (false == priority_1 && false == priority_2 && 
         false == priority_3 && false == priority_4) {
        cout << "Computer will pass\n";
    }

    return 0;
}


/* TODOs
 * sets only [0][0] ; why ?
 */