#include "book.h"

Book::Book()
{
	bookName = "N/A";
	author1 = "N/A";
	author2 = "N/A";
	category = "N/A";
	bookType = "N/A";
	publisher = "N/A";
	numOfCopies = "N/A";


}


Book::Book(string bookName, string author1, string author2, string category, string bookType, string publisher, string numOfCopies)
{
	this->bookName = bookName;
	this->author1 = author1;
	this->author2 = author2;
	this->category = category;
	this->bookType = bookType;
	this->publisher = publisher;
	this->numOfCopies = numOfCopies;

}

void Book::removeCopy()
{
	string bookString;
	int numBooks = stoi(numOfCopies.c_str());
	numBooks = numBooks - 1;
	
	bookString = to_string(numBooks);

	numOfCopies = bookString;
}


void Book::addCopy()
{
	string bookString;
        int numBooks = stoi(numOfCopies.c_str());
        numBooks = numBooks + 1;

        bookString = to_string(numBooks);

        numOfCopies = bookString;
}

string Book::getBookName()
{
	return bookName;
}


string Book::getAuthor1()
{
	return author1;
}


string Book::getAuthor2()
{
	return author2;
}


string Book::getCategory()
{
	return category;
}


string Book::getBookType()
{
	return bookType;
}


string Book::getPublisher()
{
	return publisher;
}

string Book::getNumOfCopies()
{
	return numOfCopies;
}


void Book::printBook()
{
	cout << "--------------------------------------------------" << endl;
	cout << "Book Name      : " << bookName << endl;
	cout << "Author 1       : " << author1 << endl;
	cout << "Author 2       : " << author2 << endl;
	cout << "Category       : " << category << endl;
	cout << "Format         : " << bookType << endl;
	cout << "Publisher      : " << publisher << endl;
	cout << "Available Now  : " << numOfCopies << endl;
	cout << "--------------------------------------------------" << endl;
}
