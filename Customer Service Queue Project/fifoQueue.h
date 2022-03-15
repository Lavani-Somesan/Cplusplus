/***************************************************************
 * File Name: fifoQueue.h
 *
 * This class  is a completely private class that creates and runs
 * a fifo (first in first out) queue. The FifoQueue class takes in 
 * objects from the Customer class which are considered events. 
 * The fifo queue takes in Customer objects when the priority queue 
 * is full and a departure has not been processed yet. This class is 
 * used in the Service class to process waiting arrivals.
 ***************************************************************/

#ifndef FIFOQUEUE_H
#define FIFOQUEUE_H

#include "customer.h"

#include <iostream>
#include <deque>
#include <vector>
using namespace std;



class FifoQueue {

	friend class Service;

	private:
		deque <Customer> fifoQueue;

		FifoQueue() { };
		bool isEmpty();
		int sizeOfQueue();
		Customer getBack();
		void enqueue(Customer event);
		void dequeue();
		void displayFront();
		void displayBack();

};

#endif
