/***************************************************************
 * File Name: customer.h
 * 
 * This class  is a completely private class that holds information
 * about a Customer. The Customer class holds a customer's arrival
 * time, departure time, service time, and they type of customer
 * i.e. arrival or departure. This is our event class. 
 ***************************************************************/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;


class Customer {
	
	friend class PriorityQueue;
	friend class FifoQueue;
	friend class Service;

	private:
		char customerType;
		char arrivalType = 'A';
		char departureType = 'D';
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		float currentEventTime;

		Customer();
		float getArrivalTime();
		float getStartOfServiceTime();
		float getDepartureTime();
		float getEventTime();
		char getCustomerType();

		void setArrivalTime(float arrivalTime);
		void setStartOfServiceTime(float startOfServiceTime);
		void setDepartureTime(float departureTime);
		void setEventTime();
		void setCustomerType(char customerType);

};

#endif
