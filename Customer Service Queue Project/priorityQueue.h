/***************************************************************
 * File Name: priorityQueue.h
 * 
 * This class  is a completely private class that creates and runs
 * a priority queue. The PriorityQueue class takes in objects from
 * the Customer class which are considered events. It percolates up
 * the highest priority (lowest arrival or deparutre time) to top of 
 * queue. This class is used in Service class to process arrival
 * and departure events.
 ***************************************************************/



#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "customer.h"

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class PriorityQueue
{
	friend class Service;

	private:
		const int static QUEUE_SIZE = 201;
		int numOfEvents = 1;
		Customer priorityQueue[QUEUE_SIZE];

		PriorityQueue();
		int getParentNode(int nodeIndex);
		int getLeftChild(int nodeIndex);
		int getRightChild(int nodeIndex);

		void percolateUp(int indexNode);
		void percolateDown(int indexNode);
		void insertIntoQueue(Customer event);
		void removeFromQueue();

		int currentSize();
		int getMaxQueueSize();
		bool isEmpty();
		bool isFull();
		Customer getFront();
		void displayQueue();
};

#endif


