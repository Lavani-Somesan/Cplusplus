#include <iostream>
#include <string>
#include <fstream>

#include "game.h"
#include "layout.h"
#include "cell.h"

using namespace std;



int main()
{	
	//Declaring Game Class
	Game game;

	//Calling playGame Function to play MineSweeper
	game.playGame();


	return 0;
}
