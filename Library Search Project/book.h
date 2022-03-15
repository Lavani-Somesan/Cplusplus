#ifndef BOOK_H
#define BOOK_H


#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Book {

	public:
		Book(string bookName, string author1, string author2, string category, string bookType, string publisher, string numOfCopies);
		Book();
			
		void printBook();
		void removeCopy();
		void addCopy();
	
		string getBookName();
		string getAuthor1();
		string getAuthor2();
		string getCategory();
		string getBookType();
		string getPublisher();
		string getNumOfCopies();		


	private:
		string bookName;
		string author1;
		string author2;
		string category;
		string publisher;
		string bookType;
		string numOfCopies;
	

};


#endif

