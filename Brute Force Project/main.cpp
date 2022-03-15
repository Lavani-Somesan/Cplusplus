#include "graph.hpp"
#include "tour.hpp"
#include "geneticAlgorithm.hpp"
#include "generation.hpp"
#include "bruteForce.hpp"
#include "timer.hpp"

#include <iostream>
#include <vector>
using namespace std;



int main()
{
	int numCities;
	const int MIN_CITY = 1;
	const int MAX_CITY = 20;
	int numTours;
	const int MIN_TOURS = 3;
	const int MAX_TOURS = 120;
	int numGenerations;
	const int MIN_GEN = 2;
	const int MAX_GEN = 120;
	double mutationPercent;
	const double MIN_PERCENT = 0.0;
	const double MAX_PERCENT = 1.00;

	cout << "Please Enter The Number of Cities Per Tour Between " << MIN_CITY << " and " << MAX_CITY <<  endl;
	cin >> numCities;

	while(numCities < MIN_CITY || numCities > MAX_CITY)
	{
		cout << "Please Enter The Number of Cities Per Tour Between " << MIN_CITY << " and " << MAX_CITY <<  endl;
		cin >> numCities;
	}
	

	cout << "Please Enter the Number of Tours Per Generation Between " << MIN_TOURS << " and " << MAX_TOURS << endl;
	cin >> numTours;

	while(numTours < MIN_TOURS || numTours > MAX_TOURS)
	{
		cout << "Please Enter the Number of Tours Per Generation Between " << MIN_TOURS << " and " << MAX_TOURS << endl;
		cin >> numTours;
	}


	cout << "Please Enter the Number of Generations You Want to Generate Between " << MIN_GEN << " and " << MAX_GEN <<  endl;
	cin >> numGenerations;

	while(numGenerations < MIN_GEN || numGenerations > MAX_GEN)
	{
		cout << "Please Enter the Number of Generations You Want to Generate Between " << MIN_GEN << " and " << MAX_GEN <<  endl;
		cin >> numGenerations;
	}


	cout << "Please Enter the Percent of Mutation You Want Each Generation to Have Between " << MIN_PERCENT << " and " << MAX_PERCENT << endl;
	cin >> mutationPercent;

	while(mutationPercent < MIN_PERCENT || mutationPercent > MAX_PERCENT)
	{
		cout << "Please Enter the Percent of Mutation You Want Each Generation to Have Between " << MIN_PERCENT << " and " << MAX_PERCENT << endl;
		cin >> mutationPercent;
	}

	Timer timer;
	BruteForce bf(numCities);
	GeneticAlgorithm ga(numCities, numTours, numGenerations, mutationPercent);
	
	timer.computeTime(bf, ga);

	cout << endl;
	cout << "Number of Cities: " << numCities << endl;
	cout << "Optimal Cost of Brute Force: " << bf.getBruteForceCost() << endl;
	cout << "Time the Bruce Force Algorithm Took: " << timer.getBruteForceTime() << " milliseconds" <<  endl;
	cout << "Cost From the Genetic Algorithm: " << ga.getGeneticAlgorithmCost() << endl;
	cout << "Time the Genetic Algorithm Took: " << timer.getGeneticAlgorithmTime() << " milliseconds" << endl;
	cout << "Percent of Optimal: " << ga.getGeneticAlgorithmCost() / bf.getBruteForceCost() << endl;

	return 0;
}
