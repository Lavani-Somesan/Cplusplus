/***************************************************************
 *   File Name: testProgram.cpp
 *
 *   This is the class testProgram's function declarations which
 *   which tests the program to see if it accurately works.
 *   Reads in a text file which the userIds and passwords are put
 *   into a 5 by 2 2d array that will be used to test the program.
 *   We will test 5 user names and passwords by seeing if the
 *   userIds can be found in the already created hash table and
 *   seeing if the unencrypted passwords when encrypting them will 
 *   match the encrypted passwords stored in the hash table.
 *
 ***************************************************************/

#include "testProgram.hpp"
#include "hashTable.hpp"
#include "encryption.hpp"


/* TestProgram
 * @peram readingFileName holds file name of file that is going to be read
 * @param writingFileName holds file name of file that is going to be written to
 * 
 * Calls readFile Function to read text file
 * 
 */
TestProgram::TestProgram(string readingFileName)
{
	readFile(readingFileName);
}


/* readFile
 * @param readingFileName holds file name of file that is going to be read
 * @param writingFileName holds file name of file that is going to be written to
 *  
 *  Opens raw.txt to be read and reads the userIds and unencrypted passwords into testArray.
 *
 */

void TestProgram::readFile(string readingFileName)
{
	bool isFileOpen = true;
	string userId, password;
	int counter = 0;
	int maxEntriesToTest = 5;
	int columnNum = 0;


	inFS.open(readingFileName.c_str());

	if(!inFS.is_open())
	{
		cout << "Could not open file." << endl;
		isFileOpen = false;
	}

	if(isFileOpen == true)
	{
		while(counter != maxEntriesToTest)
		{
			inFS >> userId >> password;
			
			testArray[counter][columnNum] = userId;
			testArray[counter][columnNum+1] = password;
			
			counter++;
		}

	}
		
	inFS.close();
}


/* testingBothCases
 * @param hash is an object from the HashTable class
 * @param encrypt is an object from the Encryption class
 *
 * Function that calls the testingLegalPasswords and testingIllegalPasswords
 * functions to test the testArray data.
 *
 */
void TestProgram::testingBothCases(HashTable &hash, Encryption &encrypt)
{
	cout << endl;
	cout << "TESTING LEGAL PASSWORDS" << endl << endl;

	testingLegalPasswords(hash, encrypt);

	cout << "TESTING ILLEGAL PASSWORDS" << endl << endl;

	testingIllegalPasswords(hash,encrypt);
}


/* testingLegalPasswords
 * @param hash is an object from the HashTable class
 * @param encrypt is an object from the Encryption class
 *
 * Takes the data from the testArray and assigns it to a string userId and
 * a string password. Then uses hash object to call searchHashTable function 
 * to see if a matching userId was found. Then uses encrypt object to call
 * encryptPassword function to encrypt the testArray password and then check
 * to see if the now encryptedPassword is  equivalent to the encrypted password
 * in the hash table.
 *
 */
void TestProgram::testingLegalPasswords(HashTable &hash, Encryption &encrypt)
{
	string encryptedPassword;
	string encryptPassword;
	string password, userId;

	for(int i = 0; i < ROW; i++)
	{
		userId = testArray[i][0];
		password = testArray[i][1];

		cout << i+1 << ".] User ID: " << userId << " Password: " << password << endl;
		hash.searchHashTable(userId);

		encryptPassword = encrypt.encryptPassword(password);
		encryptedPassword = hash.getEncryptedPassword(userId);

		if(encryptPassword == encryptedPassword)
		{
			cout << "The Password: " << password << " is Encrypted into " << encryptPassword << " Which Matches the Encrypted Password in the Hash Table "; 
			cout << encryptedPassword << endl << endl;
		}

		else
		{
			cout << "The Password: " << password << " is Encrypted into " << encryptPassword << " Which Does NOT Match the Encrypted Password in";
			cout << " the Hash Table: " << encryptedPassword << endl << endl;
		}
	}	
}



/* testingLegalPasswords
 * @param hash is an object from the HashTable class
 * @param encrypt is an object from the Encryption class
 *  
 *  Takes the data from the testArray and assigns it to a string userId and
 *  a string password. Then uses hash object to call searchHashTable function
 *  to see if a matching userId was found. Then call changeOneCharacterInPassword
 *  fucntion which should change a character in the non encrypted password.
 *  Then uses encrypt object to call encryptPassword function to encrypt the testArray 
 *  password and then check to see if the now encryptedPassword is equivalent to the encrypted 
 *  password in the hash table.
 *           
 */

void TestProgram::testingIllegalPasswords(HashTable &hash, Encryption &encrypt)
{
	string encryptedPassword;
	string encryptPassword;
	string password, userId;

	for(int i = 0; i < ROW; i++)
	{
		userId = testArray[i][0];
		password = testArray[i][1];

		cout << i+1 << ".] User ID: " << userId << " Password: " << password << endl;
		hash.searchHashTable(userId);
		changeOneCharInPassword(password);
		
		encryptPassword = encrypt.encryptPassword(password);
		encryptedPassword = hash.getEncryptedPassword(userId);

		if(encryptPassword == encryptedPassword)
		{
			cout << "The Password: " << password << " is Encrypted into " << encryptPassword << " Which Matches the Encrypted Password in the Hash Table ";
			cout << encryptedPassword << endl << endl;
		}
		
		else
		{
			cout << "The Passowrd: " << password << " is Encrypted into " << encryptPassword << " Which Does NOT Match the Encrypted Password in";
			cout << " the Hash Table: " << encryptedPassword << endl << endl;
		}
	}
}


/* changeOneCharInPassword
 *@param password holds unencrypted password
 *
 * Changes the first character in the password to 'a' if the
 * first letter is not an 'a'. Changes the first character to 'c'
 * if first character in password is 'a'.
 *
 */
string TestProgram::changeOneCharInPassword(string &password)
{
	int beginningStrIndex = 0;
	char firstLetter = 'a';
	char ThirdLetter = 'c';

	if(password[beginningStrIndex] != firstLetter)
	{
		password[beginningStrIndex] = firstLetter;
	}

	else
	{
		password[beginningStrIndex] = ThirdLetter;
	}

	return password;
}
