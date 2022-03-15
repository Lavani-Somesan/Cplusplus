/***************************************************************
 * File Name: analyticalModel.h
 *
 * This class  is a completely private class that processes the
 * statistics of different mathamatical models. The AnalyticalModel
 * class takes in lambda, mu, and number of Servers as arguments
 * to calculate the statistical models for Po, L, W, Lq, Wq, and rho.
 * This is used in the Service class to show the analytical model
 * compared to the simulated results.
 ***************************************************************/

#ifndef ANALYTICALMODEL_HPP
#define ANALYTICALMODEL_HPP

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;



class AnalyticalModel {

	friend class Service;

	private:

		float Po;
		float L;
		float W;
		float Lq;
		float Wq;
		float rho;
		int lambda;
		int mu;
		int M;

		AnalyticalModel(int lambda, int mu, int numOfServers);

		void showStatistics();
	
		void calculatePercentIdleTime();
		void calculateAvgNumInSystem();
		void calculateAvgTimeInSystem();
		void calculateAvgNumInQueue();
		void calculateAvgWaitInQueue();
		void calculateRho();
		int factorial(int num);
};


#endif

