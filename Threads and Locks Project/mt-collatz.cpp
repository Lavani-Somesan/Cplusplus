/**
 * @author Lavani Somesan
 * @author Martin Kadzis
 * @date 10/25/2020
 *
 * This is the main program that takes in arguments for max
 * number to compute for collatz, number of threads to run,
 * and if to use locks or no locks. The program creates and
 * launches threads to run the collatz sequence given a range
 * until done. The main thread waits for the other threads to
 * finish. Time is also calculated starting before threads are
 * launched to when threads have finished and joined back to main
 * thread. The histogram array is printed and then deallocated.
 *
 */

#include "histogram.hpp"

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <stdio.h>
#include <time.h>
using namespace std;

//Global variable
mutex mu;
Histogram histogramArray(550);


/*
 * Computes the Collatz Sequences in a specified range.
 * Stopping time is incremented till a value reaches 1
 * and the histogram array is updated with that stopping time
 * as the index.
 *
 * @param counter is the counter for loop
 * @param maxRange is the max number the sequence needs to compute
 * @param isLocked if thread is locked use locks if thread is not locked then don't use locks
 */
void computeCollatzSeq(int counter, int maxRange, bool isLocked) {
	long int value;
	long int stoppingTime;	

	while(counter < maxRange) {
	if(isLocked == true) {
        	mu.lock();
	    	value = counter;
	    	stoppingTime = 1;
	    	counter++;
        	mu.unlock();
	}
	else {
		value = counter;
		stoppingTime = 1;
		counter++;
	}
		    do {
			    (value % 2 == 0) ? value = value / 2 : value = (3 * value) + 1;
			    if (value != 1) ++stoppingTime;
		    } 
		    while(value != 1);

	if(isLocked == true) {
		mu.lock();
	    	//cout << counter -1 <<":" << stoppingTime << endl; //Used for Debugging    
	    	histogramArray.updateHistogram(stoppingTime);
	    	mu.unlock();
	}
	else {
		//cout << counter - 1 << ":" << stoppingTime << endl; //Used for Debugging
		histogramArray.updateHistogram(stoppingTime);
	}		    
	}
}


/*
 * Computse the elapsedTime from before therads are launched
 * to when they are finished in nanoseconds.
 *
 * @param start is the starting time in nanoseconds
 * @param stop is the stopping time in nanoseconds
 *
 * @return elapsed returns the elapsed time
 */
timespec elapsedTime (timespec start, timespec stop){
    timespec elapsed;
    int nano = 1000000000;

    if((stop.tv_nsec - start.tv_nsec) < 0){
        elapsed.tv_sec = stop.tv_sec - start.tv_sec - 1;
        elapsed.tv_nsec = nano + (stop.tv_nsec - start.tv_nsec);
    } else {
        elapsed.tv_sec = stop.tv_sec - start.tv_sec;
        elapsed.tv_nsec = stop.tv_nsec - start.tv_nsec;
    }

    return elapsed;
}

int main(int argc, char *argv[]) {
    	system("clear");

	string lock_str = "-nolock";	
	bool isLocked = true;
		
	int numRange = atoi(argv[1]);
	int numThreads = atoi(argv[2]);
	
	//Checks argument vector for -nolock argument
	if(argv[3] != NULL && lock_str.compare(argv[3]) == 0) {
		isLocked = false;
	}
	
	thread threads[numThreads];

	struct timespec start, stop;
	//Clock in
	clock_gettime(CLOCK_REALTIME, &start);
	
	//Create Threads
	for(int i = 0; i < numThreads; ++i){
        int threadStart = i * (numRange/numThreads);
        int threadEnd = ((i + 1) * (numRange/numThreads));

        if(threadStart == 0) threadStart = 2;
		threads[i] = thread(computeCollatzSeq, threadStart, threadEnd, isLocked);
	}
    
	//Wait for threads to join main thread
	for(auto&thread: threads) {
		thread.join();
	}
	
    	//Clock out 
	clock_gettime(CLOCK_REALTIME, &stop);
	
	//Calculate the Time in nanoseconds
	timespec elapsed = elapsedTime(start, stop);
    	
	cerr << numRange << ", " << numThreads << ", " << elapsed.tv_nsec << endl;
	
	/*	
	//cout << endl;
	//cout << COUNTER << endl; //Used for debugging if COUNTER is not one over numRange then it's experiencing a race condition
	*/
	
	histogramArray.printHistogram();
	
	histogramArray.deAllocateArray();
	return 0;
}

