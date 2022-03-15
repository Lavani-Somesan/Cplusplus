/***************************************************************
 *   File Name: generatePassword.hpp
 *
 *   This is the header file for the class GeneratePassword which
 *   contains and defines all functions and members for this class.
 *         
 ***************************************************************/

#ifndef GENERATEPASSWORD_HPP
#define GENERATEPASSWORD_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


class GeneratePassword {

	public:
		GeneratePassword(string readingFileName, string writingFileName);
		
	private:	
		void readFile(string readingFileName, string writingFileName);
		string createRandomPasswords();
		void writeToFile(string userId, string password);

		ofstream outFS;
		ifstream inFS;
};

#endif
