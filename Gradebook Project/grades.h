#ifndef GRADES_H
#define GRADES_H

#include "student.h"

 class Grades {

	public:
	//Constructor
	Grades();
	
	//Getters
	void GetHomework();
	void GetQuizzes();
	void GetExams();
	string GetGrades();
	
	//Functions That Mutate Grade Objects
	void AddQuizzes(string quizzes[], string studentArray[], int size, int size2 );
	void AddExams(string exams[], string studentArray[], int size, int size2);
	void AddHomeWork(string homeWork[], string studentArray[], int size, int size2);
	void ShiftGrades(string homeWork[], string exams[], string quizzes[], int numRemoved); 

	private:
	string defaultGrades;

};

#endif
