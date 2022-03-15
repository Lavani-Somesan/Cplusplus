#include "geneticAlgorithm.hpp"
#include "graph.hpp"
#include "tour.hpp"

GeneticAlgorithm::GeneticAlgorithm(int numCities, int numTours, int numGenerations, double mutationPercent)
{
	this->numCitiesPerTour = numCities;
	this->numToursPerGen = numTours;
	this->numGenerations = numGenerations;
	this->mutationPercent = mutationPercent;
	
	this->tourCount = 0;	
	this->tour = new Tour[numTours];

	this->generation = new Generation[numGenerations];
	this->generationCount = 0;

	this->numMutations = numTours - NUM_ELITES;
	this->numMutations = round(numMutations * mutationPercent);
	this->permutationsLeft = numTours - NUM_ELITES - numMutations;
	this->geneticAlgorithmCost = 0.0;
	
	createOriginalTourSequence();
}



void GeneticAlgorithm::createOriginalTourSequence()
{
	for(int i = 0; i < numCitiesPerTour; i++)
	{
		tourSequence.push_back(i);
	}

	tour[tourCount].createTour(tourSequence);
	
	tourVector.push_back(tour[tourCount]);
	tourCount++;
}



void GeneticAlgorithm::deallocateArray()
{
	delete[] tour;
	tourCount = 0;
}



void GeneticAlgorithm::reallocateArray()
{
	this->tour = new Tour[numToursPerGen];
}



void GeneticAlgorithm::reinitializeArray()
{
	 for(int i = 0; i < numGenerations; i++)
	{
		generation[i].setToursPerGen(numToursPerGen);
		generation[i].setCitiesPerTour(numCitiesPerTour);
	}
}



void GeneticAlgorithm::permutation(int permsThisCall)
{
	int m, k, p, q, i;

	for(i = 1; i < permsThisCall; i++)
	{
		m = numCitiesPerTour - 2;

		while(tourSequence.at(m) > tourSequence.at(m+1))
		{
			m = m -1;
		}

		k = numCitiesPerTour - 1;

		while(tourSequence.at(m) > tourSequence.at(k))
		{
			k = k -1;
		}
		swap(tourSequence.at(m), tourSequence.at(k));

		p = m + 1;
		q = numCitiesPerTour - 1;

		while(p < q)
		{
			swap(tourSequence.at(p), tourSequence.at(q));
			p++;
			q--;
		}

		if(generationCount > 0)
		{
			tour[tourCount].createTour(tourSequence);
			tourVector.push_back(tour[tourCount]);
			generation[generationCount].addTour(tourVector.at(tourCount));
			tourCount++;
		}
		else
		{
		tour[tourCount].createTour(tourSequence);
		tourVector.push_back(tour[tourCount]);	
		tourCount++;
		}
	}
}


void GeneticAlgorithm::mutation(int index)
{
	for(int i = 0; i < numCitiesPerTour; i++)
	{
		tourSequence.at(i) = generation[generationCount - 1].getTour(index).getIndexValue(i);
	}

	mutateTour();
}



void GeneticAlgorithm::mutateTour()
{
	int lastIndex = numCitiesPerTour - 1;
	int firstIndex = 0;

	while(lastIndex / 2 != firstIndex || lastIndex % 2 != firstIndex)
	{
		swap(tourSequence.at(lastIndex / 2), tourSequence.at(lastIndex));
		lastIndex = lastIndex - 1;
	}	

	
	tour[tourCount].createTour(tourSequence);
	tourVector.push_back(tour[tourCount]);
	generation[generationCount].addTour(tourVector.at(tourCount));
	
	tourCount++;
}


void GeneticAlgorithm::computeGeneration1()
{	
	permutation(numToursPerGen);

	for(int i = 0; i < numToursPerGen; i++)
	{
		generation[generationCount].addTour(tourVector.at(i));
	}

	
	generation[generationCount].determineEliteTours();
	generationCount++;
}


void GeneticAlgorithm::computeGenerationN()
{
	int countMutations = 0;
	int countTourIndex = 0;

	generation[generationCount].addTour(generation[generationCount-1].getElite1());
	generation[generationCount].addTour(generation[generationCount-1].getElite2());


	while(countMutations < numMutations && countTourIndex < numToursPerGen)
	{
			mutation(countMutations);
			countMutations++;
			countTourIndex++;
	}	
	

	if(permutationsLeft > 0)
	{
		permutation(permutationsLeft + 1);
	}

	generation[generationCount].determineEliteTours();
}


void GeneticAlgorithm::computeGeneticAlgorithm()
{

	reinitializeArray();
	computeGeneration1();

	deallocateArray();
	reallocateArray();
	reinitializeArray();


	while(generationCount < numGenerations)
	{
		computeGenerationN();
		generationCount++;

		deallocateArray();
		reallocateArray();
		reinitializeArray();
	}
	
	deallocateArray();

	this->geneticAlgorithmCost = generation[numGenerations - 1].getElite1().getTourCost();
}



double GeneticAlgorithm::getGeneticAlgorithmCost()
{
	return geneticAlgorithmCost;
}



void GeneticAlgorithm::displayCurrTourSequence()
{
	for(int i = 0; i < numCitiesPerTour; i++)
	{
		cout << tourSequence.at(i) << "  ";
	}
	cout << "0  " << endl << endl;
}

