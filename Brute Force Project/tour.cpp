#include "tour.hpp"
#include "graph.hpp"


Tour::Tour()
{
	this->eliteTour = false;
	this->costOfTour = 0;
		
}



void Tour::createTour(vector<int> array)
{
	for(unsigned int i = 0; i < array.size(); i++)
	{
		tours.push_back(array.at(i));
	}

	calculateTourCost();
}



void Tour::calculateTourCost()
{
	int size = tours.size();
	int row;
	int col;

	for(int i = 0; i < size; i++)
	{
		if( i == size - 1)
		{
			row = tours.at(i);
			col = 0;
			costOfTour += graph.getEdgeCost(row, col);
		}

		else
		{
			row = tours.at(i);
			col = tours.at(i + 1);
			costOfTour += graph.getEdgeCost(row, col);
		}
	}

}


double Tour::getTourCost()
{
	return costOfTour;
}




void Tour::setElite(bool eliteBool)
{
	if(eliteBool == true)
	{
		eliteTour = true;
	}

	else
	{
		eliteTour = false;
	}
}



bool Tour::isElite()
{
	if(eliteTour == true)
	{
		return true;
	}

	else
	{
		return false;
	}
}


int Tour::getIndexValue(int index)
{
	return tours.at(index);
}


void Tour::displayTour()
{
	for(unsigned int i = 0; i < tours.size(); i++)
	{
		cout << tours.at(i) << "  ";
	}
	cout << "0  " << endl << endl;
}
