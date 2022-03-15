/***************************************************************
 * Student Name: Lavani Somesan
 * File Name: bruteForce.hpp
 * Assignment number: Project #3
 * 
 * This class holds information about a Brute Force Algorithm.
 * The BruteForce class holds the number of cities and the minimum
 * tour cost. The BruteForce class takes the factorial of the
 * number of cities minus one and permutes them to get different
 * tour sequences. Then it looks at each cost of each sequence and
 * sets the lowest one the minimum tour cost. The BruteForce class
 * is mainly used to calculate the Brute Force algorithm.
  ***************************************************************/

#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

#include "graph.hpp"

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class BruteForce {

	private:
		Graph graph;
		vector<int> tourSequence;
		int numCities;
		int permsThisCall;
		int tourCount;
		double tourCost;
		double minTourCost;
		double bruteForceCost;
		

		void createTourSequence();
		int factorial(int num);
		void permutation();
		void determineLowestTourCost(double costOfTour);

	public:
		BruteForce(int numCities);

		void computeBruteForce();
		double getBruteForceCost();
		void displayTourSequence();

};


#endif
