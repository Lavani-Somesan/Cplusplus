#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <ctime>
using namespace std;

#include "ledgerClass.h"



void Ledger::AddTransaction(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column) {
	
	int exitLoop = 0;

	//Prints out transactions	
	for(int i=0; i < row; i++) {
	if(transID[i] != -1 && transID[i] != -2) {
	cout << i+1 << ". " << transID[i] << " " << name[i] << endl;
	}
	}

	cout << endl;
	
	//Checks to see if Ledger is full or not
	if(transID[row-1] == -1) {
	
	//User inputs time of transaction
	for(int i=0; i < row; i++) {
	
	//Gets out of the loop
	if(exitLoop == 1) {
	break;
	}
	//User Enters Time 
	for(int j = 0; j < column; j = j+column) {
	if(timeArr[i][j] == -1) {
	cout << "Please input the time as three integers for hour, minute and second separated by space: ";
   	cin >> timeArr[i][j] >> timeArr[i][j+1] >> timeArr[i][j+2];
    	
	//User Validation for Hour
	while(timeArr[i][j] < 0 || timeArr[i][j] > 24) {
	cout << "Please Enter an Hour between 0 and 24. " << endl;
	cin >> timeArr[i][j];
	cout << endl;
	}
	
	//User Validation for Minute
	while(timeArr[i][j+1] < 0 || timeArr[i][j+1] > 59) {
	cin >> timeArr[i][j+1];
	cout << endl;
	}
	
	//User Validation for Second
	while(timeArr[i][j+2] < 0 || timeArr[i][j+2] > 59) {
        cin >> timeArr[i][j+2];
	cout << endl;
        }
	cout << endl;
	++exitLoop;
	break;
	}
	}
	}

	exitLoop = 0;
	
	//User inputs cost price and selling price of transaction
	for(int i=0; i < row; i++) {
	//Gets out of outer loop
	if(exitLoop == 1) {
	break;
	}
	
	//Inputs cost and selling prices of item
        for(int j = 0; j < column; j = j+column) {
        if(price[i][j] == -1) {
        cout << "Please Input the Cost Price of the Item: ";
        cin >> price[i][j];
	cout << endl;

	cout << "Please Input the Selling Price of the Item: ";
	cin >> price[i][j+1];
        cout << endl;

	//User validation to make sure Selling price is > than Cost price
	while(price[i][j+1] <=  price[i][j]) {
	cout << "Please Input the Selling Price Higher than the Cost Price." << endl;
	cin >> price[i][j+1];
	cout << endl;
	}

	//Holds Profit (Selling - Cost)
	price[i][j+2] = price[i][j+1] - price[i][j];

        ++exitLoop;
	break;
        }
        }
        }

	//User enters item's name
   	for(int i=0; i < row; i++) {
	if(name[i] == "noName") {
	cout << "Please enter the item's name. " << endl;
	getline(cin, name[i]);
	getline(cin, name[i]);
	break;
	}
	}

	//Ensures Number is Random every compilation
    	srand(time(NULL));
	cout << endl;
   
	//Generates Random Transaction ID Number
	for(int i=0; i < row; i++) {
    	if(transID[i] == -1) {
	transID[i] = (rand()%100000)+1; 
	break;
	}
	}
	cout << "Transaction Added Successfully" << endl;
	}

	else {
	cout << "Transaction Failed, You Have Reached Maximum Transactions That Can Be Added" << endl;
	}

} //End of AddTransaction Function



