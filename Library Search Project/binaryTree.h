#ifndef STACK_H
#define STACK_H

#include "node.h"
#include "book.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class BinaryTree {
	
	Node* root = NULL;

	public:
		BinaryTree()
		{
		
		}
		void createOrInsert(string data);
		void insert(string data, Node *leaf);
		void searchForBookNames(string data);
		void searchForAvailability(string dataB, vector<Book> books);

		void inOrderNamesTraverse(Node *leaf);
		void printBookNames();
		void printCatalog(vector<Book> books);

	private:
		bool searchForBookNames(string data, Node *leaf);
		void inOrderCatalogTraverse(vector<Book> books, Node *leaf);


};


#endif
