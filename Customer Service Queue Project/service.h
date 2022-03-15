/***************************************************************
 * File Name: service.h
 *
 * This class runs a queue simulation of generated events.
 * The Service class takes in number of Arrivals, lambda, mu, and
 * number of servers from user input from main class. Then it 
 * generates a number of arrivals to put into the priority queue.
 * It will then proess each event and determine if they are arrivals
 * or departures or whether to put them into the fifo queue if the
 * priority queue is full. Will continue to generate arrival times
 * until there are no more arrivals to simulate. Will then display
 * the simulated results and compare them with the analytical model.
 ***************************************************************/

#ifndef SERVICE_H
#define SERVICE_H

#include "priorityQueue.h"
#include "fifoQueue.h"
#include "customer.h"
#include "analyticalModel.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h> 
using namespace std;

class Service {

	public:
		Service() { };
		Service(int numOfArrivals, int lambda, int mu, int numOfServers);
		void commenseService();

	private:
		int numOfArrivals;
		int lambda;
		int mu;
		int numOfServers;
		int arrivalType = 'A';
		int departureType = 'D';
		int serverAvailableCount;
		int customerArrivalIndex;
		float idleTime = 0;
		float lastDepartureTimeIdle = 0;
		float nextArrivalTimeIdle = 0;
		float totalWaitTime = 0;
		float totalServiceTime = 0;
		int numOfCustomersWaited = 0;
		Customer *customer;
		PriorityQueue priorityQueue;
		FifoQueue fifoQueue;
		int simulationIndex = 0;
		float totalLengthOfSimulation = 0;
		float lastDepartureInSimulation = 0;

		float getNextRandomInterval(int avg);
		void generateArrivals(int lambda, int sizeOfNumArrivals, int startingIndex, Customer customer[]);
		bool isServerAvailable();
		bool isMoreArrivals();
		void showStatistics();

		void processNextEvent();
		void processStatistics();
		void calculateIdleTime();
		void insertPriorityQueue(int startingIndex, int availalbePqSpace);
};


#endif
		
