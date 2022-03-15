/***************************************************************
 * File Name: generation.hpp
 * 
 * This class is a completely private class that holds information 
 * about a Generation. The Generation class holds the number of 
 * tours in a generation and stores the two best tours that have 
 * the best tour cost. The Generation class can add tours and can 
 * determine which of those tours are elite. This class is called
 * and used by the GeneticAlgorithm class in order to generate 
 * generations and add tours to them.
 ***************************************************************/

#ifndef GENERATION_HPP
#define GENERATION_HPP

#include "tour.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Generation {

	friend class GeneticAlgorithm;

	private:
		Tour elite1;
		Tour elite2;
		vector<Tour> tourVector;
		int numToursPerGen;
		int numCitiesPerTour;
		int tourCount;

		Generation();

		void setElite1(int index);
		void setElite2(int index);
		void setToursPerGen(int numToursPerGen);
		void setCitiesPerTour(int numCitiesPerTour);
		
		Tour getElite1();
		Tour getElite2();
		Tour getTour(int index);

		void addTour(Tour tour);
		void determineEliteTours();

};



#endif 
