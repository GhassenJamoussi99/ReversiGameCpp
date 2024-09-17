#include <iostream>
#include <fstream>
#include "reversigame.h"
#include "macros.h"
#include "player.h"
#include "menu.h"
#include "user.h"
#include "computer.h"

using namespace std;
extern Menu *menu;

ReversiGame::ReversiGame(){
    LOG(INFO) << "Init game";
    menu = new Menu();
    reversiboard = new ReversiBoard();
    user = new User();
    computer = new Computer();
    doubleCheck = false;
    gameOver = false;
}

void ReversiGame::startMenu(){
    cout << " ____                         _\n"; 
    cout << "|  _ \\ _____   _____ _ __ ___(_)\n";
    cout << "| |_) / _ \\ \\ / / _ \\ '__/ __| |\n";
    cout << "|  _ <  __/\\ V /  __/ |  \\__ \\ |\n";
    cout << "|_| \\_\\___| \\_/ \\___|_|  |___/_|\n";
    cout << "\n";
    cout<<"===================================================== \n";
    cout<<" \t\tGame Start MENU \t \n";
    cout<<"===================================================== \n";
    cout<<" 1. Start a game\n";
    cout<<" 2. Help \n";
    cout<<" 3. Exit \n";

    int choice;
	do
	{
		cout << "Enter your choice (1 / 2 / 3):\n";
		cin >> choice;
		switch (choice)
		{
		case 1: 
            menu->startGame(this); 
            break;
		case 2: 
            menu->help();
            this->startMenu();
            break;;
		case 3: 
            cout << "Goodbye! Until next time...\n\n";
            exit(0);
            break;
		default: 
            cout << "Invalid input! Try again:\n";
            cin.clear();
            cin.ignore(16,'\n');
		}
	} while (choice < 1 || choice > 3);
	
    //TODO: wo gehts weiter????
    //reversiboard->addStandardReversiPieces();
}

void ReversiGame::updateGameState(){
    //cout << "updateGameState";
    LOG(INFO) << "Update game state";
    bool movePossible = false;
    bool boardFull = true;
    int i = 0;
    int j = 0;
    while(movePossible == false && i < 8) {
        if(ReversiGame::reversiboard->getBoardCell(i,j) == '+') {
            movePossible = true;
        }
        if(ReversiGame::reversiboard->getBoardCell(i,j) == '-') {
            boardFull = false;
        }
        if(j==7){
            j=0;
            i++;
        } else {
            j++;
        }
    }

    if(movePossible == true) {
        user->changeTurn();
        LOG(INFO) << "Next player can continue";
        //nextTurn()?  don't we need a function to toggle between the user and the computer as the active player?
    } else if(boardFull == true) {
        this->showResult();
    } else if(doubleCheck == false){
        doubleCheck = true;
        //skipTurn()? alternative: if(currentPlayer == 'W') {nextPlayer = 'W';}
    } else if(doubleCheck == true) {
        LOG(INFO) << "Early end, because no moves available for both players";
        cout << "Both players have no moves available!\n";
        this->showResult();
    } else {
        LOG(ERROR) << "updateGameState: something went wrong";
        std::exit(1);
    }

}

void ReversiGame::showResult(){
    cout << "\n===== The game is finished! =====\n\n";
    gameOver = true;
    int numB = 0;
    int numW = 0;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(ReversiGame::reversiboard->getBoardCell(i,j) == 'W') {numW++;}
            if(ReversiGame::reversiboard->getBoardCell(i,j) == 'B') {numB++;}
        }
    }
    if(numW > numB && user->getUserColor() == 'W') {
        cout << "Congratulations YOU WIN!\n\nNumber of White discs (YOU): " << numW << "\nNumber of Black discs: " << numB << endl;
    } else if(numW > numB && user->getUserColor() == 'B') {
        cout << "GAME OVER\n\nNumber of White discs: " << numW << "\nNumber of Black discs (YOU): " << numB << "\n\nTry better next time ;)\n";
    } else if(numW < numB && user->getUserColor() == 'W') {
        cout << "GAME OVER\n\nNumber of White discs (YOU): " << numW << "\nNumber of Black discs: " << numB << "\n\nTry better next time ;)\n";
    } else if(numW < numB && user->getUserColor() == 'B') {
        cout << "Congratulations YOU WIN!\n\nNumber of White discs: " << numW << "\nNumber of Black discs (YOU): " << numB << endl;
    } else if(numW == numB){
        cout << "WOW! A draw how unexpected!\n\nNumber of White discs: " << numW << "\nNumber of Black discs: " << numB << endl;
    } else {
        LOG(ERROR) << "Something went wrong within showResult()";
        cout << "No winner found?\n";
        std::exit(1);
    }
    this->startMenu();

}

void ReversiGame::openHelpMenu(){ 
    menu->helpMenu(this);
}

void ReversiGame::openPauseMenu(){ 
    menu->pauseGameMenu(this);
}

void ReversiGame::checkCommands(){ //OPTIONAL: Switch case einrichten um alle möglichen Eingaben abzufangen //muss bei jedem default switch aufgerufen werden.
    cout << "checkCommands\n";
}

ReversiBoard* ReversiGame::getReversiBoard(){
    return reversiboard;
}

ReversiGame::~ReversiGame()
{
    SAFE_DELETE(reversiboard);
    SAFE_DELETE(menu);
    SAFE_DELETE(user);
    SAFE_DELETE(computer);
}
