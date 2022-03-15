#include "bruteForce.hpp"
#include "graph.hpp"

BruteForce::BruteForce(int numCities)
{
	this->numCities = numCities;
	this->permsThisCall = factorial(numCities - 1);
	this->tourCount = 0;
	this->tourCost = 0;
	this->bruteForceCost = 0;

	createTourSequence();
}



void BruteForce::createTourSequence()
{
	for(int i = 0; i < numCities; i++)
	{
		tourSequence.push_back(i);	
	}
}


int BruteForce::factorial(int num)
{
	if(num == 0)
	{
		return 1;
	}

	if( num == 1)
	{
		return num;
	}

	else
	{
		return num * factorial(num - 1);
	}
}


void BruteForce::permutation()
{
	int m, k, p, q, i;

	for( i = 1; i < permsThisCall; i++)
	{
		m = numCities - 2;

		while(tourSequence.at(m) > tourSequence.at(m+1))
		{
			m = m - 1;
		}

		k = numCities - 1;

		while(tourSequence.at(m) > tourSequence.at(k))
		{
			k = k -1;
		}

		swap(tourSequence.at(m), tourSequence.at(k));
		p = m + 1;
		q = numCities - 1;

		while(p < q)
		{
			swap(tourSequence.at(p), tourSequence.at(q));
			p++;
			q--;
		}

		tourCost = graph.calculateTourSequenceCost(tourSequence, numCities);

		determineLowestTourCost(tourCost);
		tourCount++;
	}	
}



void BruteForce::computeBruteForce()
{
	permutation();

	this->bruteForceCost = minTourCost;
}


void BruteForce::determineLowestTourCost(double costOfTour)
{
	if(tourCount == 0)
	{
		minTourCost = costOfTour;
	}

	else if(costOfTour < minTourCost)
	{
		minTourCost = costOfTour;
	}		
}


double BruteForce::getBruteForceCost()
{
	return bruteForceCost;
}



void BruteForce::displayTourSequence()
{
	for(int i = 0; i < numCities; i++)
	{
		cout << tourSequence.at(i) << "  ";
	}
	cout << "0  " <<  endl;
}
