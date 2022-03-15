#include "priorityQueue.h"
#include "customer.h"


PriorityQueue::PriorityQueue()
{
	
}


int PriorityQueue::getParentNode(int nodeIndex)
{
		return (nodeIndex / 2);
}


int PriorityQueue::getLeftChild(int nodeIndex)
{
	return (2 * nodeIndex);
}


int PriorityQueue::getRightChild(int nodeIndex)
{
	return (2 * nodeIndex) + 1;
}


int PriorityQueue::currentSize()
{
	return numOfEvents;
}


int PriorityQueue::getMaxQueueSize()
{
	return (int)QUEUE_SIZE;
}


bool PriorityQueue::isEmpty()
{
	if(currentSize() == 1)
	{
		return true;
	}

	else 
	{
		return false;
	}
}


bool PriorityQueue::isFull()
{
	if(currentSize() == QUEUE_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Customer PriorityQueue::getFront()
{
	return priorityQueue[1];
}	



void PriorityQueue::percolateDown(int nodeIndex)
{
	int smallestNodeIndex = nodeIndex;
	int leftNodeIndex; 
	int rightNodeIndex;
	int currentArraySize = currentSize();

	leftNodeIndex = getLeftChild(nodeIndex);
	rightNodeIndex = getRightChild(nodeIndex);


	if((leftNodeIndex < currentArraySize) && (priorityQueue[leftNodeIndex].getEventTime() < priorityQueue[smallestNodeIndex].getEventTime()))
	{
		smallestNodeIndex = leftNodeIndex;
	}
	
	if((rightNodeIndex < currentArraySize) && (priorityQueue[rightNodeIndex].getEventTime() < priorityQueue[smallestNodeIndex].getEventTime()))
	{
		smallestNodeIndex = rightNodeIndex;
	}

	if(smallestNodeIndex != nodeIndex)
	{
		swap(priorityQueue[nodeIndex], priorityQueue[smallestNodeIndex]);
		percolateDown(smallestNodeIndex);
	}	
}


void PriorityQueue::removeFromQueue()
{
	int beginningIndex = 1;

	if(isEmpty() != true)
	{
		priorityQueue[beginningIndex] = priorityQueue[numOfEvents - 1];
		this->numOfEvents = numOfEvents - 1;

		percolateDown(beginningIndex);
	}
}


void PriorityQueue::percolateUp(int nodeIndex)
{
	int parentIndex = getParentNode(nodeIndex);
	
	if(parentIndex > 0)
	{	
	if(priorityQueue[nodeIndex].getEventTime() < priorityQueue[parentIndex].getEventTime())
	{
		swap(priorityQueue[nodeIndex], priorityQueue[parentIndex]);
		percolateUp(parentIndex);
	}
	}
}



void PriorityQueue::insertIntoQueue(Customer event)
{
	int arrayIndex = numOfEvents;

	if(isFull() != true)
	{
		priorityQueue[arrayIndex] = event;
		percolateUp(arrayIndex);

		this->numOfEvents = numOfEvents + 1;
	}
}


void PriorityQueue::displayQueue()
{
	for(int i = 1; i < numOfEvents; i++)
	{
		cout << priorityQueue[i].getEventTime() << endl;
	}
}
