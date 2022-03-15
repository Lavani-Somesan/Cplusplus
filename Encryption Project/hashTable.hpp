/***************************************************************
 *   File Name: hashTable.hpp
 *
 *    This is the header file for the class HashTable which
 *    contains and defines all functions and members for this class.
 *
 ***************************************************************/

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "hashNode.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


class HashTable 
{
	public:
		HashTable(string readingFileName, string writingFileName);
		
		void searchHashTable(string userId);
		string getEncryptedPassword(string userId);
	private:
		void readFile(string readingFileName, string writingFileName);
		void createHashTable();
		int hash(string userId);
		void insertIntoTable(string userId, string encryptedPassword);
		void writeHashTableToFile();

		ifstream inFS;	
		ofstream outFS;
		HashNode **hashTable;
		const int TABLE_SIZE = 90001;

};


#endif
