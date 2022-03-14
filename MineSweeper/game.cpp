#include "game.h"
#include "layout.h"

//Declares Layout Object outside of functions so it can be used throughout entire class
Layout layout;


//Default Constructor
Game::Game()
{

}


//Function that begins the game, controls all operations of the
//game by calling different functions, and can end the game.
void Game::playGame()
{
	int outcome = 0;  //Holds numerical outcome of if game is over or not
	char userChoice;  //Holds User's choice for move function
	int userRowNum;  //Hold's User inputted row number for move function
	int userColumnNum;  //Hold's User inputted column number for move function
	
	
	//Populates userGameBoard with empty chars
	for(int i = 0; i < ROW; i++)
        {
        for(int j = 0; j < COLUMN; j++)
        {
		userGameBoard[i][j] = ' ';
        }
        }

	//Create 2D array from user File
	layout.createGameBoard(gameBoard, ROW, COLUMN);

	//Prints User's Board
	layout.showLayout(userGameBoard);


	//Game will keep playing until user clicks on mine or clears the booard
	while(isGameOver(outcome) == false)
	{

		cout << "Choose your Next Move (c or f) and Cell, e.g. c 0 3 to click row zero column 3: " << endl;
		cin >> userChoice >> userRowNum >> userColumnNum;
	
		//Validates that userChoice has to be a c or an f
		while(tolower(userChoice) != 'c' && tolower(userChoice) != 'f')
		{
			cout << "Invalid move. Please enter your next move: " << endl;
                	cin >> userChoice  >> userRowNum >> userColumnNum;
		}

		//Gets the numberical outcome of the move and then tests it to see if the move
		//caused a game over
		outcome = move(userChoice, userRowNum, userColumnNum);	
		isGameOver(outcome);
	}
}


//Function that controls the user's movement by calling the click function
//or the flag function
int Game::move(char userChoice, int userRowNum, int userColumnNum)
{

	int outcome = 0;

        if(tolower(userChoice) == 'c')
        {
                outcome = layout.click(userGameBoard, gameBoard, userRowNum, userColumnNum);
		return outcome;
        }

        else if(tolower(userChoice) == 'f')
        {
		layout.flag(userGameBoard, gameBoard, userRowNum, userColumnNum);

        }

	return 0;
}


//Function that determines if the game is over. Either by 
//the user clicking on a mine or the user clears the board.
bool Game::isGameOver(int outcome)
{
	int count = 0;
	
	if(outcome == 1)
	{
		++count;
		if(count == 1)
		{
		cout << "GAME OVER!" << endl;
		}
	
		return true;
	}

	else if(layout.allClear(userGameBoard, gameBoard) == true)
	{
		++count;
                if(count == 1)
                {
                cout << "CONGRAGULATIONS! YOU WON!!" << endl;
                }

		return true;
	}

	return false;
}


//Function that Sets the File Name that contains info on the mine placement
void Game::setFileName(string fileName)
{
	ifstream inFS;

        inFS.open(fileName.c_str());

        if(!inFS.is_open())
        {
		inFS.close();
        }
	
	else
	{
		this->fileName = fileName;
	}

        inFS.close();

}


//Function that determines if the file name given by user is valid
bool Game::isValidFileName()
{
	ifstream inFS;
	
	inFS.open(fileName.c_str());

	if(!inFS.is_open())
	{
		inFS.close();
		return false;
	}
	
	inFS.close();
	return true;

}


//Function that gets/sets the file name of the mine layout
string Game::getFileName()
{
	cout << "Please Enter a File Name with the Minefield Information: " << endl;
	cin >> fileName;

        setFileName(fileName);

        while(isValidFileName() == false)
        {
                cout << "Please Enter a File Name with the Minefield Information: " << endl;
                cin >> fileName;

                setFileName(fileName);
        }

	return fileName;		
}
