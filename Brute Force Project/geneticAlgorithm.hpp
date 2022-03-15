/***************************************************************
 * File Name: geneticAlgorithm.hpp
 * 
 * This class holds information about a Genetic Algorithm.
 * The GeneticAlgorithm class holds the number of cities per tour, 
 * the number of tours per generation, the number of generations,
 * and the percent of mutation in order to compute generations
 * that hold permuations of a sequence as well as mutations of
 * subsquent sequences. The GeneticAlgorithm class is mainly used
 * to compute the genetic algorithm.
 ***************************************************************/

#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include "graph.hpp"
#include "tour.hpp"
#include "generation.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



class GeneticAlgorithm {

	private:
		vector<Tour> tourVector;
		Generation *generation;
		Tour *tour;
		const int NUM_ELITES = 2;
		vector<int> tourSequence;
		int numCitiesPerTour;
		int numToursPerGen;
		int numGenerations;
		int numMutations;
		double mutationPercent;
		int tourCount;
		int generationCount;
		int permutationsLeft;
		double geneticAlgorithmCost;


		void permutation(int permsThisCall);
		void mutation(int index);
		void mutateTour();
		void createOriginalTourSequence();
		void computeGeneration1();
		void computeGenerationN();
		void deallocateArray();
		void reallocateArray();
		void reinitializeArray();
		

	public:
		GeneticAlgorithm(int numCities, int numTours, int numGenerations, double mutationPercent);
		void computeGeneticAlgorithm();
		double getGeneticAlgorithmCost();
		void displayCurrTourSequence();

};


#endif
