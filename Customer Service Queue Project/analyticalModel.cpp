#include "analyticalModel.h"


AnalyticalModel::AnalyticalModel(int lambda, int mu, int numOfServers)
{
	this->lambda = lambda;
	this->mu = mu;
	this->M = numOfServers;
	this->Po = 0;
	this->L = 0;
	this->W = 0;
	this->Lq = 0;
	this->Wq = 0;
	this->rho = 0;
}


void AnalyticalModel::showStatistics()
{
	cout << "Lambda = " << lambda << endl;
	cout << "mu = " << mu << endl;
	cout << "M = " << M << endl << endl;

	calculatePercentIdleTime();
	calculateAvgNumInSystem();
	calculateAvgTimeInSystem();
	calculateAvgNumInQueue();
	calculateAvgWaitInQueue();
	calculateRho();
	cout << "Po = " << Po << endl;
	cout << "L = " << L << endl;
	cout << "W = " << W << endl;
	cout <<"Lq = " << Lq << endl;
	cout <<"Wq = " << Wq << endl;
	cout << "Rho = " << rho << endl;
}


void AnalyticalModel::calculatePercentIdleTime()
{
	float formulaPart1, formulaPart2;

	for(int i = 0; i <= M - 1; i++)
	{
		formulaPart1 += ((1 / (double)factorial(i)) * pow((lambda / (double)mu), i));
	}

	formulaPart2 = (1 / (double)factorial(M)) * pow((lambda / (double)mu), M) * ((M * mu) / (double)(M * mu - lambda));
	
	this->Po = (1 / (formulaPart1 + formulaPart2));
}


void AnalyticalModel::calculateAvgNumInSystem()
{
	float formulaPart1, formulaPart2, formulaPart3, formulaPart4;

	formulaPart1 = (lambda * mu * pow(lambda / (double) mu, M));
	
	formulaPart2 = (factorial(M-1) * pow((M * mu - lambda), 2));

	formulaPart3 = this->Po;

	formulaPart4 = (lambda / (double) mu);

	this->L = ((formulaPart1 / formulaPart2) * formulaPart3 + formulaPart4);
}


void AnalyticalModel::calculateAvgTimeInSystem()
{
	this->W = (L / lambda);
}


void AnalyticalModel::calculateAvgNumInQueue()
{
	float formulaPart1 = (lambda / (double)mu);

	this->Lq = (L - formulaPart1);
}


void AnalyticalModel::calculateAvgWaitInQueue()
{
	this->Wq = (Lq / lambda);
}


void AnalyticalModel::calculateRho()
{
	this->rho = (lambda / (double)(M * mu));
}


int AnalyticalModel::factorial(int num)
{
	if(num == 0)
	{
		return 1;
	}	

	if(num == 1)
	{
		return num;
	}

	else
	{
		return num * factorial(num - 1);
	}
}
