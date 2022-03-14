#include "cell.h"
#include "game.h"


//Default Constructor
Cell::Cell()
{


}


//Function that checks if there is a mine in a specific cell which then
//returns true or false
bool Cell::isMine(char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	if(gameBoard[rowPos][columnPos] == '*')
	{
		return true;
	}

	return false;
}


//Function that checks if there is a flag on a specific cell which then 
//returns true or false
bool Cell::isFlag(char userGameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	if(userGameBoard[rowPos][columnPos] == 'f')
	{
		return true;
	}
	
	return false;
}


//Function that checks if a cell number entered by the user or checking
//an adjacent cell is a valid cell which then returns true or false
bool Cell::isValidCell(int rowPos, int columnPos)
{
	if((rowPos >=0 && rowPos < ROW) && (columnPos >= 0 && columnPos < COLUMN))
	{
		return true;
	}
	
	return false;
}


//Function that Gets the Mine Count for an individual cell which checks to see if 
//there are any mines in the adjacent cells.
int Cell::getMineCount(char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	int count = 0;  //Holds number of mines adjacent to a specific cell
	

	//Checking South of Cell to see if there are any mines
	if(isValidCell(rowPos + 1, columnPos) == true)
	{
		if(isMine(gameBoard, rowPos + 1, columnPos) == true)
		{
			count++;
		}
	}

	//Checking South West of Cell to see if there are any mines
	if(isValidCell(rowPos + 1, columnPos - 1) == true)
        {
                if(isMine(gameBoard, rowPos + 1, columnPos - 1) == true)
                {
                        count++;
                }
        }

	//Checking West of Cell to see if there are any mines
	if(isValidCell(rowPos, columnPos - 1) == true)
        {
                if(isMine(gameBoard, rowPos, columnPos - 1) == true)
                {
                        count++;
                }
        }

	//Checking North West of Cell to see if there are any mines
	if(isValidCell(rowPos - 1, columnPos - 1) == true)
        {
                if(isMine(gameBoard, rowPos - 1, columnPos - 1) == true)
                {
                        count++;
                }
        }

	//Checking North of Cell to see if there are any mines
	if(isValidCell(rowPos - 1, columnPos) == true)
        {
                if(isMine(gameBoard, rowPos - 1, columnPos) == true)
                {
                        count++;
                }
        }

	//Checking North East of Cell to see if there are any mines
	if(isValidCell(rowPos - 1, columnPos + 1) == true)
        {
                if(isMine(gameBoard, rowPos - 1, columnPos + 1) == true)
                {
                        count++;
                }
        }

	//Checking East of Cell to see if there are any mines
	if(isValidCell(rowPos, columnPos + 1) == true)
        {
                if(isMine(gameBoard, rowPos, columnPos + 1) == true)
                {
                        count++;
                }
        }

	//Checking South East of Cell to see if there are any mines
	if(isValidCell(rowPos + 1, columnPos + 1) == true)
        {
                if(isMine(gameBoard, rowPos + 1, columnPos + 1) == true)
                {
                        count++;
                }
        }

	//Returns Number of mines that are adjacent to cell specified
	return count;
}


//Function that expands the adjacent cells of the special char cell "~" if certain criteria is met 
void Cell::expandCell(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	//Checks to see if the cell is a valid (in the range of the 2d array)
	if(isValidCell(rowPos, columnPos) == true)
        {
		//If the adjacent cell is not a mine and is not already cleared then the cell is expanded
                if((isMine(gameBoard, rowPos, columnPos) != true) && isCleared(userGameBoard, gameBoard, rowPos, columnPos) != true)
                {
                        userGameBoard[rowPos][columnPos] = gameBoard[rowPos][columnPos];
                }

                if(gameBoard[rowPos][columnPos] == '~')
                {
                        //expandCell(userGameBoard, gameBoard, rowPos, columnPos);
                }
        }                     
}


//Function that checks to see what was contained in the cell clicked by user.
//Then returns corresponding number to what was found.
int Cell::click(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	//Checks to see if cell is valid, if there is no flag, and if it is not already cleared
	if((isValidCell(rowPos, columnPos) == true) && (isFlag(userGameBoard, rowPos, columnPos) != true))
	   // && (isCleared(userGameBoard, gameBoard, rowPos, columnPos) != true))
	{

	//Checks to see if the cell has a mine and returns a 1 if so
	if(isMine(gameBoard, rowPos, columnPos) == true)
	{
		return 1;
	}

	//Checks to see if the cell has a special char and returns a 2 if so
	else if(gameBoard[rowPos][columnPos] == '~')
	{
		return 2;
	}

	//Returns a 3 if a number is contained in the cell
	else
	{
		return 3;
	}
	}

	//Returns a 4 if not a valid cell, has a flag, or already cleared
	else 
	{
		return 4;
	}	
}


//Function that toggles the flag placement on a specified cell.
//The user can place a flag on a cell or remove it using this function.
void Cell::toggleFlag(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	//If no flag is placed then place a flag
	if(userGameBoard[rowPos][columnPos] != 'f')
	{
		userGameBoard[rowPos][columnPos] = 'f';
	}
	//If flag is placed then remove it
	else
	{
		userGameBoard[rowPos][columnPos] = ' ';
	}
}


//Function that checks if the cell has been cleared which then
//returns a true or false
bool Cell::isCleared(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	
	if(userGameBoard[rowPos][columnPos] == gameBoard[rowPos][columnPos])
	{
		return true;
	}

	return false;
}


//Function that checks if a cell of the user game board matches the 
//cell of the original game board and then returns a true or false
bool Cell::clear(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos)
{
	if((isMine(gameBoard, rowPos, columnPos) == true) && (isFlag(userGameBoard, rowPos, columnPos) == true))
	{
		return true;
	}

	else if(userGameBoard[rowPos][columnPos] == gameBoard[rowPos][columnPos])
        {
                return true;
        }

	return false;
}


