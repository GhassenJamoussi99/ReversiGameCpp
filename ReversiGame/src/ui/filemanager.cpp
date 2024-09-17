#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include "filemanager.h"
#include "reversigame.h"
#include "player.h"

using namespace std;

void FileManager::save(ReversiGame *game){
    Player *user = game->getUser();
    int num;
    cout << "-- Save Game --\n";
    cout << "Select game save number:\n";
    while(!(cin >> num) || num < 0) {
        cin.clear();
        cin.ignore(16,'\n');
        cout << "You have entered a unsuited input. Enter a positive number again:\n";
    }
    ofstream file ("data/save_file" + std::to_string(num) + ".txt"); 
    if (file.is_open()) {
        bool isUserPlayingBlack = user->getUserColor() == 'B' ? true : false; 
        file << "User is Player Black: " << isUserPlayingBlack << "\n";
        for (int i=0; i<8; i++)
        {
            for (int j=0; j<8; j++)
            {
                file << game->getReversiBoard()->getBoardCell(i,j);
            }
            file << "\n";
        }     
        file.close();
    } else {
        cout << "Unable to open the savefile!\n";
        LOG(ERROR) << "save: unable to write into the savefile";
    }
}

void FileManager::reload(ReversiGame *game){
    int num;
    Player *user = game->getUser();
    Player *computer = game->getComputer();

    cout << "-- Reload Game --\n";
    cout << "Enter game save number to load from:\n";
    while(!(cin >> num) || num < 0) {
        cin.clear();
        cin.ignore(16,'\n');
        cout << "You have entered a unsuited input. Enter a positive number again:\n";
    }
    ifstream file ("data/save_file" + std::to_string(num) + ".txt");
    if (file.is_open()) {
        std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());        
        file.close();
        cout << "\n" << fileContent[22] << "\n"; //22 -> 1 = Black oder 0 = white 
        LOG(INFO) <<  "fileContent[22] = " << fileContent[22];
        if (true == bool(fileContent[22]))
        {
            LOG(INFO) << "filemanager::setUserColor('B')";
            user->setUserColor('B');
            computer->setComputerColor('W');
        } else { 
            LOG(INFO) << "filemanager::setUserColor('W')";
            user->setUserColor('W');
            computer->setComputerColor('B');
        }

        int counter = 24; //fileContent[24] is the first element -> reloadedBoard[0][0]
        for (int col=0; col<8; col++)
	    {
		    for (int row=0; row<8; row++)
		    {   
                game->getReversiBoard()->setBoardCell(col, row, fileContent[counter]);
			    //reloadedBoard[col][row] = fileContent[counter];
                cout << game->getReversiBoard()->getBoardCell(col,row) << " ";
                counter++;
		    }
            cout << "\n";
            counter++;
	    }

    } else {
        cout << "Unable to open the savefile! Try again!\n\n";
        LOG(ERROR) << "reload: unable to read from the savefile";
        this->reload(game);
    }
}

FileManager::FileManager(){
    //char reloadedBoard[8][8];
}