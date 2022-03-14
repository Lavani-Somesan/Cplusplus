#include "layout.h"
#include "game.h"


//Default Parameter
Layout::Layout()
{


}


//Function that calls setFileName function and then reads the file which contains
//the mines and puts them into a four by four array
void Layout::createGameBoard(char gameBoard[ROW][COLUMN], int row, int column)
{
	ifstream inFS;
	string fileName;	

	//Sets file name from Game class and then opens file
	fileName = gameObj.getFileName();

	inFS.open(fileName.c_str());

	//Copies file into 2D array to make game board
	for(int i=0; i < row; i++)
	{
	for(int j=0; j < column; j++)
	{
		inFS.get(gameBoard[i][j]);
	}
	}
	
	inFS.close();

	//Calls fillWithCells Function to fill gameBoard 2D array
	fillWithCells(gameBoard, row, column);
}


//Function that populates 2d array with characters that aren't mines
void Layout::fillWithCells(char gameBoard[ROW][COLUMN], int row, int column)
{
	int count = 0;

	//Goes through each cell in the 2d array and assigns num of mines
	for(int i=0; i < row; i++)
        {
        for(int j=0; j < column; j++)
        {
		//If there is no mines in the cell then it will call getMineCount from
		//Cell class and assign the number of mines adjacent to that cell.
		if(cell.isMine(gameBoard, i, j) != true)
		{
			count = cell.getMineCount(gameBoard, i, j);
			gameBoard[i][j] = '0' + count;
		}
        }
        }

	//For any cell that is not a number or mine it will fill with ~ character 
	for(int i=0; i < row; i++)
        {
        for(int j=0; j < column; j++)
        {
        	if(gameBoard[i][j] == '0')
		{
			gameBoard[i][j] = '~';
		}
        }
        }
}


//Function that expands the adjacent cells of the cell that continas "~" character which the user clicked on
void Layout::expandClick(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	//Expands North of Cell
	cell.expandCell(userGameBoard, gameBoard, rowPos - 1, columnPos);
	//Expands North East of Cell
	cell.expandCell(userGameBoard, gameBoard, rowPos - 1, columnPos + 1);
	//Expands East of Cell
	cell.expandCell(userGameBoard, gameBoard, rowPos, columnPos + 1);
	//Expands South East of Cell	
	cell.expandCell(userGameBoard, gameBoard, rowPos + 1, columnPos + 1);
	//Expands South of Cell
	cell.expandCell(userGameBoard, gameBoard, rowPos + 1, columnPos);
	//Expands South West of Cell
	cell.expandCell(userGameBoard, gameBoard, rowPos + 1, columnPos - 1);
	//Expands West of Cell
	cell.expandCell(userGameBoard, gameBoard, rowPos, columnPos - 1);
	//Expands North West of Cell
	cell.expandCell(userGameBoard, gameBoard, rowPos - 1, columnPos - 1);
}


//Function that calls Cell click function and then determines what the user clicked on.
//Depneding on what the user clicked on the function will correctly display what they did.
int Layout::click(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	int outcome = 0;  //Holds outcome of what the cell is

	//Calls Cell click funciton and then assigns the return value to the outcome
	outcome = cell.click(userGameBoard, gameBoard, rowPos, columnPos);

	
	switch(outcome)
	{
	//If Mine was clicked then it explodes which shows the real layout of the gameboard
	//then its game over
	case 1:
		explode(userGameBoard, gameBoard);
		showLayout(userGameBoard);
		return 1;
		break;

	//If special character is clicked then goes to expandClick function and then prints layout
	case 2:
		expandClick(userGameBoard, gameBoard, rowPos, columnPos);
		userGameBoard[rowPos][columnPos] = gameBoard[rowPos][columnPos];
		showLayout(userGameBoard);
		break;

	//If a number was clicked then the number will be shown
	case 3:
		userGameBoard[rowPos][columnPos] = gameBoard[rowPos][columnPos];
		showLayout(userGameBoard);	
		break;
	case 4:
		cout << "Invalid Move. " << endl << endl; 	
		break;
	}

	return 0;
}


//Function that calls the Cell toggleFlag function and determines whether a flag can be
//placed on the specified cell or not
void Layout::flag(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	if(cell.isCleared(userGameBoard, gameBoard, rowPos, columnPos) != true)
        {
		cell.toggleFlag(userGameBoard, gameBoard, rowPos, columnPos);

		showLayout(userGameBoard);
	}
	else
	{
		cout << "Cannot place a flag there. " << endl << endl;
	}
}


//Function that is used if user clicks on a mine. The original board will be displayed.
void Layout::explode(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN])
{
	for(int i =0; i < ROW; i++)
	{
	for(int j = 0; j < COLUMN; j++)
	{
		userGameBoard[i][j] = gameBoard[i][j];
	}
	}
}


//Function that checks to see if the user game board matches the original game board.
//If so, then the board is all clear which returns a true. If not, then returns a false.
bool Layout::allClear(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN])
{
	int breakLoop = 0;

	for(int i = 0; i < ROW; i++)
	{
	for(int j = 0; j < COLUMN; j++)
	{
		//Breaks out of inner loop if the cells don't match on both game boards
		if(cell.clear(userGameBoard, gameBoard, i, j) != true)
		{
			breakLoop = 1;
			break;
		}	
	}
	//breaks out of outer loop
	if(breakLoop == 1)
	{
		break;
	}
	}
	
	//If the loop was not broken then the game boards successfully matched
	if(breakLoop != 1)
	{
		return true;
	}

	return false;
}



//Function that shows the Layout of the users gameboard
void Layout::showLayout(char userGameBoard[ROW][COLUMN])
{
	cout << endl;
	cout << "    ";

	for(int i =0; i < ROW; i++)
	{
	cout << i << "   ";
	}
	
	cout << endl;
	
	for(int i = 0; i < ROW; i++)
	{
	cout << "  +---+---+---+---+  " << endl;
	cout << i << " | ";

	for(int j = 0; j < COLUMN; j++)
	{
	cout << userGameBoard[i][j] << " | ";
	}

	cout << endl;
	
	if(i == ROW - 1)
	{
	cout << "  +---+---+---+---+  " << endl;
	}
	}

	cout << endl;
}

