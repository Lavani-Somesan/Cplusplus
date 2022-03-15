//Lavani Somesan
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "ImageClass.h"


void ChangeImage::Rotate90(int imArr[][24], const int row, const int column) {
	
	//Variables
	int rowCopy = column;
	int columnCopy = row;
	int imCopyArr[rowCopy][columnCopy];
	string outFileName;

	//Rotates Coppied ARray 90 Degrees
	for(int i=0; i < rowCopy; i++) {
        for(int j=0; j < columnCopy; j++) {
        imCopyArr[i][j] = imArr[columnCopy-1-j][i];
        }
        }
	
	
	ofstream outFS;
	
	//Prompts User To Enter Output File Name
	cout << "Please input the name of the output file / path: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;

	//Validates the Output File is less than 32 characters	
	while(outFileName.length() > 31) {
        cout << "Please input the name of the output file/ path less than 32 characters: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;
        }

	outFS.open(outFileName.c_str());


	//Outputs Rotated Array into Output File
	for(int i=0; i < rowCopy; i++) {
        for(int j=0; j < columnCopy; j++) {
        outFS << right << setw(2) <<  imCopyArr[i][j] << "  ";
        }
        outFS << endl;
        }
	
	//Closes Output File
	outFS.close();

	cout << endl;
	cout << "File Rotated 90 Degrees" << endl;
	cout << "File Saved!" << endl;
	cout << "Thank You For Using!" << endl;


}//End of Rotate90 Function



void ChangeImage::Rotate180(int imArr[][24], const int row, const int column) {

	//Variables
	int rowCopy = column;
        int columnCopy = row;
        int imCopyArr[rowCopy][columnCopy]; //Rotated 90 Degrees Array
	int imCopy2Arr[row][column]; 	//Rotated 180 Degress Array
	string outFileName;

	//Rotates Copied Array 90 degrees
        for(int i=0; i < rowCopy; i++) {
        for(int j=0; j < columnCopy; j++) {
        imCopyArr[i][j] = imArr[columnCopy-1-j][i];
        }
        }

	//Rotates Copied Array Another 90 Degrees
	for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
        imCopy2Arr[i][j] = imCopyArr[column-1-j][i];
	}
        }
	
	ofstream outFS;

	//Asks User to Enter Output File Name
	cout << "Please input the name of the output file / path: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;

	//Validates Output File to be less than 32 characters
	while(outFileName.length() > 31) {
        cout << "Please input the name of the output file/ path less than 32 characters: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;
        }

	//Opens Output File
        outFS.open(outFileName.c_str());


	//Copys Array to Output File
	for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
        outFS << right << setw(2) <<  imCopy2Arr[i][j] << " ";
        }
        outFS << endl;
        }

	//Closes Output File
	outFS.close();
	
	cout << endl;
        cout << "File Rotated 180 Degrees" << endl;
        cout << "File Saved!" << endl;
        cout << "Thank You For Using!" << endl;

}//End of Rotate180 Function


void ChangeImage::Rotate270(int imArr[][24], const int row, const int column) {

        int rowCopy = column;
        int columnCopy = row;
        int imCopyArr[rowCopy][columnCopy];
	string outFileName;
	
	//Rotates Copied Array 90 Degrees Counter Clockwise (270 Degrees Clockwise)
        for(int i=rowCopy-1; i >= 0; i--) {
        for(int j=columnCopy-1; j >= 0; j--) {
        imCopyArr[i][j] = imArr[j][rowCopy-1-i];
	}
        }

	ofstream outFS;

	//User is Prompted to Enter Output File
        cout << "Please input the name of the output file / path: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;

	//Validates User if Output File is less than 32 characters
        while(outFileName.length() > 31) {
        cout << "Please input the name of the output file/ path less than 32 characters: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;
        }
	
	//Opens Output File
        outFS.open(outFileName.c_str());

	//Outputs Rotated Array to Output File	
	for(int i=0; i < rowCopy; i++) {
        for(int j=0; j < columnCopy; j++) {
        outFS << right << setw(2) <<  imCopyArr[i][j] << " ";
        }
        outFS << endl;
        }
	
	//Closes Output File
	outFS.close();

        cout << endl;
        cout << "File Rotated 270 Degrees" << endl;
        cout << "File Saved!" << endl;
        cout << "Thank You For Using!" << endl;

}//End of Rotate270 Function


