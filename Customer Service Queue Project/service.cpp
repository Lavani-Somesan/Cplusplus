#include "service.h"
#include "customer.h"
#include "priorityQueue.h"
#include "fifoQueue.h"
#include "analyticalModel.h"


Service::Service(int numOfArrivals, int lambda, int mu, int numOfServers)
{
	customer = new Customer[numOfArrivals];

	this->numOfArrivals = numOfArrivals;
	this->lambda = lambda;
	this->mu = mu;
	this->numOfServers = numOfServers;
	this->customerArrivalIndex = 0;
	this->serverAvailableCount = numOfServers;
}


bool Service::isServerAvailable()
{
	if(this->serverAvailableCount > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


float Service::getNextRandomInterval(int avg)
{
	float intervalTime;
	float f = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	intervalTime = -1 * (1.0 / avg) * log(f);

	return intervalTime;
}


//Generating Times for Next set of Arrivals, Not putting in priority queue yet
void Service::generateArrivals(int lambda, int sizeOfPriorityQueue, int startingIndex, Customer customer[])
{
	float arrivalTime = 0;
	float interval = 0;
	int counter = 0;
	int i = startingIndex;

	while(counter != sizeOfPriorityQueue - 1 && customerArrivalIndex < numOfArrivals)
	{
		if(i == 0)
		{
			interval = getNextRandomInterval(lambda);
			customer[i].setArrivalTime(interval);
		}

		else
		{
			interval = getNextRandomInterval(lambda);
			arrivalTime = interval + customer[i - 1].getArrivalTime();
			customer[i].setArrivalTime(arrivalTime);
		}
		i++;
		counter++;
		this->customerArrivalIndex++;
	}

}


bool Service::isMoreArrivals()
{
	if(customerArrivalIndex < numOfArrivals)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Service::insertPriorityQueue(int startingIndex, int availablePqSpace)
{
	startingIndex++;

	while(availablePqSpace != 0)
	{
		priorityQueue.insertIntoQueue(customer[startingIndex - availablePqSpace]);
		availablePqSpace--;
	}
}


void Service::commenseService()
{
	//pqMaxArraySize is used for generating next set of arrivals since that's how big the priority queue is
	int pqMaxArraySize = priorityQueue.getMaxQueueSize();
	int availablePqSize = pqMaxArraySize - (priorityQueue.currentSize() -1);

	generateArrivals(this->lambda, pqMaxArraySize, this->customerArrivalIndex, customer);
	
	insertPriorityQueue(customerArrivalIndex, availablePqSize);

	while(priorityQueue.isEmpty() != true)
	{
		processNextEvent();
		
		if((isMoreArrivals() == true) && (priorityQueue.currentSize() - 1 < serverAvailableCount + 1))
		{
			availablePqSize = pqMaxArraySize - (priorityQueue.currentSize() - 1); 
			generateArrivals(this->lambda, pqMaxArraySize, this->customerArrivalIndex, customer);
			//generateArrivals(this->lambda, availablePqSize + 1, this->customerArrivalIndex, customer);

			insertPriorityQueue(customerArrivalIndex, availablePqSize);
			calculateIdleTime();
		}
	}


	showStatistics();
}


void Service::processNextEvent()
{
	float arrivalTime;
	float interval;
	float departureTime;
	//Customer tempCustomer;

	if(priorityQueue.getFront().getCustomerType() == arrivalType)
	{
		if(isServerAvailable() == true)
		{
			this->serverAvailableCount--;
			arrivalTime = priorityQueue.getFront().getArrivalTime();
			interval = getNextRandomInterval(this->mu);
			departureTime = arrivalTime + interval;

			Customer tempCustomer = priorityQueue.getFront();

			tempCustomer.setStartOfServiceTime(arrivalTime);
			tempCustomer.setCustomerType(departureType);
			tempCustomer.setDepartureTime(departureTime);

			priorityQueue.removeFromQueue();
			priorityQueue.insertIntoQueue(tempCustomer);
		}
		else 
		{
			Customer tempCustomer2 = priorityQueue.getFront();
			priorityQueue.removeFromQueue();
			fifoQueue.enqueue(tempCustomer2);	
		}
	}
	//Dealing with Departure Event
	else
	{
		this->serverAvailableCount++;
		
		processStatistics();
		priorityQueue.removeFromQueue();
		
		if(fifoQueue.isEmpty() != true)
		{	
			arrivalTime = fifoQueue.getBack().getArrivalTime();
			interval = getNextRandomInterval(this->mu);
			departureTime = arrivalTime + interval;
		
			Customer tempCustomer3 = fifoQueue.getBack();
			tempCustomer3.setCustomerType(departureType);
			tempCustomer3.setStartOfServiceTime(departureTime);
			tempCustomer3.setDepartureTime(departureTime);

			fifoQueue.dequeue();
			
			priorityQueue.insertIntoQueue(tempCustomer3);
			
			calculateIdleTime();
			this->serverAvailableCount--;	
		}
	}
}


void Service::calculateIdleTime()
{
	if(serverAvailableCount == numOfServers)
	{
		if(priorityQueue.getFront().getCustomerType() == arrivalType)
		{
			this->nextArrivalTimeIdle = priorityQueue.getFront().getArrivalTime();
		}

		else if(priorityQueue.getFront().getCustomerType() == departureType)
		{
			this->lastDepartureTimeIdle = priorityQueue.getFront().getDepartureTime();
		}
	}
	if(this->nextArrivalTimeIdle > 0 && this->lastDepartureTimeIdle > 0)
	{
		this->idleTime += nextArrivalTimeIdle - lastDepartureTimeIdle;
		this->nextArrivalTimeIdle = 0;
		this->lastDepartureTimeIdle = 0;
	}
}


void Service::processStatistics()
{
	float arvTime = priorityQueue.getFront().getArrivalTime();
	float servTime = priorityQueue.getFront().getStartOfServiceTime();
	float depTime = priorityQueue.getFront().getDepartureTime();
	float currentWaitTime = servTime - arvTime;

	if(currentWaitTime > 0)
	{
		numOfCustomersWaited++;
		this->totalWaitTime += (depTime - arvTime);
	}

	if(depTime - servTime == 0)
	{

		this->totalServiceTime += depTime;
	}

	else
	{
		this->totalServiceTime += (servTime - depTime);
	}
	
	calculateIdleTime();

	if(simulationIndex == 0)
	{
		totalLengthOfSimulation = arvTime;
		this->simulationIndex++;
	}
	
	lastDepartureInSimulation = depTime;
}

void Service::showStatistics()
{
	AnalyticalModel aM(lambda, mu, numOfServers);

	cout << "Analytical Model" << endl;
	cout << "----------------" << endl;
	aM.showStatistics();

	totalLengthOfSimulation = lastDepartureInSimulation - totalLengthOfSimulation;

	cout << endl;
	cout << "Simulated Results" << endl;
	cout << "-----------------" << endl;
	cout << "Idle Time Po: " << this->idleTime << endl;
	cout << "Average Time Customer Spent In System W: " << ((totalServiceTime + totalWaitTime) / numOfArrivals) << endl;
	cout << "Average Time Customer's Waited Lq: " << (this->numOfCustomersWaited / (double)numOfArrivals) << endl;
	cout << "Rho: " << (this->totalServiceTime / (totalLengthOfSimulation * numOfServers * totalLengthOfSimulation)) << endl; 
}
