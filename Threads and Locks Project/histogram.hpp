/*
 * @author Lavani Somesan
 * @author Martin Kadzis
 * @date 10/25/2020
 *
 * The Histogram class stores the histogram array.
 * You pass an initial size for the array as a param
 * when you instantiate the class. You can update, print,
 * and deallocate the array. Used to store stopping times
 * for collatz sequence.
 */

#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

#include <iostream>

using namespace std;


class Histogram {

	private:
		long int *histogramArray;
		int sizeOfArray;	
	
	public:
		Histogram(int sizeOfArray);
		
		void updateHistogram(int stoppingTime);
		void printHistogram();
		void deAllocateArray();
};

#endif
