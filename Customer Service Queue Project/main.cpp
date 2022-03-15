#include "customer.h"
#include "priorityQueue.h"
#include "fifoQueue.h"
#include "service.h"
#include "analyticalModel.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;



int main()
{
	
	srand(time(NULL));

	int n = 0;
	int lambda = 0;
	int mu = 0;
	int M = 0;
	const int MIN_ARV = 1000;
	const int MAX_ARV = 5000;
	const int MIN_CHANNELS = 1;
	const int MAX_CHANNELS = 10;

	cout << "Please Enter the Number of Arrivals to Simulate between 1000 to 5000" << endl;
	cin >> n;

	while(n < MIN_ARV || n > MAX_ARV)
	{
		cout << "Please ReEnter the Number of Arrivals to Simulate between 1000 to 5000" << endl;
		cin >> n;
	}
	cout << endl;

	cout << "Please Enter the Average Number of Arrivals in a Time Period between 1 and " << MAX_ARV <<  endl;
	cin >> lambda;

	while(lambda < 1 || lambda > MAX_ARV)
	{
		cout << "Please Enter the Average Number of Arrivals in a Time Period between 1 and 50" << endl;
		cin >> lambda;
	}
	cout << endl;

	cout << "Please Enter the Average Number Served in a Time Period" << endl;
	cin >> mu;
	cout << endl;

	cout << "Please Enter the Number of Service Channels between 1 to 10" << endl;
	cin >> M;

	while(M < MIN_CHANNELS || M > MAX_CHANNELS)
	{
		cout << "Please ReEnter the Number of Service Channels between 1 to 10" << endl;
		cin >> M;
	}
	cout << endl << endl;


	Service service(n, lambda, mu, M);
	service.commenseService();

	return 0;
}
