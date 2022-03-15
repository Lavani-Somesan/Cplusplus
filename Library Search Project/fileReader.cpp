#include "fileReader.h"
#include "book.h"
#include "library.h"


FileReader::FileReader(string filename)
{

	readFile(filename);
}



void FileReader::readFile(string filename)
{
	ifstream inFS;
	string bookName;
	string author1;
	string author2;
	string category;
	string bookType;
	string publisher;
	string numOfCopies;
	string line;
	int count = 0;
	bool isfileOpen = true;


	Library lib;

	inFS.open(filename.c_str());
	
   	if (!inFS.is_open()) 
	{
      		cout << "Could not open file" << endl;
		isfileOpen = false;
   	}


	if(isfileOpen == true)
	{
			
		while(getline(inFS, line))
		{
			if(count == 0)
			{
				bookName = line;
				++count;
			}
			else if(count == 1)
			{
				author1 = line;
				++count;
			}
			else if(count == 2)
			{
				author2 = line;
				++count;
			}
			else if(count == 3)
			{
				category = line;
				++count;
			}
			else if(count == 4)
			{
				bookType = line;
				++count;
			}
			else if(count == 5)
			{
				publisher = line;
				++count;
			}
			else if(count == 6)
			{
				numOfCopies = line;
				Book book(bookName, author1, author2, category, bookType, publisher, numOfCopies);
				book.printBook();
				lib.addBook(book);		
				count = 0;
			}
		}	
	}

	inFS.close();

	lib.startMenu();
}

