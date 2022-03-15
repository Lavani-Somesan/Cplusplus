#include "timer.hpp"
#include "bruteForce.hpp"
#include "geneticAlgorithm.hpp"

Timer::Timer()
{
	bruteForceTime = 0;
	geneticAlgorithmTime = 0;
}


void Timer::computeTime(BruteForce &bf, GeneticAlgorithm &ga)
{
	auto start = high_resolution_clock::now();

	bf.computeBruteForce();

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start); 
	
	this->bruteForceTime = duration.count();	

	
	auto start1 = high_resolution_clock::now();

	ga.computeGeneticAlgorithm();

	auto stop1 = high_resolution_clock::now();

	auto duration1 = duration_cast<microseconds>(stop1 - start1);

	this->geneticAlgorithmTime = duration1.count();
}


long int Timer::getBruteForceTime()
{
	return bruteForceTime;
}


long int Timer::getGeneticAlgorithmTime()
{
	return geneticAlgorithmTime;
}


