#include "generation.hpp"
#include "tour.hpp"


Generation::Generation()
{
	this->tourCount = 0;
}



void Generation::setToursPerGen(int numToursPerGen)
{
	this->numToursPerGen = numToursPerGen;
}



void Generation::setCitiesPerTour(int numCitiesPerTour)
{
	this->numCitiesPerTour = numCitiesPerTour;
}



void Generation::addTour(Tour tourObj)
{
	if(tourCount < numToursPerGen)
	{
		tourVector.push_back(tourObj);
	}
}



void Generation::setElite1(int index)
{
	elite1 = tourVector.at(index);
}


void Generation::setElite2(int index)
{
	elite2 = tourVector.at(index);
}


Tour Generation::getElite1()
{
	return elite1;
}


Tour Generation::getElite2()
{
	return elite2;
}



Tour Generation::getTour(int index)
{
	return tourVector.at(index);
}


void Generation::determineEliteTours()
{
	double minCost1;
	double minCost2;

	if(tourVector.at(0).getTourCost() < tourVector.at(1).getTourCost())
	{
		minCost1 = tourVector.at(0).getTourCost();
		minCost2 = tourVector.at(1).getTourCost();
	}

	else
	{	
		minCost1 = tourVector.at(1).getTourCost();
		minCost2 = tourVector.at(0).getTourCost();
	}

	for(int i = 0; i < numToursPerGen; i++)
	{
		if(minCost1 > tourVector.at(i).getTourCost())
		{
			minCost2 = minCost1;
			minCost1 = tourVector.at(i).getTourCost();
		}

		else if(tourVector.at(i).getTourCost() < minCost2 && tourVector.at(i).getTourCost() != minCost1)
		{
			minCost2 = tourVector.at(i).getTourCost();
		}
	}

	for(int i = 0; i < numToursPerGen; i++)
	{
		if(minCost1 == tourVector.at(i).getTourCost())
		{
			tourVector.at(i).setElite(true);
			setElite1(i);
		}

		else if(minCost2 ==  tourVector.at(i).getTourCost())
		{
			tourVector.at(i).setElite(true);
			setElite2(i);
		}
	}
}
