#include "library.h"
#include "book.h"
#include "binaryTree.h"

Library::Library()
{

}


void Library::addBook(Book bk)
{
	book.push_back(bk);
}



void Library::createBinaryTree(BinaryTree &bt)
{
	for(unsigned i = 0; i < book.size(); i++)
        {
                bt.createOrInsert(book[i].getBookName());
        }

}


void Library::loanABook()
{
	string userOption = " ";
	string string1;
	string string2;
	bool found = false;

	cout << "Please Enter the Name of the Book You Wish to Loan Out. " << endl;
	cin.ignore();
	getline(cin, userOption);

	string2 = userOption;
	

	for(unsigned i = 0; i < book.size(); i++)
	{
		string1 = book[i].getBookName();

		if(string2 == userOption)
		{
			found = true;

			if(book[i].getNumOfCopies() != "0")
			{
				book[i].removeCopy();
				loanBookList.push_back(book[i].getBookName());	
				cout << "Successfully, Loaned " << userOption << " Now Number of Copies Left is " << book[i].getNumOfCopies() << endl << endl;
				break;
			}
		
			else
			{
				cout << "Unfortunately, There are No Copies Left of << " << userOption << endl << endl;
				break;
			}
		}
	}

	if(found == false)
	{
		cout << "No Match Was Found." << endl << endl;
	}	

}



void Library::returnABook()
{
        string userOption = " ";
        string string1;
        string string2;
        bool found = false;

        cout << "Please Enter the Name of the Book You Wish to Return. " << endl;
        cin.ignore();
        getline(cin, userOption);

        string2 = userOption;


        for(unsigned i = 0; i < loanBookList.size(); i++)
        {
                if(userOption == string2)
                {
			found = true;	
                	book[i].addCopy();
                        cout << "Successfully, Returned " << userOption << ", Now Number of Copies Left is " << book[i].getNumOfCopies() << endl << endl;
                        break;
                }
        }

        if(found == false)
        {
                cout << "No Match Was Found." << endl << endl;
        }

}






void Library::startMenu()
{
	int userOption;
	string userData;
	string userData2;

	createBinaryTree(bt);

	do {

	cout << "=============================================" << endl;
	cout << "    Welcome To Your Neighborhood Library" << endl;
	cout << "=============================================" << endl;
	cout << "Select One of the Options From the Below Menu: "<< endl;
	cout << "1. To Check if a Particular Book is Part of the Library System" << endl;
	cout << "2. To Show the Names of All the Books in the Library" << endl;
	cout << "3. To Show a Catalog of All the Books with Full Details" << endl;
	cout << "4. To Find Out if a Particular Book is Currently Available" << endl;
	cout << "5. To Loan a Book" << endl;
	cout << "6. To Return a Book" << endl;
	cout << "7. To Exit Program" << endl;
	cin >> userOption;

	while(userOption < 1 || userOption > 7)
	{
		cout << "Incorrect Option Choice Entered, Please Re-Enter One of the Choices Above i.e 1-7" << endl;
		cin >> userOption;
	}

	switch(userOption)
	{

	case 1:
		cout << "Please Enter the Name of the Book being Searched For: " << endl;
		cin.ignore();
		getline(cin, userData);
		userData2 = userData;
		bt.searchForBookNames(userData2);	
		break;

	case 2:
		bt.printBookNames();
		break;

	case 3:
		bt.printCatalog(book);
		break;
	
	case 4:
		cout << "Please Enter the Name of the Book being Searched For: " << endl;
                cin.ignore();
		getline(cin, userData);
		bt.searchForAvailability(userData, book);
		break;

	case 5:
		loanABook();
		break;

	case 6:
		returnABook();
		break;

	case 7:
		cout << "Thank You for Using Your Neighborhood Library! Goodbye!!" << endl;
		break;
	}
	}
	while(userOption != 7);

}
