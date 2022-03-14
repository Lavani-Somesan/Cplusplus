//Lavani Somesan
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "ImageClass.h"

int main() {

        string inFileName; //Name of Input File	
	string name;	//Name of Type of Image
	int choice; 	//User Chooses what option they want
	int row;	//Holds Row Size of Array from File
	int column;	//Holds Column Size of Array from File
	int inputHolder; //Holds Input of the array from file while it is being coppied over
	int maxThreshold; //Holds Max Threshold Value
	int k=0,m=0;		

	ifstream inFS;
	
	//User Enters File Name
        cout << "Welcome!" << endl;
        cout << "Please input a file name / path: sample.pgm" << endl;
        cin >> inFileName;
	cout << endl;
	
	//Validates the File is less than 32 characters
	while(inFileName.length() > 31) {
	cout << "Please input a file name / path less than 32 characters: sample.pgm" << endl;
	cin >> inFileName;
	cout << endl;
	}

	
	//Opens Image File
        inFS.open(inFileName.c_str());

	
	//Checks to see if file cannot be opened
        if(!inFS.is_open()) {
        cout << "File Could Not Be Opened." << inFileName << endl;
        return 1;       //1 indicates error
        }


	//Input from file
	inFS >> name;
	inFS >> column;
	inFS >> row;
	inFS >> maxThreshold;


	//Declares array
	int imageArr[row][column];


	//Copies array into main array
	while(inFS >> inputHolder) {
	if(m != 23) {
	imageArr[k][m] = inputHolder;	
	m++;	
	}
	else {
	imageArr[k][m] = inputHolder;
	k++;
	m = 0;
	}
	}

	//Closes Input File
	inFS.close();

	cout << endl;
	
	//Declares a Copy Array for ImageArr
	const int ROW = row;
	const int COLUMN = 24;
	int imageArray[ROW][COLUMN];

	//Populates Copy Array for Image
	//Had to make a copy because it was not passing as argument in function
	for(int i=0; i < ROW; i++) {
	for(int j=0; j < COLUMN; j++) {
	imageArray[i][j] = imageArr[i][j];
	}
	}

	//Declares Image Object from ChangeImage Class
	ChangeImage image;	
	
	//Option Menu	
	cout << "OPTIONS" << endl;
	cout << "1. Rotate 90 Degress Clockwise" << endl;
	cout << "2. Rotate 180 Degrees Clockwise" << endl;
	cout << "3. Rotate 270 Degrees Clockwise" << endl;
	cout << "4. Flip Vertically" << endl;
	cout << "5. Flip Horizontally" << endl;
	cout << "6. To Black And White" << endl;

	cin >> choice;
	
	//User Validation 
	while(choice > 6 || choice < 1)
	{
	cout << "Please Enter A Choice 1-6" << endl;
	cin >> choice;
	}
	cout << endl; 
        

	//Function that is chosen by user to do on image
	switch(choice) {
	
	case 1:
	image.Rotate90(imageArray, ROW, COLUMN);
	break;
	
	case 2:
	image.Rotate180(imageArray, ROW, COLUMN);
	break;
	
	case 3:
	image.Rotate270(imageArray, ROW, COLUMN);
	break;
	
	case 4:
	image.VerticalFlip(imageArray, ROW, COLUMN);
	break;
	
	case 5:
	image.HorizontalFlip(imageArray, ROW, COLUMN); 
	break;

	case 6:
	image.BlackAndWhite(imageArray, ROW, COLUMN, maxThreshold);
	break;
	}

	return 0;

} //End of Main

