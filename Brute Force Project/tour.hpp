/***************************************************************
 * File Name: tour.hpp
 * 
 * This class is a completely private class that holds information
 * about a Tour. The Tour class holds a tour's sequence, the cost
 * of the tour, or if it is an elite tour. The Tour class can 
 * calculate the cost of a tour. This class is used in the 
 * GeneticAlgorithm class to create tours for the Generation class
 * and get the cost of those tours.
 ***************************************************************/

#ifndef TOUR_HPP
#define TOUR_HPP

#include "graph.hpp"

#include <iostream>
#include <vector>
using namespace std;



class Tour {

	friend class Generation;
	friend class GeneticAlgorithm;

	private:
		Graph graph;
		vector<int> tours;
		double costOfTour;
		bool eliteTour;

		Tour();
		void createTour(vector<int> array);
		void calculateTourCost();
		double getTourCost();
		void setElite(bool elite);
		bool isElite();
		int getIndexValue(int index);
		void displayTour();
};



#endif


