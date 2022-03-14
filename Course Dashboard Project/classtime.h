#ifndef CLASSTIME_H
#define CLASSTIME_H

#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include <cstdlib>

using namespace std;


class ClassTime {


	private:
		int daysOfTheWeek[7];  //Array that holds numerical values that represent days of the week
		int times[4];  //Holds time of the course
		
		//Private Function
		void SetDaysOfTheWeek(string days);  
		void SetTime(string times);
		
		enum timeParts { START_HOUR, START_MINUTE, END_HOUR, END_MINUTE };
		
	public:
		//Default Constructor
		ClassTime();
		
		//Paramaterized Constructor
		ClassTime(string days, string time);

		friend ostream& operator<<(ostream& os, const ClassTime& ct);

};


#endif
