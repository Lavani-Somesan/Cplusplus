#ifndef LAYOUT_H
#define LAYOUT_H

#include <iostream>
#include <string>
#include <fstream>

#include "game.h"
#include "cell.h"

using namespace std;



class Layout {

	public:
		//Default Constructor
		Layout();
	
		//Public Functions
		void createGameBoard(char gameBoard[ROW][COLUMN], int row, int column);
		void fillWithCells(char gameBoard[ROW][COLUMN], int row, int column);
		void explode(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN]);
		void showLayout(char userGameBoard[ROW][COLUMN]);
		void expandClick(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);	
		void flag(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);
		
		bool allClear(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN]);
		
		int click(char userGameBoard[ROW][COLUMN], char gameBoard[ROW][COLUMN], int rowPos, int columnPos);


	private:
		Game gameObj; //Declares Game Object from Game Class
		Cell cell;  //Declares Cell Object from Cell Class

};

#endif 

