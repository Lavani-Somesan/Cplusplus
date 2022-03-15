#include "histogram.hpp"

/*
 * Constructor for Histogram
 *
 * @param sizeOfArray The size of the histogramArray
 */

Histogram::Histogram(int sizeOfArray) {
	histogramArray = new long int[sizeOfArray];
	this->sizeOfArray = sizeOfArray;
}

/*
 * Updates the Histogram at a certain index by
 * an increment of 1.
 *
 * @param stoppingTime Index of histogramArray to update
 */
void Histogram::updateHistogram(int stoppingTime) {
	histogramArray[stoppingTime] += 1;
}

/*
 * Deallocates the Histogram Array
 */
void Histogram::deAllocateArray() {
	delete histogramArray;
}

/*
 * Prints out the index of the Histogram Array and the value at that index
 */
void Histogram::printHistogram() {
	cout << endl;
	for(int i = 0; i < sizeOfArray; i++) {
		cout << i << "," << histogramArray[i] << endl;
	}
}
