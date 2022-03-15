/***************************************************************
 * Student Name: Lavani Somesan
 * File Name: timer.hpp
 * Assignment number: Project #3
 * 
 * This class is a completely holds information about a Timer.
 * The Timer class computes the length of time it takes to 
 * compute the Brute Force algorithm and the Genetic Algorithm.
 * Once it has caluclated the times for each algorithm it stores
 * each time. Calculates time in milliseconds.
 ***************************************************************/

#ifndef TIMER_HPP
#define TIMER_HPP

#include "bruteForce.hpp"
#include "geneticAlgorithm.hpp"

#include <iostream>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  
#include <chrono>
using namespace std;
using namespace std::chrono;


class Timer {

	private:
		long int bruteForceTime;
		long int geneticAlgorithmTime;

	public:
		Timer();
		void computeTime(BruteForce &bf, GeneticAlgorithm &ga);
		long int getBruteForceTime();
		long int getGeneticAlgorithmTime();
};


#endif
