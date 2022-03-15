/***************************************************************
 *   File Name: generatePassword.cpp
 *   
 *   This is the class generatePassword's function declarations which
 *   will read in a file that contains last names which will become userId.
 *   Then it generates a random 9 character password for each userId and 
 *   then writes the passwords and userIds into a text file called raw.txt
 ***************************************************************/

#include "generatePassword.hpp"


/*GeneratePassword Constructor
 * @param readingFileName holds file name of file that is going to be read
 * @param writingFileName holds file name of file that is going to be written to
 *
 *Calls readFile Function to read file
 *
 */
GeneratePassword::GeneratePassword(string readingFileName, string writingFileName)
{
	readFile(readingFileName, writingFileName);
}


/* readFile 
 * @param readingFileName holds file name of file that is going to be read
 * @param writingFileName holds file name of file that is going to be written to
 *
 * Opens lastNames.txt to be read and reads the Last names from file.
 * Calls createRandomPasswords Function and writeToFile function to create passwords
 * for userIds and then writing them to a file.
 */
void GeneratePassword::readFile(string readingFileName, string writingFileName) 
{
	bool isFileOpen = true; 
	string userId, password;
	string data1, data2, data3;

	srand(time(NULL));

	inFS.open(readingFileName.c_str());
	outFS.open(writingFileName.c_str());

	if(!inFS.is_open()) 
	{
		cout << "Could not open file" << endl;
		isFileOpen = false;
	}


	if(isFileOpen == true)
	{
		while(inFS >> userId >> data1 >> data2 >> data3)
		{
			password = createRandomPasswords();
			writeToFile(userId, password);
		}	
	}

	inFS.close();
	outFS.close();
}



/*createRandomPasswords
 *
 * Creates an char array that contains all lower case letters of the alphabet. 
 * Then sets the password length to 9 and then randomizes the index of the char
 * array and adds 9 random char from array to a string called password. Then 
 * returns password. Generates truely random passwords each time since using srand.
 *
 */
string GeneratePassword::createRandomPasswords()
{	
	const int SIZE = 26;
	char alphabetAndNumbers[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};	
	string password;
	int lengthOfPassword = 9;

	for(int i = 0; i < lengthOfPassword; i++)
	{
		password = password + alphabetAndNumbers[rand() % SIZE];
	}

	return password;
}


/*writeToFile
 * @param userId holds the user id 
 * @param password holds unencrypted password
 *
 * Writes the userIds and their randomly generated
 * passwords to a textfile called raw.txt
 *
 */
void GeneratePassword::writeToFile(string userId, string password)
{
	bool isFileOpen = true;

	if(!outFS.is_open()) 
	{
		cout << "Could not open file raw.txt" << endl;
		isFileOpen = false;
	}

	if(isFileOpen == true)
	{
		outFS << userId << " " << password << endl;
	}
}
