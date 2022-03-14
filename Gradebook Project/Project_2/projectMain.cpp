#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
using namespace std;

#include "student.h"
#include "grades.h"
#include "gradebook.h"

int main() {
	
	//Variables
	int userOption = 1;
	const int SIZE = 15;
	const int SIZE_HW = 75;
	const int SIZE_QZ = 75;
	const int SIZE_EX = 45;
	
	int gradeOption;
	int shift;
	
	//Array Declaraion
	string stuArray[SIZE]; //Holds Student Records
	string hWArray[SIZE_HW]; //Holds HomeWork Records
	string quizArray[SIZE_QZ];  //Holds Quiz Records
	string examArray[SIZE_EX];  //Holds Exam Records
	double hWAvgArray[SIZE_HW]; //Holds HomeWork Average
	double quizAvgArray[SIZE_QZ]; //Holds quiz Average
	double examAvgArray[SIZE_EX]; //Holds Exam Average
	double finalAvgArray[SIZE]; //Holds final Average
	
	//Gradebook Weights
	double hWWeight = 0.0;
	double quizWeight = 0.0;
	double examWeight = 0.0;
	
	//Gradebook Name Default
	string gradebookName = "noName";
	
	//Holds Final Grades For Each Student 
	double finalGradeReport[SIZE];

	
	//Instantiates Student Class and declares 15 objects that are all set to noName
	Student students[SIZE];	
	
	//Instantiates Grade Class and sets all objects to "<ungraded>"
	Grades homeWork[SIZE_HW];
	Grades quizzes[SIZE_QZ];
	Grades exams[SIZE_EX];
	
	//Instatiates Gradebook Class 
	Gradebook homeWorkAvg[SIZE];
	Gradebook quizAvg[SIZE];
	Gradebook examAvg[SIZE];
	Gradebook gradebook;
	
	
	//Sets Student Name in main program array to  noName
	for(int i=0; i < SIZE; i++) {
	stuArray[i] = students[i].GetName();
	}


	//Sets Grades to <ungraded>
	for(int i=0; i < SIZE_HW; i++) {
	hWArray[i] = homeWork[i].GetGrades();
	}	

	for (int i=0; i < SIZE_QZ; i++) {
	quizArray[i] = quizzes[i].GetGrades();
	}

	for(int i=0; i < SIZE_EX; i++) {
	examArray[i] = exams[i].GetGrades();
	}

	//Sets Average 
	for(int i=0; i < SIZE; i++) {
	hWAvgArray[i] = 0.0;
	examAvgArray[i] = 0.0;
	}	

	//gradebook.SetGradebookName(gradebookName);
	//gradebook.SetGradebookWeights(hWWeight, quizWeight, examWeight);
	
	//Main Menu		
	while(userOption != 0) {
	
	//Outputs Fromatted Main Menu Options
	cout << endl;
	cout << setw(5) << left << "-=|" << "MAIN MENU";
	cout << setw(5) << right << "|=-" << endl;
	cout << endl;
	cout << "1. Add a Student" << endl;
	cout << "2. Remove a Student" << endl;
	cout << "3. Change a Student's Grade" << endl;
	cout << "4. Change Group Weights" << endl;
	cout << "5. Change the Gradebook Name" << endl;
	cout << "6. Display Class Averages" << endl;
	cout << "7. Display Full Report" << endl;
	cout << "0. Quit" << endl;

	cout << endl;
	cout << "Enter an Option: " << endl;
	cin >> userOption;
	//Input Validation for User to ensure they can only choose options 0-7
	while (userOption < 0 || userOption > 7) {
	cout << "Please Enter an Option between 0 and 7!" << endl;
	cin >> userOption;
	}
	cout << endl;

	switch(userOption) {
	
	//Adds Student To List
	case 1:
	
	cout << setw(5) << left << "-=|" << "ADDING STUDENT";
	cout << setw(5) << right << "|=-" << endl;
	
	(*students).AddStudent(stuArray, SIZE);
	break;

	//Removes Student From List
	case 2:
	 
	cout << setw(5) << left << "-=|" << "REMOVING STUDENT";
	cout << setw(5) << right << "|=-" << endl;
	(*students).RemoveStudent(stuArray, SIZE);
	shift = (*students).GetShiftedPos();
	(*homeWork).ShiftGrades(hWArray, examArray, quizArray, shift);
	break;

	//Change Grade for Any Student On List
	case 3:
	
	cout << setw(5) << left << "-=|" << "CHANGING GRADE";
	cout << setw(5) << right << "|=-" << endl;
	
	cout << "1. Change a Homework Grade" << endl;
	cout << "2. Change a Quiz Grade" << endl;
	cout << "3. Change an Exam Grade" << endl;
	cout << endl;

	cout << "What Type of Grade Would You Like To Change? " << endl;
	cin >> gradeOption;
	
	if( gradeOption < 1 || gradeOption > 3) {
	cout << "Choose an Option between 1 through 3 to Change " << endl;
	cin >> gradeOption;
	}	
	switch(gradeOption) {
	
	case 1: 
	(*homeWork).AddHomeWork(hWArray, stuArray, SIZE, SIZE_HW);
	break;
	
	case 2:
	(*quizzes).AddQuizzes(quizArray, stuArray, SIZE, SIZE_HW);
	break;

	case 3:
	(*exams).AddExams(examArray, stuArray, SIZE, SIZE_HW);
	break;
	}
	break;


	//Change Group Weights for GradeBook
	case 4: 
	cout << setw(5) << left << "-=|" << "CHANGING GROUP WEIGHTS";
	cout << setw(5) << right << "|=-" << endl;
	
	gradebook.ChangeGradebookWeights(hWWeight, quizWeight, examWeight);
	break;

 
	//Change GradeBook Name
	case 5:
	
	cout << setw(5) << left << "-=|" << "CHANGING GRADEBOOK NAME";
	cout << setw(5) << right << "|=-" << endl;
	
	gradebook.ChangeGradebookName(gradebookName);
	break;

	//Display Averages for Each Assignment Group and Final Average
	case 6:
	cout << setw(5) << left << "-=|" << "DISPLAY CLASS AVERAGES";
	cout << setw(5) << right << "|=-" << endl;
	
	(*homeWorkAvg).HomeWorkAverage(hWArray, hWAvgArray, stuArray, SIZE, SIZE_HW);
	(*quizAvg).QuizAverage(quizArray, quizAvgArray, stuArray, SIZE, SIZE_QZ);
	(*examAvg).ExamAverage(examArray, examAvgArray, stuArray, SIZE, SIZE_EX);
	
	gradebook.TotalClassAverage(hWAvgArray, quizAvgArray, examAvgArray, finalAvgArray, SIZE);
	gradebook.FinalGradeCalc(hWAvgArray, quizAvgArray, examAvgArray, hWWeight, quizWeight, examWeight, finalGradeReport, SIZE);
	break;

	//Prints Full Grade Report
	case 7:
	cout << setw(5) << left << "-=|" << "DISPLAY FULL REPORT";
	cout << setw(5) << right << "|=-" << endl;
	
	gradebook.PrintGradeReport(stuArray, gradebookName, hWWeight, quizWeight, examWeight, finalAvgArray, hWArray, hWAvgArray, quizArray, quizAvgArray, examArray, examAvgArray, finalGradeReport);

	break;

	//Quiz
	case 0:
	cout << setw(5) << left << "-=|" << "QUIT";
	cout << setw(5) << right << "|=-" << endl;
	break;
	}

	}

} 	
