#include "customer.h"


Customer::Customer()
{
	this->customerType = arrivalType;
	this->arrivalTime = 0;
	this->departureTime = 0;
	this->startOfServiceTime = 0;
	setEventTime();
}


void Customer::setCustomerType(char customerType)
{
	if(customerType == arrivalType)
	{
		this->customerType = customerType;
	}

	else if(customerType == departureType)
	{
		this->customerType = customerType;
	}

	else {
		this->customerType = arrivalType;
	}

	setEventTime();
}

char Customer::getCustomerType()
{
	return this->customerType;
}


void Customer::setEventTime()
{
	if(customerType == arrivalType)
	{
		this->currentEventTime = arrivalTime;
	}

	else
	{
		this->currentEventTime = departureTime;
	}
}


void Customer::setArrivalTime(float arrivalTime)
{
	this->arrivalTime = arrivalTime;
	setEventTime();
}


void Customer::setStartOfServiceTime(float startOfServiceTime)
{
	this->startOfServiceTime = startOfServiceTime;
}

void Customer::setDepartureTime(float departureTime)
{
	this->departureTime = departureTime;
	setEventTime();
}


float Customer::getArrivalTime()
{
	return arrivalTime;
}


float Customer::getStartOfServiceTime()
{
	return startOfServiceTime;
}


float Customer::getDepartureTime()
{
	return departureTime;
}

float Customer::getEventTime()
{
	return currentEventTime;
}
