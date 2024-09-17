#include <iostream>
#include <fstream>

#include "menu.h"
#include "reversigame.h"
#include "reversiboard.h"
#include "macros.h"
#include "player.h"
#include "log.h"

using namespace std;

Menu::Menu(){
	files = new FileManager();
}

void Menu::startGame(ReversiGame *game)
{
	ReversiBoard *reversiboard = game->getReversiBoard();

	cout << "Choose one of the following:\n";
	cout << " 1. New game\n 2. Load Game\n";
	int num;
	do
	{
		cout << "Enter your choice (1 / 2):\n";
		cin >> num;
		switch (num)
		{
		case 1: 
			this->restartGame(game);
			cout << "\nLet the game begin!\n"; 
            break;
		case 2: 
            files->reload(game);
			cout << "\nLet the game continue!\n";
			reversiboard->updateBoard(game);
            break;
		default: 
			cout << "Invalid input! Try again:\n";
			cin.clear();
        	cin.ignore(16,'\n');
		}
	} while (num < 1 || num > 2);
	
	//ReversiGame();
}

void Menu::restartGame(ReversiGame *game)
{
	Player *user = game->getUser();
    Player *computer = game->getComputer();
	ReversiBoard *reversiboard = game->getReversiBoard();

	cout << "\n===== Welcome! =====\n";
	//game = new ReversiGame();
	//TODO: Funktionsufruf um den Spieler seine Farbe wählen zulassen, ein frisches Board zu erstellen und das Spiel zu beginnen...
	cout << "Choose a colour to play with:\n 1. White\n 2. Black\n";
	int num;
	do
	{
		cout << "Enter your choice (1 / 2):\n";
		cin >> num;
		switch (num)
		{
		case 1: 
			user->setUserColor('W');
			computer->setComputerColor('B');
            break;
		case 2: 
    		user->setUserColor('B');
			computer->setComputerColor('W');
            break;
		default: 
			cout << "Invalid input! Try again:\n";
			cin.clear();
        	cin.ignore(16,'\n');
		}
	} while (num < 1 || num > 2);

	reversiboard->setup(game); 
}

void Menu::pauseGameMenu(ReversiGame *game)
{ 
	cout << "===== Game Is Paused =====\n";
	cout << "Do you want to save your progress?\n 1. Save progress\n 2. Restart\n 3. Go back\n";
	int num;
	do
	{
		cout << "Enter your choice (1 / 2):\n";
		cin >> num;
		switch (num)
		{
		case 1: 
			files->save(game);
            break;
		case 2: 
			system("clear");
            this->restartGame(game);
            break;
		case 3: 
            this->helpMenu(game);
            break;
		default: 
			cout << "Invalid input! Try again:\n";
			cin.clear();
        	cin.ignore(16,'\n');
		}
	} while (num < 1 || num > 2);
     
}

void Menu::helpMenu(ReversiGame *game)
{
	ReversiBoard *reversiboard = game->getReversiBoard();
	cout<<"===================================================== \n";
	cout<<" \t Ingame MENU \t \n";
	cout<<"===================================================== \n";
	cout<<" 1. Continue \n";
	cout<<" 2. Pause\n";
	cout<<" 3. Help \n";
	cout<<" 4. Exit \n";
	cout<<"\n";
	cout<<"\n";


	int choice;
	do
	{
		cout << "Enter your choice (1 / 2 / 3 / 4):\n";
		cin >> choice;
		switch (choice)
		{
		case 1: 
			cout << "\n\n\n\n";
			reversiboard->updateBoard(game);
            break;
		case 2: 
            this->pauseGameMenu(game);
            break;
		case 3: 
            this->help();
			this->helpMenu(game);
            break;
		case 4: 
            this->exitGame(game);
            break;
		default: 
            cout << "Invalid input! Try again:\n";
            cin.clear();
            cin.ignore(16,'\n');
		}
	} while (choice < 1 || choice > 4);

}

void Menu::help()
{   cout<<"===================================================== \n";
    cout<<" \t Help\n";
    cout<<"===================================================== \n";
	cout<<"You need to decide which disk color to play with -W- or -B-\n";
	cout<<"The non-valid moves are shown as an '-' on the board.\n";
	cout<<"The allowed valid moves are shown as an '+' on the board\n";
	cout<<"Please give the input as coordinates with a character between A & H for the row and a number between 1 & 8 for the column (i.e. 'H8') to make his move\n";
	cout<<"Type \"menu\" to see the options ingame.\n";
	cout<<"Choose \"pause\" to get the option to save the game.\n\n";
	//cout<<"To stop and save the game at any point enter the input('SS'/'ss').\n";
	//cout<<"To start a new game enter (s) or to reload a game enter (r)\n";
	
	
}

void Menu::exitGame(ReversiGame *game)
{
	cout << "Do you want to quit?\n 1. YES, I want to Save and Exit\n 2. NO, take me back\n 3. Exit without saving \n";
	int num;
	do
	{
		cout << "Enter your choice (1 / 2 / 3):\n";
		cin >> num;
		switch (num)
		{
		case 1: 
			files->save(game);
			cout << "\nGoodbye!\n"; 
			std::exit(0);
            break;
		case 2: 
            this->helpMenu(game);
            break;
		case 3: 
			cout << "\nGoodbye!\n"; 
			std::exit(0);
            break;	
		default: 
			cout << "Invalid input! Try again:\n";
			cin.clear();
        	cin.ignore(16,'\n');
		}
	} while (num < 1 || num > 2);
}


Menu::~Menu(){
    SAFE_DELETE(files);
}
