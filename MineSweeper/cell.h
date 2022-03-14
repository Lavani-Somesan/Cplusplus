#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

#include "game.h"

using namespace std;



class Cell {

	public:
	//Default Constructor
	Cell();
	
	//Public Functions
	bool isMine(char gameBoard[ROW][COLUMN], int rowPos, int columnPos);
	bool isFlag(char userGameBoard[ROW][COLUMN], int rowPos, int columnPos);
	bool isValidCell(int rowPos, int columnPos);
	bool isCleared(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);
	bool clear(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);
	
	int getMineCount(char gameBoard[ROW][COLUMN], int rowPos, int columnPos);
	int click(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);	
	
	void expandCell(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);
	void toggleFlag(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);
	
};

#endif 

