#include "binaryTree.h"
#include "node.h"
#include "book.h"

void BinaryTree::createOrInsert(string dataB)
{
	if(root == NULL)
	{
		root = new Node();
		root->data = dataB;
		root->left = NULL;
		root->right = NULL;
	}
	
	else
	{
		insert(dataB, root);
	}

}



void BinaryTree::insert(string dataB, Node *leaf)
{
	
	if(dataB < leaf->data)
	{
		if(leaf->left == NULL)
		{
			leaf->left = new Node;
			leaf->left->data = dataB;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	
		else
		{
			insert(dataB, leaf->left);
		}

	}

	else if(dataB >= leaf->data)
	{
		if(leaf->right == NULL)
		{
			leaf->right = new Node;
			leaf->right->data = dataB;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	
		else
		{
			insert(dataB, leaf->right);
		}
	}
}


void BinaryTree::searchForBookNames(string dataB)
{
	bool foundBook;

	if(root != NULL)
	{
		foundBook = searchForBookNames(dataB, root);
		if(foundBook == true)
		{
			cout << "Yes, " << dataB << " is in the Library System." << endl << endl;
		}

		else 
		{
			cout << "Sorry! " << dataB << " is Not In the Library System." << endl << endl;
		}
	}

	else
	{
		cout << "Sorry! There are No Books Currently in the Library System." << endl << endl;
	}

}


bool BinaryTree::searchForBookNames(string dataB, Node *leaf)
{
	bool result = false;
	string dataC = dataB;

	if(leaf != NULL)
	{
		string leafData = leaf->data;
		if(dataC == leafData)
		{
			result =  true;
		}

		if(dataC < leafData)
		{
			searchForBookNames(dataC, leaf->left);
		}
		
		else 
		{
			searchForBookNames(dataC, leaf->right);
		}
	}
	
	return result;
}


void BinaryTree::searchForAvailability(string dataB, vector<Book> books)
{

	if(root != NULL)
	{
		 bool foundBook = searchForBookNames(dataB, root);

                if(foundBook == true)
                {
                        for(unsigned i = 0; i < books.size(); i++)
			{
				cout << books[i].getBookName() << endl;
				if(dataB == books[i].getBookName())
				{
				if(books[i].getNumOfCopies() != "0")
				{
					cout << "There are " << books[i].getNumOfCopies() << " Copies Available." << endl << endl;
				}
				else 
				{
					cout << "There are No Copies Available." << endl << endl;
				}
				break;
				}
			}
                }

                else
                {
                        cout << "Sorry! " << dataB << " is Not In the Library System." << endl << endl;
                }
	}
		
}


void BinaryTree::printBookNames()
{
	cout << endl;
	cout << "----------------------------------------" << endl;
        cout << "Below is a List of All Books" << endl;
        cout << "----------------------------------------" << endl;

	inOrderNamesTraverse(root);

	cout << "----------------------------------------" << endl << endl;

}

void BinaryTree::inOrderNamesTraverse(Node *leaf)
{
	if(leaf != NULL)
	{
		inOrderNamesTraverse(leaf->left);
		cout << "--- " << leaf->data << endl;
		inOrderNamesTraverse(leaf->right);
	}
}

void BinaryTree::printCatalog(vector<Book> books)
{
	cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Below is Our Catalog of Books" << endl;
        cout << "-------------------------------------------------" << endl;

        inOrderCatalogTraverse(books, root);

        cout << "--------------------------------------------------" << endl << endl;


}

void BinaryTree::inOrderCatalogTraverse(vector<Book> books, Node *leaf)
{
	if(leaf != NULL)
        {
                inOrderCatalogTraverse(books, leaf->left);

                for(unsigned i = 0; i < books.size(); i++)
		{
			if(books[i].getBookName() == leaf->data)
			{
				books[i].printBook();
				break;
			}
		}

		inOrderCatalogTraverse(books, leaf->right);
	}
}