void ChangeImage::HorizontalFlip(int imArr[][24], const int row, const int column) {
	
	//Variables
	string outFileName;

	//Flips Image Array Horizontally
	for(int i=0; i < row; i++) {
        for(int j=0; j < column/2; j++) {
        swap(imArr[i][j], imArr[i][column-j-1]);
        }
        }

	ofstream outFS;
	
	//User is Prompted to Enter Output File Name
        cout << "Please input the name of the output file / path: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;

	//Validates User that Output File Name is less than 32 characters
        while(outFileName.length() > 31) {
        cout << "Please input the name of the output file/ path less than 32 characters: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;
        }
	
	//Opens Output File
        outFS.open(outFileName.c_str());


	//Prints Flipped Array to Output File
	for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
        outFS << right << setw(2) <<  imArr[i][j] << " ";
        }
        outFS << endl;
        }

	//Closes Output File
	outFS.close();

        cout << endl;
        cout << "File Horizontally Flipped" << endl;
        cout << "File Saved!" << endl;
        cout << "Thank You For Using!" << endl;


}//End of HorizontalFlip Function


void ChangeImage::VerticalFlip(int imArr[][24], const int row, const int column) {

	//Variables
	string outFileName;

	//Flips Image Array Vertically
	for(int j=0; j < column; j++) {
        for(int i=0; i < row/2; i++) {
        swap(imArr[i][j], imArr[row-i-1][j]);
	}
	}

	ofstream outFS;
	
	//Prompts User to Enter Output File Name
        cout << "Please input the name of the output file / path: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;

	//Validates User that Output File Name is less than 32 characters
        while(outFileName.length() > 31) {
        cout << "Please input the name of the output file/ path less than 32 characters: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;
        }

	//Opens Output File
        outFS.open(outFileName.c_str());

	//Prints Flipped Array to Output File
	for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
	outFS << right << setw(2) <<  imArr[i][j] << "   ";
        }
	outFS << endl;
        }
	
	//Closes Output File
	outFS.close();

        cout << endl;
        cout << "File Vertically Flipped" << endl;
        cout << "File Saved!" << endl;
        cout << "Thank You For Using!" << endl;

}//End of VerticalFlip Function


void ChangeImage::BlackAndWhite(int imArr[][24], const int row, const int column, int thresh) {

	//Variables
	int userThresh;
	string outFileName;
	
	//User Enters Threshold Value
	cout << "Please Enter a Threshold Value for the Image." << endl;	
	cin >> userThresh;

	//Loop That Checks Each Value in the Array to 0 or 15 depneding on the threshold
	for(int i=0; i < row; i++) {
	for(int j=0; j < column; j++) {
	if(imArr[i][j] <= userThresh) {
	imArr[i][j] = 0;
	}
	else {
	imArr[i][j] = thresh;
	}
	}
	}

	ofstream outFS;

	//Prompts User to Enter Output File Name
        cout << "Please input the name of the output file / path: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;

	//User Validation that Output File Name is less than 32 characters
        while(outFileName.length() > 31) {
        cout << "Please input the name of the output file/ path less than 32 characters: sample.pgm" << endl;
        cin >> outFileName;
        cout << endl;
        }

	//Opnes Output File
        outFS.open(outFileName.c_str());

	//Prints BlackAndWhite Array to Output File
	for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
        outFS << right << setw(2) <<  imArr[i][j] << "   ";
        }
        outFS << endl;
        }

	//Closes Output File
	outFS.close();

        cout << endl;
        cout << "File Converted to Black And White" << endl;
        cout << "File Saved!" << endl;
        cout << "Thank You For Using!" << endl;

} //End of BlackOrWhite Function
