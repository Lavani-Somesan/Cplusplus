#ifndef LEDGERCLASS_H
#define LEDGERCLASS_H


class Ledger {

	public: 

	//Constructor
	//Ledger();
	
	void AddTransaction(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column);
        void VoidTransaction(int transID[], string name[], const int row);
	void printDetailsByID(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column);
	void printDetailsByName(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column);
	void printDetailsByProfit(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column);
	
	private:
	int t[10][3];
	double prices[10][3];
	int transitionID[10];
	string names[10];


};

#endif
		

