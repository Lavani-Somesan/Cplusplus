/***************************************************************
 *   File Name: main.cpp
 *
 *   This class is called the main class which holds all class
 *   declarations and usages of classes. The main class runs the
 *   program.
 *
 ***************************************************************/

#include "generatePassword.hpp"
#include "encryption.hpp"
#include "hashTable.hpp"
#include "hashNode.hpp"
#include "testProgram.hpp"

#include <iostream>
using namespace std;



int main() {

	string lastNamesFile = "lastNames.txt";
	string rawPasswordsFile = "raw.txt";
	string encryptedPasswordsFile = "encrypted.txt";
	string hashTableDataFile = "hashTableData.txt";
	
	GeneratePassword userIds(lastNamesFile, rawPasswordsFile);
	
	Encryption encrypt(rawPasswordsFile, encryptedPasswordsFile);
	
	HashTable hash(encryptedPasswordsFile, hashTableDataFile);
	
	TestProgram test(rawPasswordsFile);	

	test.testingBothCases(hash, encrypt);

	return 0;
}

