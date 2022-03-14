#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H


#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;


class Instructor {

	private: 
	 
		string firstName;  //Holds First Name of Instructor
		string lastName;  //Holds Last Name of Instructor
		
		//Private Function
		void SetName(string names);

	public:
		//Default Constructor
		Instructor();
	
		//Parameterized Constructor
		Instructor(string names);		

		friend std::ostream& operator<<(std::ostream& os, const Instructor& instr);
	};


#endif