void Ledger::VoidTransaction(int transID[], string name[],  const int row) {

	int choice;
	int empty = 0;

	//Checks to see if Ledger is empty
	for(int i=0; i < row; i++) {
        if(transID[i] == -1 || transID[i] == -2) {
	empty = empty +1;      
	}
	}
	
	if(empty == row) { 
	cout << "There Are No Transactions In Ledger That Can Be Voided" << endl;
        }
       

	//Can only void a Transaction if there are transactions availabe to void
	for(int i=0; i < row; i++) {
	if(transID[i] != -1 && transID[i] != -2) {

	for(int i=0; i < row; i++) {
        if(transID[i] != -1 && transID[i] != -2) {
        cout << i+1 << ". " << transID[i] << " " << name[i] << endl;
        }
        }
	cout << endl;
	
	cout << "Choose Which Transaction You Would Like To Void. " << endl;
	cin >> choice;
	
	choice = choice -1;

	while(transID[choice] == -1 || transID[choice] == -2) {
	cout << "Please Enter a Number Listed on the Screen" << endl;
	cin >> choice;
	choice = choice -1;
	}
	
	//Assign ID to -2 so if matched when priting summary it will print VOID
	transID[choice] = -2;
	
	cout << "Transaction Voided Successfully" << endl;
	break;
	}
	}
	


} //End of VoidTransaction Function




 void Ledger::printDetailsByID(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column) {

	int m,k;
	int temp, temp6, temp7, temp8;
	string temp3;
	double temp2, temp4, temp5;
	int size = 0;
	int counter = 1;
	double totalProfit;
	
	if(name[0] != "noName") {

	//Loop to get size for copy transaction ID array
	for(int i=0; i < row; i++) {
	if(name[i] != "noName") {
	++size;
	}
	}

	//Declare a Id array to hold transID that are not void or empty
	int iD[size];
	string itemName[size];
        double cost[size];
        double sell[size];
        double profit[size];
        int hour[size];
        int min[size];
        int sec[size];

	
	//Copies main arrays to copy arrays
        for(int i=0; i < row; i++) {
        if(name[i] != "noName") {
        itemName[i] = name[i];
        iD[i] = transID[i];
        cost[i] = price[i][0];
        sell[i] = price[i][1];
        profit[i] = price[i][2];
        hour[i] = timeArr[i][0];
        min[i] = timeArr[i][1];
        sec[i] = timeArr[i][2];
        }
        }


	//Sort iD Array
	for(k=0; k < size; k++) {
	m = k;
	while(m > 0 && iD[m] < iD[m-1]) { 
	
	temp = iD[m];
	iD[m] = iD[m-1];
	iD[m-1] = temp;

	temp3 = itemName[m];
        itemName[m] = itemName[m-1];
        itemName[m-1] = temp3;

        temp2 = profit[m];
        profit[m] = profit[m-1];
        profit[m-1] = temp2;


        temp4 = cost[m];
        cost[m] = profit[m-1];
        cost[m-1] = temp4;

        temp5 = sell[m];
        sell[m] = profit[m-1];
        sell[m-1] = temp5;


        temp6 = hour[m];
        hour[m] = hour[m-1];
        hour[m-1] = temp6;

        temp7 = min[m];
        min[m] = min[m-1];
        min[m-1] = temp7;

        temp8 = sec[m];
        sec[m] = sec[m-1];
        sec[m-1] = temp8;

	--m;
	}
	}	

	//Gets total Profit
	for(int i=0; i < size; i++) {
	if(iD[i] != -2) {
        totalProfit += profit[i];
        }
        }
	
	
        cout << endl;
        cout << setprecision(2);
        cout << fixed;
	
	//Gets Current Time and Date
	time_t now = time(0);
        char* dt = ctime(&now);


        cout << right << setw(67) <<  "-=| LEDGER |=-" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << dt << endl;
        cout << "VOID -> Transaction was Cancelled" << endl;
        cout << endl << endl;;

        cout << left << setw(15) << "ID";
        cout << right << setw(8) << "Item Name";
        cout << right << setw(27) << "Time Purchased";
        cout << right << setw(21) << "Cost";
        cout << right << setw(20) << "Selling Price";
        cout << right << setw(10) << "Profit";
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

        for(int i=0; i < size; i++) {

        cout << counter << ". ";
	if(iD[i] != -2) {
	cout << left << setw(15) << iD[i];
	}
	else {
	cout << left << setw(15) << "VOID";
	}
        cout << right << setw(4) << itemName[i];
        cout << right << setw(10) << hour[i] << " hrs.";
        cout << right << setw(4) << min[i] << " min.";
        cout << right << setw(4) << sec[i] << " sec.";
        cout << right << setw(12) <<  "$" << cost[i];
        cout << right << setw(10) << "$" <<  sell[i];
        cout << right << setw(10) << "$" <<  profit[i];
        cout << "\n" << endl;
        ++counter;
        }



        cout << endl << endl;
        cout << right << setw(99) << "Total Profit:  $" << totalProfit << endl;

	

	}//End of if statement 

	else {
	cout << "There are No Transactions To Print Out" << endl;
	}


} //End of printDetailsByID Function


 void Ledger::printDetailsByName(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column) {
	
	int l, m;
	string temp;
	int temp3, temp6, temp7, temp8; 
	double temp2, temp4, temp5;
	int counter = 1;
	int size = 0;
	double totalProfit;

	if(name[0] != "noName") {

	//Gets size for copy string array
	for(int i=0; i < row; i++) {
	if(name[i] != "noName") {
	++size;
	}
	}

	//Declare copy string array
	string itemName[size];
	int iD[size];
	double cost[size];
	double sell[size];
	double profit[size];
	int hour[size];
	int min[size];
	int sec[size];


	for(int i=0; i < row; i++) {
	if(name[i] != "noName") {
	itemName[i] = name[i];
	iD[i] = transID[i];
        cost[i] = price[i][0];
        sell[i] = price[i][1];
        profit[i] = price[i][2];
        hour[i] = timeArr[i][0];
        min[i] = timeArr[i][1];
        sec[i] = timeArr[i][2];
	}
	}

	//Sorting Name Copy Array
	for(l=0; l < size; l++) {
	m = l;
	while( m > 0 && name[m].at(0) < name[m-1].at(0)) {
        //Sorts Names
	temp = itemName[m];
        itemName[m] = itemName[m-1];
        itemName[m-1] = temp;

	temp2 = profit[m];
        profit[m] = profit[m-1];
        profit[m-1] = temp2;

        temp3 = iD[m];
        iD[m] = iD[m-1];
        iD[m-1] = temp3;

        temp4 = cost[m];
        cost[m] = profit[m-1];
        cost[m-1] = temp4;

        temp5 = sell[m];
        sell[m] = profit[m-1];
        sell[m-1] = temp5;


        temp6 = hour[m];
        hour[m] = hour[m-1];
        hour[m-1] = temp6;

        temp7 = min[m];
        min[m] = min[m-1];
        min[m-1] = temp7;

        temp8 = sec[m];
        sec[m] = sec[m-1];
        sec[m-1] = temp8;

        --m;
        }
        }
	


	//Calculates Total Profit
	for(int i=0; i < size; i++) {
	if(iD[i] != -2) {
	totalProfit += profit[i];
	}
	}
	
	cout << endl;
        cout << setprecision(2);
        cout << fixed;

	//Gets Current Date and Time
	time_t now = time(0);
        char* dt = ctime(&now);

	//Prints out Ledger
        cout << right << setw(67) <<  "-=| LEDGER |=-" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << dt << endl;
        cout << "VOID -> Transaction was Cancelled" << endl;
        cout << endl << endl;;

        cout << left << setw(15) << "ItemName";
        cout << right << setw(8) << "ID";
        cout << right << setw(27) << "Time Purchased";
        cout << right << setw(21) << "Cost";
        cout << right << setw(20) << "Selling Price";
        cout << right << setw(10) << "Profit";
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

        for(int i=0; i < size; i++) {

        cout << counter << ". ";

        cout << left << setw(15) << itemName[i];
        if(iD[i] != -2) {
        cout << right << setw(6) << iD[i];
        }
        else {
        cout << right << setw(6) << "VOID";
        }
        cout << right << setw(10) << hour[i] << " hrs.";
        cout << right << setw(4) << min[i] << " min.";
        cout << right << setw(4) << sec[i] << " sec.";
        cout << right << setw(10) <<  "$" << cost[i];
        cout << right << setw(10) << "$" <<  sell[i];
        cout << right << setw(10) << "$" <<  profit[i];
	cout << "\n" << endl;
        ++counter;
        }

        cout << endl << endl;
        cout << right << setw(97) << "Total Profit:  $" << totalProfit << endl;




}

	else {
	cout << "There are No Transactions To Print Out" << endl;
	}
	

} //End of printDetailsByName Function


 void Ledger::printDetailsByProfit(int timeArr[][3], double price[][3], int transID[], string name[], const int row, const int column) {
	
	if(name[0] != "noName") {
	
	int l,m;
	int size = 0;
	double temp, temp4, temp5;
	int temp3, temp6, temp7, temp8;
	string temp2;
	int counter = 1;
	double totalProfit;
	
	//Gets size for copy array
	for(int i=0; i < row; i++) {
	if(name[i] != "noName") {
	++size;
	}
	}

	//Declares Copy array
	double profit[size];
	double sell[size];
	double cost[size];
	string itemName[size];
	int iD[size];
	int hour[size];
	int min[size];
	int sec[size];

	//copies price array to profit array 
	for(int i=0; i < row; i++) {
        if(name[i] != "noName" ) {
	itemName[i] = name[i];
        iD[i] = transID[i];
        cost[i] = price[i][0];
        sell[i] = price[i][1];
        profit[i] = price[i][2];
        hour[i] = timeArr[i][0];
        min[i] = timeArr[i][1];
        sec[i] = timeArr[i][2];
        }
	}

	//Sorting profit array
	for(l=0; l < size; l++) {
        m = l;
        while( m > 0 && profit[m] < profit[m-1]) {
        
	temp = profit[m];
        profit[m] = profit[m-1];
        profit[m-1] = temp;
        
	temp2 = itemName[m];
        itemName[m] = itemName[m-1];
        itemName[m-1] = temp2;

        temp3 = iD[m];
        iD[m] = iD[m-1];
        iD[m-1] = temp3;

        temp4 = cost[m];
        cost[m] = profit[m-1];
        cost[m-1] = temp4;

        temp5 = sell[m];
        sell[m] = profit[m-1];
        sell[m-1] = temp5;


        temp6 = hour[m];
        hour[m] = hour[m-1];
        hour[m-1] = temp6;

        temp7 = min[m];
        min[m] = min[m-1];
        min[m-1] = temp7;

        temp8 = sec[m];
        sec[m] = sec[m-1];
        sec[m-1] = temp8;

	--m;
        }
        }
	cout << endl;

	//Total Profit 
	for(int i=0; i < size; i++) {
	if(iD[i] != -2) {
	totalProfit += profit[i];
	}
	}

	cout << endl;
	cout << setprecision(2);
	cout << fixed;
	
	//Gets Current Date and Time
	time_t now = time(0);
	char* dt = ctime(&now);
	
	
	cout << right << setw(67) <<  "-=| LEDGER |=-" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << dt << endl;
	cout << "VOID -> Transaction was Cancelled" << endl;
	cout << endl << endl;;
	
        cout << left << setw(15) << "Profit";
	cout << right << setw(8) << "ID";
	cout << right << setw(20) << "Item Name";
        cout << right << setw(25) << "Time Purchased";
        cout << right << setw(20) << "Cost";
        cout << right << setw(20) << "Selling Price";
	cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

        for(int i=0; i < size; i++) {
        
	cout << counter << ". $"; 
	
	cout << left << setw(15) <<  profit[i];
	if(iD[i] != -2) {
	cout << right << setw(6) << iD[i];
	}
	else {
	cout << right << setw(6) << "VOID";
	}
        cout << right << setw(16) << itemName[i];
	cout << right << setw(10) << hour[i] << " hrs.";
        cout << right << setw(4) << min[i] << " min.";
        cout << right << setw(4) << sec[i] << " sec.";
        cout << right << setw(10) <<  "$" << cost[i];
        cout << right << setw(10) << "$" <<  sell[i];
        cout << "\n" << endl;
        ++counter;
        
        }

	cout << endl << endl;
	cout << right << setw(100) << "Total Profit:  $" << totalProfit << endl;

	}
	
	else {
	cout << "There are No Transactions To Print Out" << endl;
	}


} //End of printDetailsByProfit Function


