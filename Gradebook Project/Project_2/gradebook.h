#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "grades.h"
#include "student.h"

class Gradebook {

	public: 
	//Constructor
	Gradebook();
	//Functions
	void ChangeGradebookName(string& gradebookName);
	void ChangeGradebookWeights(double& hWWeight, double& quizWeight, double& examWeight);
	
	//Function That Gets Averages for each Assignment Group
	void HomeWorkAverage(string hWArray[], double hWAvgArray[], string studentArray[], int SIZE, int SIZE2);
	void QuizAverage(string qZArray[], double qZAvgArray[], string studentArray[], int SIZE, int SIZE2);
	void ExamAverage(string eXArray[], double eXAvgArray[], string studentArray[], int SIZE, int SIZE2);
	void TotalClassAverage(double hWAvgArray[], double qZAvgArray[], double eXAvgArray[], double finalAvgArray[], int SIZE);	
	
	//Function That Gets Final Grades for Each Student
	void FinalGradeCalc(double hWAvgArray[], double qZAvgArray[], double eXAvgArray[], double hWWeight, double quizWeight, double examWeight, double finalGradeReport[], int SIZE);	
	
	//Function That Prints Out Grade Report
	void PrintGradeReport(string studentArray[], string gradeBookName, double hWWeight, double quizWeight, double examWeight, double finalAvgGrade[], string hWArray[], double hWAvgArray[], string qZArray[], double qZAvgArray[], string eXArray[], double eXAvgArray[], double finalGradeReport[]);


};


#endif
