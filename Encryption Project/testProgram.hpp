/***************************************************************
 *   File Name: testProgram.hpp
 *
 *   This is the header file for the class TestProgram which
 *   contains and defines all functions and members for this class.
 *
 ***************************************************************/

#ifndef TESTPROGRAM_HPP
#define TESTPROGRAME_HPP

#include "hashTable.hpp"
#include "encryption.hpp"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class TestProgram
{
	public: 
		TestProgram(string readingFileName);
		void testingBothCases(HashTable &hash, Encryption &encrypt);

	private:
		void readFile(string readingFileName);
		string changeOneCharInPassword(string &password);
		void testingLegalPasswords(HashTable &hash, Encryption &encrypt);
		void testingIllegalPasswords(HashTable &hash, Encryption &encrypt);


		ifstream inFS;
		static const int ROW = 5;
		static const int COLUMN = 2;
		string testArray[ROW][COLUMN];
	
};

#endif
