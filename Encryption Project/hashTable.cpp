/***************************************************************
 *   File Name: hashTable.cpp
 *
 *   This is the class HashTable's function declarations which
 *   will create a Hash Table and then read in a file that contains 
 *   the encrypted passwords and userIds. The userIds will be hashed
 *   and then inserted into the hash table accordingly.
 *
 ***************************************************************/

#include "hashTable.hpp"


/*   HashTable Constructor
 *   @param readingFileName holds file name of file that is going to be read
 *   @param writingFileName holds file name of file that is going to be written to
 *   
 *   Calls createHashTable function to create the hash table and then calls
 *   readFile function to read encrypted file
 */

HashTable::HashTable(string readingFileName, string writingFileName)
{
	createHashTable();
	readFile(readingFileName, writingFileName);
}


/* createHashTable
 *
 * Creates a Dynamically Allocated HashTable with a 
 * Table size of 90001 and assigns NULL to each index.
 *
 */
void HashTable::createHashTable()
{
	hashTable = new HashNode*[TABLE_SIZE];

	for(int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}

/*  readFile
 *  @param readingFileName holds file name of file that is going to be read
 *  @param writingFileName holds file name of file that is going to be written to
 *   
 *  Opens encryption.txt to be read and reads the userIds and encrypted passwords.
 *  Calls insertIntoTable Function and writeToFile function to insert userIds and 
 *  encrypted passwords into hash table and then writing them to a file.
 *
 */
void HashTable::readFile(string readingFileName, string writingFileName)
{
	bool isFileOpen = true;
	string userId, encryptedPassword;
	
	inFS.open(readingFileName.c_str());
	outFS.open(writingFileName.c_str());
		

    	if(!inFS.is_open())
	{
		cout << "Could not open file" << endl;
		isFileOpen = false;
	}

	 if(isFileOpen == true)
	{
		while(inFS >> userId >> encryptedPassword)
		{
			insertIntoTable(userId, encryptedPassword);
		}
	}	

	writeHashTableToFile();

	inFS.close();
	outFS.close();
}


/* insertIntoTable 
 * @param userId which holds the userIds 
 * @param encryptedPassword which hodls the encrypted passwords for each userId
 *
 * First Calls the Hash funciton to hash the userId and return an index. Then index
 * is in hash table is looked at to be NULL and if so then the userId and encrypted
 * password is inserted into the index location. If the index location is not NULL 
 * then the next node in that index is assigned the data.
 *
 */
void HashTable::insertIntoTable(string userId, string encryptedPassword)
{
	int index = hash(userId);
	string info = userId + " " + encryptedPassword;

	HashNode *newNode = new HashNode(info, userId, encryptedPassword);

	if(hashTable[index] == NULL)
	{
		hashTable[index] = newNode;
	}

	else 
	{
		newNode->next = hashTable[index];
		hashTable[index] = newNode;
	}
}


/* hash
 * @param userId which holds the user's Id
 *
 * This takes each character in the userId and multiplying it
 * by 3 to the power n+1 and summing it. We then take the sum 
 * we got and do a modulus with the table size and return that number.
 *
 *
 */
int HashTable::hash(string userId)
{
	int sumOfUserId = 0;
	int h = 3;
	int counter = 1;

	for(unsigned int i = 0; i < userId.length(); i++)
	{
		sumOfUserId = sumOfUserId + (int(userId[i]) * pow(h, counter));;
		counter++;
	}

	return sumOfUserId % TABLE_SIZE;	
}



/* searchHashTable
 * @param userId which holds the user's Id
 *
 * This searches through the hash table by taking
 * the passed userId and hashing it and then starting
 * at the index of hash and seeing if the userId passed
 * matches the userId in that index and can traverse each node
 * in that index to find a match. 
 *
 */
void HashTable::searchHashTable(string userId)
{
	int index = hash(userId);
	bool found = false;

	for(auto dataKey = hashTable[index]; dataKey != NULL; dataKey = dataKey->next)
	{
		if(dataKey->keyUserId == userId)
		{
			found = true;
			cout << "User ID: " << dataKey->keyUserId << " with Encrypted Password " << dataKey->password << " Found at Bucket " << index << endl;
		}	
	}

	if(found != true)
	{
		cout << userId << " Could Not Be Found!" << endl;
	}
}


/* getEncryptedPassword
 * @param userId which holsd the user's Id
 *
 * Takes passed userId and hashes to get hash index. Then
 * searches through that index to find a matching userId
 * which if it finds a match returns the encrypted password
 * else returns nothing.
 *
 */
string HashTable::getEncryptedPassword(string userId)
{
	int index = hash(userId);
	string NOTFOUND = " ";

	for(auto dataKey = hashTable[index]; dataKey != NULL; dataKey = dataKey->next)
	{
		if(dataKey->keyUserId == userId)
		{
			return dataKey->password;
		}
	}

	return NOTFOUND;
}


/* writeHashTableToFile
 *
 * Writes the hashTable array to a file called 
 * HashTableData.txt.
 *
 */
void HashTable::writeHashTableToFile()
{
	int counter = 0;
	bool isFileOpen = true;

	if(!outFS.is_open())
	{
		cout << "Could not open file." << endl;
		isFileOpen = false;
	}

	if(isFileOpen == true)
	{
	while(counter < TABLE_SIZE) 
	{
		outFS << counter << ".] ";	
		for(auto dataKey = hashTable[counter]; dataKey != NULL; dataKey = dataKey->next)
		{
			if(dataKey->next == NULL)
			{
				outFS << dataKey->data << " ";
			}
			else 
			{
				outFS << dataKey->data << " ---> ";
			}		
		}
		outFS << endl;
		counter++;
	}
	}
}
