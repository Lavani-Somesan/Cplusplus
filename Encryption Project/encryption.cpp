/***************************************************************
 *   File Name: encryption.cpp
 *
 *   This is the class Encryption's function declarations which
 *   will read in a file that contains userIds and raw passwords.
 *   The class wil then encrypt the passwords using a Vigenere cipher
 *   using the key jones. The userids and encrypted passwords will be
 *   written to a textfile called encrypted.txt.
 *
 ***************************************************************/

#include "encryption.hpp"



/*Encryption Constructor
 * @peram readingFileName holds file name of file that is going to be read
 * @param writingFileName holds file name of file that is going to be written to
 *
 * Assigns key to be jones and creates a key Character Array that will hold each
 * character of the key. Then will call funciton generateKeyArray and then call
 * readFile Function to read file.
 */
Encryption::Encryption(string readingFileName, string writingFileName)
{
	key = "jones";
	keyCharArray[key.length()];

	generateKeyArray();

	readFile(readingFileName, writingFileName);
}


/* readFile
 *  @param readingFileName holds file name of file that is going to be read
 *  @param writingFileName holds file name of file that is going to be written to
 *  
 *  Opens raw.txt to be read and reads the userIds and passwords from file.
 *  Calls encryptedPassword Function and writeToFile function to encrypt the passwords
 *  and then write the userIds and encrypted passwords to a file.
 */

void Encryption::readFile(string readingFileName, string writingFileName)
{
        bool isFileOpen = true;
	string userId, password;
	string encryptedPassword;

	inFS.open(readingFileName.c_str());
	outFS.open(writingFileName.c_str());

	if(!inFS.is_open())
	{
	cout << "Could not open file" << endl;
	isFileOpen = false;
	}

	
	if(isFileOpen == true)
	{
		while(inFS >> userId >> password)
		{
		encryptedPassword = encryptPassword(password);
		writeToFile(userId, encryptedPassword);
		}
	}

	inFS.close();
	outFS.close();
}


/*generateKeyArray
 *
 * Generates Character Array that will hold the key "jones" and will
 * be used to encrypt the passwords.
 *
 */
void Encryption::generateKeyArray()
{
	for(unsigned int i = 0; i < key.length(); i++)
	{
		keyCharArray[i] = key[i];
	}
}


/*encryptPassword
 * @param password holds the unencrypted password which will be encrypted
 *
 * Takes the password and puts it into a character array. Then takes a
 * character from the key array and subtracts the ASCII value 'a' from it
 * to get number of shifts the alphabet is shifting by. Then takes a password
 * character and adds the shift value to get the new letter. This process repeats
 * till all characters in password array are encrypted and are assigned to string 
 * encryptedPassowrd which is then returned.
 *
 */
string Encryption::encryptPassword(string password)
{
	unsigned int counter = 0;
	char passwordCharArray[password.length()];
	string encryptedPassword;
	char startLetter = 'a';
	char endLetter = 'z';
	int originalNumShifts;
	int remainingShifts;
	int finalNumShifts;
	char encryptedChar;


	for(unsigned int i = 0; i < password.length(); i++)
	{
		passwordCharArray[i] = password[i];
	}


	for(unsigned int i = 0; i < password.length(); i++)
	{
		if(counter <= key.length() - 1)
		{
			originalNumShifts = int(keyCharArray[counter]) - int(startLetter);

			if(int(passwordCharArray[i]) + originalNumShifts > int(endLetter))
			{
				remainingShifts = int(endLetter) - int(passwordCharArray[i]);
				finalNumShifts = originalNumShifts - remainingShifts - 1;

				encryptedChar = startLetter + char(finalNumShifts);				
				encryptedPassword += encryptedChar;
			}

			else 
			{
				encryptedChar = passwordCharArray[i] + originalNumShifts;
				encryptedPassword += encryptedChar;
			}
		}

		counter++;

		if(counter == key.length())
		{
			counter = 0;
		}
	}

	return encryptedPassword;
}


/*writeToFile
 *  @param userId holds the user id
 *  @param password holds unencrypted password
 *   
 *  Writes the userIds and the newly encrypted passwords
 *  to a textfile called encrypted.txt
 * 
 */
void Encryption::writeToFile(string userId, string encryptedPassword)
{
	bool isFileOpen = true;

        if(!outFS.is_open())
	{
		cout << "Could not open file." << endl;
                isFileOpen = false;
        }

        if(isFileOpen == true)
	{
		outFS << userId << " " << encryptedPassword << endl;
	}
}
