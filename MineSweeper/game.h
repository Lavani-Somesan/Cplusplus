#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;


const int ROW = 4;
const int COLUMN = 4;


class Game {

	public:
		//Default Constructor
		Game();
	
		//Public Functions
		void playGame();
		void setFileName(string fileName);
		string getFileName();
		bool isValidFileName();
		bool isValidMove();
		bool isGameOver(int outcome);
		int move(char userOption, int userRowNum, int userColumnNum);

	private:
		char gameBoard[ROW][COLUMN];  //Holds Original Game Board 2d array
                char userGameBoard[ROW][COLUMN];  //Holds User's Game Board 2d array
		string fileName;  //Holds File name that contains minefield info
	
};


#endif 
