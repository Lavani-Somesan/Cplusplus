#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
using namespace std;

#include "ledgerClass.h"

int main() {

	//Variables 
	int choice;
	int option;
	const int ROW = 10;
	const int COLUMN = 3;
	//Arrays
	int time[ROW][COLUMN];
	double price[ROW][COLUMN];
	int transID[ROW];
	string itemName[ROW]; 

	
	for(int i=0; i < ROW; i++) {
	itemName[i] = "noName";
	transID[i] = -1;
	for( int j=0; j < COLUMN; j++) {
	time[i][j] = -1;
	price[i][j] = -1;
	}
	}


	Ledger ledger;



    do {
    cout << endl;
    cout << "Daily ledger managing system:" << endl;
    cout << "1. Add a transaction." << endl;
    cout << "2. Void a transaction." << endl;
    cout << "3. Print summary." << endl;
    cout << "4. Quit." << endl;
    cout << "Input your choice: ";
    
    cin >> choice;
    
    while (choice > 4 || choice <= 0) {
        cout << "Invalid choice. Input 1 to 4 only!" << endl;
        cout << "Input your choice: ";
        cin >> choice;
    }

        cout << endl;
        switch (choice) {
            case 1:
                ledger.AddTransaction(time, price, transID, itemName, ROW, COLUMN);
                break;
            case 2:
                ledger.VoidTransaction(transID, itemName, ROW);
                break;
            case 3:

        cout << "Choose How You Want to Sort Your Transactions" << endl;
        cout << "1. By Transaction ID" << endl;
        cout << "2. By Item Name" << endl;
        cout << "3. By Profit " << endl;
        cin >> option;

        while(option < 1 || option > 3) {
        cout << "Please Re-Enter Your Choice from 1 to 3" << endl;
        cin >> option;
        }

        switch(option) {

        case 1:
	  ledger.printDetailsByID(time, price, transID, itemName, ROW, COLUMN);
         break;
	
	case 2: 
	 ledger.printDetailsByName(time, price, transID, itemName, ROW, COLUMN);
	break;
	
	case 3:
	 ledger.printDetailsByProfit(time, price, transID, itemName, ROW, COLUMN);
	break;
	}
	break;
         
	   case 4:
                cout << "Thank you for using! Bye!" << endl;
		
        }
    } while (choice != 4);






}//End of main	
