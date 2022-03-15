#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "binaryTree.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Library {

	public:
		Library();	
		void addBook(Book bk);	
		void startMenu();
		void createBinaryTree(BinaryTree &bt);
		void loanABook();
		void returnABook();


	private:
		vector<Book> book;
		BinaryTree bt;
		vector<string> loanBookList;	
		
};


#endif

