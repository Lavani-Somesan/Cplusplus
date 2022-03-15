/***************************************************************
 *   File Name: encryption.hpp
 *
 *   This is the header file for the class Encryption which
 *   contains and defines all functions and members for this class. 
 ***************************************************************/


#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Encryption
{
	friend class TestProgram;

	public: 
		Encryption(string readingFileName, string writingFileName);
		
	private:	

		void readFile(string readingFileName, string writingFileName); 
		string encryptPassword(string password);
		void generateKeyArray();
		void writeToFile(string userId, string encryptedPassword);

		ofstream outFS;
		ifstream inFS;
		string key;
		char keyCharArray[];

};

#endif
