#include "fifoQueue.h"
#include "customer.h"


bool FifoQueue::isEmpty()
{
	if(sizeOfQueue() == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}


int FifoQueue::sizeOfQueue()
{
	return fifoQueue.size();
}


void FifoQueue::enqueue(Customer event)
{
	if(isEmpty() == true)
	{
		fifoQueue.push_back(event);
	}

	else
	{
		fifoQueue.push_front(event);
	}
}

void FifoQueue::dequeue()
{
	if(isEmpty() != true)
	{
		fifoQueue.pop_back();
	}
}


Customer FifoQueue::getBack()
{
	return fifoQueue.back();
}


void FifoQueue::displayFront()
{

	if(!fifoQueue.empty())
	{
		cout << fifoQueue.front().getEventTime() << endl;
	}
}

void FifoQueue::displayBack()
{
	if(!fifoQueue.empty())
	{
		cout << fifoQueue.back().getEventTime() << endl;
	}
}
