#ifndef STUDENT_H
#define STUDENT_H

#include "grades.h"

class Student {

	public:
	//Constructor
	Student();
	 
	//Getters
	string GetName();
	
	//Function That Shifts Student List
	int GetShiftedPos();
	
	//Fuctions That Mutate Student Object
	void AddStudent(string studentArray[], int size);
	void RemoveStudent(string studentArray[], int size);

	private:
	int studentMoved;
	string defaultName;
	string stuName;

};

#endif
