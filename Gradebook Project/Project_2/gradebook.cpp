#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "gradebook.h"
#include "student.h"
#include "grades.h"

Gradebook::Gradebook() {
	
}

	
void Gradebook::ChangeGradebookName(string& gradebookName) {

	
	cout << "Please Enter the New Name For The Gradebook:  ";
	getline(cin, gradebookName);
	getline(cin, gradebookName);
	
	cout << endl;
	cout << "Gradebook Name Changed To " << gradebookName << endl;
}


void Gradebook::ChangeGradebookWeights(double& homeWorkWeight, double& qWeight, double& eWeight) {
	
	cout << endl;
	cout << "Enter The Weights, Separated By Spaces, In The Order Of Homework, Quizzes, and Exam (Total Must Add Up To 1.0): " << endl;
	cin >> homeWorkWeight;
	cin >> qWeight;
	cin >> eWeight;

	cout << endl;
	
	while((homeWorkWeight + qWeight + eWeight) != 1.0 || cin.fail()) {
	cout << "Weights Do Not Add Up To 1.0, Try Again..." << endl;
	cin >> homeWorkWeight;
	cin >> qWeight;
	cin >> homeWorkWeight;
	cin >> eWeight;
	cout << endl;
	}
	
	
	cout << "Weights Updated Successfully!" << endl;
	cout << endl;
}


void Gradebook::FinalGradeCalc(double hWAvgArray[], double qZAvgArray[], double eXAvgArray[], double hWWeight, double quizWeight, double examWeight, double finalGradeReport[],int SIZE) {

	double finalHWGrade[SIZE];
	double finalQZGrade[SIZE];
	double finalEXGrade[SIZE];
	double finalGrade[SIZE];

	
	
	for(int i=0; i < SIZE; i++) {
	finalHWGrade[i] = hWAvgArray[i] * hWWeight;	
	}

	cout << endl;
	for(int i=0; i < SIZE; i++) {
        finalQZGrade[i] = (qZAvgArray[i] * quizWeight);
        }
	

	for(int i=0; i < SIZE; i++) {
	finalEXGrade[i] = (eXAvgArray[i] * examWeight);
	}

	
	for(int i=0; i < SIZE; i++) {
	finalGrade[i] = finalHWGrade[i] + finalQZGrade[i] + finalEXGrade[i];
	}
	
	for(int i=0; i < SIZE; i++) {
	if(finalGrade[i] != 0) {
	cout << finalGrade[i] << endl;
	}
	}
	
	for(int i=0; i < 15; i++) {
	finalGradeReport[i] = finalGrade[i];
	}


}


void Gradebook::PrintGradeReport(string studentArray[], string gradeBookName, double hWWeight, double quizWeight, double examWeight, double finalAvgArray[], string hWArray[], double hWAvgArray[], string qZArray[], double qZAvgArray[], string eXArray[], double eXAvgArray[], double finalGradeReport[]) {

	cout << endl;
	
	cout << setw(5) << left << "-=|" << "GRADEBOOK REPORT";
        cout << setw(5) << right << "|=-" << endl;
	
	cout << endl;
	cout << "Course: " << gradeBookName << endl;
	cout << "HomeWork Average of Class: " << finalAvgArray[0] << "%" << endl;
	cout << "Quiz Average of Class: " << finalAvgArray[1] <<"%" << endl;	
	cout << "Exam Average of CLass: " << finalAvgArray[2] << "%" << endl;
	cout << "Final Average of Class: " << finalAvgArray[3] << "%" << endl;

	cout << endl;
	
	cout << "Student" << setw(15) << right << "|  ";
	cout << "Homework " << "(" << (hWWeight*100) << "%)";
	cout << setw(4) << right << "|  ";
	cout << "Quizzes " << "(" << (quizWeight * 100) << "%)";
	cout << setw(4) << right << "|  ";
	cout << "Exams " << "(" << (examWeight*100) << "%)";
	cout << setw(7) << right << "| ";
	cout << "Hw Avg | " << "Quiz Avg | " << "Exam Avg | " << "Final Grade |" << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
	


	//Student 1
	if(studentArray[0] != "noName"){
	cout << studentArray[0] << setw(8) << right << "| ";
		
	for(int i=0; i < 5; i++) {
	if(hWArray[i] != "<ungraded>") {
	cout << hWArray[i] << " ";
	}
	else {
	cout << "UG" << " ";
	}
	}
	cout << " | ";
	
	for(int i=0; i < 5; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
	cout << " | ";
        
	for(int i=0; i < 3; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
	}
        cout << "   |     ";
    
        if(hWAvgArray[0] != 0) {
	cout << hWAvgArray[0] << " ";
	}
	else {
	cout << "." << " ";
	}
	cout << " | ";
	
	if(qZAvgArray[0] != 0 && qZAvgArray[0] >= 1) {
        cout << qZAvgArray[0] << " ";
        }
        else  {
        cout << "." << " ";
	}
        cout << " | ";
	
	if(eXAvgArray[0] != 0 && eXAvgArray[0] >= 1) {
        cout << eXAvgArray[0] << " ";
        }
        else {
        cout << "." << " ";
	}
        cout << " | ";
	
	if(finalGradeReport[0] != 0 && finalGradeReport[0] >= 1) {
        cout << finalGradeReport[0] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";
	}


	//Student 2
	cout << endl;
	if(studentArray[1] != "noName"){
        cout << studentArray[1] << setw(8) << right << "| ";

        for(int i=5; i < 10; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=5; i < 10; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=3; i < 6; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[1] != 0) {
        cout << hWAvgArray[1] << " ";
        }
        else {
        cout << "." << " ";
	 }
        cout << "    | ";

        if(qZAvgArray[1] != 0) {
        cout << qZAvgArray[1] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

        if(eXAvgArray[1] != 0 && eXAvgArray[1] >= 1) {
        cout << eXAvgArray[1] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[1] != 0 && finalGradeReport[1] >= 1) {
        cout << finalGradeReport[1] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

	 }

	
	//Student #3
	 cout << endl;
        if(studentArray[2] != "noName"){
        cout << studentArray[2] << setw(8) << right << "| ";

        for(int i=10; i < 15; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=10; i < 15; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=6; i < 9; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[2] != 0) {
        cout << hWAvgArray[2] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[2] != 0) {
        cout << qZAvgArray[2] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[2] != 0 && eXAvgArray[2] >= 1) {
        cout << eXAvgArray[2] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[2] != 0 && finalGradeReport[2] >= 1) {
        cout << finalGradeReport[2] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";
	}
	
	//Student # 4
	cout << endl;
        if(studentArray[3] != "noName"){
        cout << studentArray[3] << setw(8) << right << "| ";

        for(int i=15; i < 20; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=15; i < 20; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=9; i < 12; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[3] != 0) {
        cout << hWAvgArray[3] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[3] != 0) {
        cout << qZAvgArray[3] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[3] != 0 && eXAvgArray[3] >= 1) {
        cout << eXAvgArray[3] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(finalGradeReport[3] != 0 && finalGradeReport[3] >= 1) {
        cout << finalGradeReport[3] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

	}

	//Student # 5
	cout << endl;
        if(studentArray[4] != "noName"){
        cout << studentArray[4] << setw(8) << right << "| ";

        for(int i=20; i < 25; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=20; i < 25; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=12; i < 15; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[4] != 0) {
        cout << hWAvgArray[4] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[4] != 0) {
        cout << qZAvgArray[4] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[4] != 0 && eXAvgArray[4] >= 1) {
        cout << eXAvgArray[4] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[4] != 0 && finalGradeReport[4] >= 1) {
        cout << finalGradeReport[4] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

        }
	
	//Student #6
	cout << endl;
        if(studentArray[5] != "noName"){
        cout << studentArray[5] << setw(8) << right << "| ";

        for(int i=25; i < 30; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=25; i < 30; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=15; i < 18; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[5] != 0) {
        cout << hWAvgArray[5] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[5] != 0) {
        cout << qZAvgArray[5] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[5] != 0 && eXAvgArray[5] >= 1) {
        cout << eXAvgArray[5] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
        
	if(finalGradeReport[5] != 0 && finalGradeReport[5] >= 1) {
        cout << finalGradeReport[5] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

	}


	//Student # 7
	cout << endl;
        if(studentArray[6] != "noName"){
        cout << studentArray[6] << setw(8) << right << "| ";

        for(int i=30; i < 35; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=30; i < 35; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=18; i < 21; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[6] != 0) {
        cout << hWAvgArray[6] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[6] != 0 && qZAvgArray[6] >= 1) {
        cout << qZAvgArray[6] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(eXAvgArray[6] != 0 && eXAvgArray[6] >= 1) {
        cout << eXAvgArray[6] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
        
	if(finalGradeReport[6] != 0 && finalGradeReport[6] >= 1) {
        cout << finalGradeReport[6] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

	}


	//Student # 8
	cout << endl;
        if(studentArray[7] != "noName"){
        cout << studentArray[7] << setw(8) << right << "| ";

        for(int i=35; i < 40; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=35; i < 40; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=21; i < 24; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[7] != 0) {
        cout << hWAvgArray[7] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[7] != 0 && qZAvgArray[7] >= 1) {
        cout << qZAvgArray[7] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[7] != 0 && eXAvgArray[7] >= 1) {
        cout << eXAvgArray[7] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[7] != 0 && finalGradeReport[7] >= 1) {
        cout << finalGradeReport[7] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";
	 }

	//Student #9	
	cout << endl;
        if(studentArray[8] != "noName"){
        cout << studentArray[8] << setw(8) << right << "| ";

        for(int i=40; i < 45; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=40; i < 45; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=24; i < 27; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[8] != 0) {
        cout << hWAvgArray[8] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[8] != 0 && qZAvgArray[8] >= 1) {
        cout << qZAvgArray[8] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[8] != 0 && eXAvgArray[8] >= 1) {
        cout << eXAvgArray[8] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[8] != 0 && finalGradeReport[8] >= 1) {
        cout << finalGradeReport[8] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

        }

	//Student #10
	cout << endl;
        if(studentArray[9] != "noName"){
        cout << studentArray[9] << setw(8) << right << "| ";

        for(int i=45; i < 50; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=45; i < 50; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=27; i < 30; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[9] != 0) {
        cout << hWAvgArray[9] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[9] != 0 && qZAvgArray[9] >= 1) {
        cout << qZAvgArray[9] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(eXAvgArray[9] != 0 && eXAvgArray[9] >= 1) {
        cout << eXAvgArray[9] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[9] != 0 && finalGradeReport[9] >= 1) {
        cout << finalGradeReport[9] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

        }


	//Student #11
	cout << endl;
        if(studentArray[10] != "noName"){
        cout << studentArray[10] << setw(8) << right << "| ";

        for(int i=50; i < 55; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=50; i < 55; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=30; i < 33; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[10] != 0) {
        cout << hWAvgArray[10] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[10] != 0) {
        cout << qZAvgArray[10] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(eXAvgArray[10] != 0 && eXAvgArray[10] >= 1) {
        cout << eXAvgArray[10] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[10] != 0 && finalGradeReport[10] >= 1) {
        cout << finalGradeReport[10] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

        }

	//Student # 12
	cout << endl;
        if(studentArray[11] != "noName"){
        cout << studentArray[11] << setw(8) << right << "| ";

        for(int i=55; i < 60; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=55; i < 60; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=33; i < 36; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[11] != 0) {
        cout << hWAvgArray[11] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[11] != 0 && qZAvgArray[11] >= 1) {
        cout << qZAvgArray[11] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[11] != 0 && eXAvgArray[11] >= 1) {
        cout << eXAvgArray[11] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[11] != 0 && finalGradeReport[11] >= 1) {
        cout << finalGradeReport[11] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

        }

	
	//Student #13
	cout << endl;
        if(studentArray[12] != "noName"){
        cout << studentArray[12] << setw(8) << right << "| ";

        for(int i=60; i < 65; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=60; i < 65; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=36; i < 39; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[12] != 0) {
        cout << hWAvgArray[12] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[12] != 0 && qZAvgArray[12] >= 1) {
        cout << qZAvgArray[12] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[12] != 0 && eXAvgArray[12] >= 1) {
        cout << eXAvgArray[12] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";

	if(finalGradeReport[12] != 0 && finalGradeReport[12] >= 1) {
        cout << finalGradeReport[12] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

        }

	//Student #14
	cout << endl;
        if(studentArray[13] != "noName"){
        cout << studentArray[13] << setw(8) << right << "| ";

        for(int i=65; i < 70; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=65; i < 70; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=39; i < 42; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[13] != 0 && hWAvgArray[13] >= 1) {
        cout << hWAvgArray[13] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[13] != 0) {
        cout << qZAvgArray[13] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(eXAvgArray[13] != 0 && eXAvgArray[13] >= 1) {
        cout << eXAvgArray[13] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(finalGradeReport[13] != 0 && finalGradeReport[13] >= 1) {
        cout << finalGradeReport[13] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";

        }
	

	//Student # 15
	cout << endl;
        if(studentArray[14] != "noName"){
        cout << studentArray[14] << setw(8) << right << "| ";

        for(int i=70; i < 75; i++) {
        if(hWArray[i] != "<ungraded>") {
        cout << hWArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=70; i < 75; i++) {
        if(qZArray[i] != "<ungraded>") {
        cout << qZArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        for(int i=42; i < 45; i++) {
        if(eXArray[i] != "<ungraded>") {
        cout << eXArray[i] << " ";
        }
        else {
        cout << "UG" << " ";
        }
        }
        cout << "   | ";

        if(hWAvgArray[14] != 0) {
        cout << hWAvgArray[14] << " ";
        }
        else {
        cout << "." << " ";
         }
        cout << "    | ";

        if(qZAvgArray[14] != 0) {
        cout << qZAvgArray[14] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	

	if(eXAvgArray[14] != 0 && eXAvgArray[14] >= 1) {
        cout << eXAvgArray[14] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << "    | ";
	
	if(finalGradeReport[14] != 0 && finalGradeReport[14] >= 1) {
        cout << finalGradeReport[14] << " ";
        }
        else {
        cout << "." << " ";
        }
        cout << " | ";
	}



}	




void Gradebook::TotalClassAverage(double hWAvgArray[], double qZAvgArray[], double eXAvgArray[], double finalAvgArray[], int SIZE) {

	int counterHW = 0;
	int counterQZ = 0;
	int counterEX = 0;
	int counter = 0;
	int hWtotal = 0.0;
	double hWClassAvg = 0.0;
	int qZtotal = 0;
	double qZClassAvg = 0.0;
	int eXtotal = 0;
	double eXClassAvg = 0.0;
	double finalClassAvg = 0.0;

	
	//HomeWork Class Average
	for(int i=0; i < SIZE; i++) {
	if(hWAvgArray[i] != 0) {
	hWtotal += hWAvgArray[i];
        counterHW += 1;
        }
        }

	cout << endl;

	if(hWtotal != 0) {
	hWClassAvg = hWtotal / static_cast<double>(counterHW);
	cout << setprecision(2);
	cout << fixed;
	cout << "Homework Average of Class:  " << hWClassAvg << "%" << endl;
	}
		


	//Quiz Class Average
	for(int i=0; i < SIZE; i++) {
	if(qZAvgArray[i] != 0) {
	qZtotal += qZAvgArray[i];
	counterQZ += 1;
	}
	}

        cout << endl;
	
        if(qZtotal != 0) {
        qZClassAvg = qZtotal / static_cast<double>(counterQZ);
	cout << setprecision(2);
        cout << fixed;
        cout << "Quiz Average of Class:  " << qZClassAvg << "% " << endl;
        }


	//Exam Class Average
	for(int i=0; i < SIZE; i++) {
        if(eXAvgArray[i] != 0) {
        eXtotal += eXAvgArray[i];
        counterEX += 1;
        }
        }

        cout << endl;

        if(eXtotal != 0) {
        eXClassAvg = eXtotal / static_cast<double>(counterEX);
        cout << setprecision(2);
        cout << fixed;
	cout << "Exam Average of Class:  " << eXClassAvg << "%" << endl;
        }

	cout << endl;	

	//Final Class Average
	if(hWClassAvg != 0) {
	finalClassAvg = hWClassAvg;
	counter += 1;
	}
	if(qZClassAvg != 0) {
	finalClassAvg += qZClassAvg;
	counter += 1;
	}
	if(eXClassAvg != 0) {
	finalClassAvg += eXClassAvg;
	counter += 1;
	}
	
	if(finalClassAvg != 0) {
	finalClassAvg = finalClassAvg / counter;
	cout << setprecision(2);
        cout << fixed;
	cout << "Final Average Of Class: " << finalClassAvg << "%" << endl;
	}

	for(int i=0; i < 4; i++) {
	if (i == 0) {
	finalAvgArray[i] = hWClassAvg;
	}
	if( i==1) {
	finalAvgArray[i] = qZClassAvg;
	}
	if(i==2) {
	finalAvgArray[i] = eXClassAvg;
	}
	if(i==3) {
	finalAvgArray[i] = finalClassAvg;
	}	
	}


}



void Gradebook::HomeWorkAverage(string hWArray[], double hWAvgArray[], string studentArray[], int SIZE, int SIZE2) {
	
	
	int counter[SIZE];
	int SIZE3 = 5;
	int array[SIZE3];
	int array2[SIZE3];
	int array3[SIZE3];
	int array4[SIZE3];
	int array5[SIZE3];
	int array6[SIZE3];
	int array7[SIZE3];
	int array8[SIZE3];
	int array9[SIZE3];
	int array10[SIZE3];
	int array11[SIZE3];
	int array12[SIZE3];
	int array13[SIZE3];
	int array14[SIZE3];
	int array15[SIZE3];
	
	for(int i=0; i < SIZE3; i++){
	array[i] = 0;
	array2[i] = 0;
	array3[i] = 0;	
	array4[i] = 0;
	array5[i] = 0;
	array6[i] = 0;
	array7[i] = 0;
	array8[i] = 0;
	array9[i] = 0;
	array10[i] = 0;
	array11[i] = 0;
	array12[i] = 0;
	array13[i] = 0;
	array14[i] = 0;
	array15[i] = 0;
	}

	for(int i=0; i < SIZE; i++) {
	counter[i] = 0;
	}
	

	
	for(int i = 0; i < SIZE3; i++) {
	if(hWArray[i] != "<ungraded>"){
	array[counter[0]] = atoi(hWArray[i].c_str());
	counter[0] +=1;
	}
	}

	if(studentArray[0] != "noName") {	
	if(counter[0] != 0) {
	hWAvgArray[0] = (array[0] + array[1] + array[2] + array[3] + array[4]) /static_cast<double>(counter[0]);
	}
	else {
	hWAvgArray[0] = 0;
	}
	}
	


	for(int i=5; i < 10; i++){
	if (hWArray[i] != "<ungraded>") {
        array2[counter[1]] = atoi(hWArray[i].c_str());
        counter[1] += 1;
        }
        }
	
	if(studentArray[1] != "noName") {
	if(counter[1] != 0) {
        hWAvgArray[1] = (array2[0] + array2[1] + array2[2] + array2[3] + array2[4]) /static_cast<double>(counter[1]);
        }
	else {
	hWAvgArray[1] = 0;
	}
	}


	for(int i=10; i < 15; i++){
        if ( hWArray[i] != "<ungraded>") {
        array3[counter[2]] = atoi(hWArray[i].c_str());
        counter[2] += 1;
        }
        }

	if(studentArray[2] != "noName") {
	if(counter[2] != 0) {
        hWAvgArray[2] = (array3[0] + array3[1] + array3[2] + array3[3] + array3[4]) /static_cast<double>(counter[2]);
        }
	else {
        hWAvgArray[2] = 0;
        }
        }



	for(int i=15; i < 20; i++){
        if ( hWArray[i] != "<ungraded>") {
        array4[counter[3]] = atoi(hWArray[i].c_str());
        counter[3] += 1;
        }
        }

	if(studentArray[3] != "noName") {
	if(counter[3] != 0) {
        hWAvgArray[3] = (array4[0] + array4[1] + array4[2] + array4[3] + array4[4]) /static_cast<double>(counter[3]);
        }
	else {
        hWAvgArray[3] = 0;
        }
        }



	for(int i=20; i < 25; i++){
        if ( hWArray[i] != "<ungraded>") {
        array5[counter[4]] = atoi(hWArray[i].c_str());
        counter[4] += 1;
        }
        }

	if(studentArray[4] != "noName") {
	if(counter[4] != 0) {
        hWAvgArray[4] = (array5[0] + array5[1] + array5[2] + array5[3] + array5[4]) /static_cast<double>(counter[4]);
        }
	else {
        hWAvgArray[4] = 0;
        }
        }


	for(int i=25; i < 30; i++){
        if ( hWArray[i] != "<ungraded>") {
        array6[counter[5]] = atoi(hWArray[i].c_str());
        counter[5] += 1;
        }
        }

	if(studentArray[5] != "noName") {
	if(counter[5] != 0) {
        hWAvgArray[5] = (array6[0] + array6[1] + array6[2] + array6[3] + array6[4]) /static_cast<double>(counter[5]);
        }
	else {
        hWAvgArray[5] = 0;
        }
        }


	for(int i=30; i < 35; i++){
        if ( hWArray[i] != "<ungraded>") {
        array7[counter[6]] = atoi(hWArray[i].c_str());
        counter[6] += 1;
        }
        }

	if(studentArray[6] != "noName") {
	if(counter[6] != 0) {
        hWAvgArray[6] = (array7[0] + array7[1] + array7[2] + array7[3] + array7[4]) /static_cast<double>(counter[6]);
        }
	else {
        hWAvgArray[6] = 0;
        }
        }

	
	
	for(int i=35; i < 40; i++){
        if ( hWArray[i] != "<ungraded>") {
        array8[counter[7]] = atoi(hWArray[i].c_str());
        counter[7] += 1;
        }
        }

	if(studentArray[7] != "noName") {
	if(counter[7] != 0) {
        hWAvgArray[7] = (array8[0] + array8[1] + array8[2] + array8[3] + array8[4]) /static_cast<double>(counter[7]);
        }
	else {
        hWAvgArray[7] = 0;
        }
        }



	for(int i=40; i < 45; i++){
        if ( hWArray[i] != "<ungraded>") {
        array9[counter[8]] = atoi(hWArray[i].c_str());
        counter[8] += 1;
        }
        }

	if(studentArray[8] != "noName") {
	if(counter[8] != 0) {
        hWAvgArray[8] = (array9[0] + array9[1] + array9[2] + array9[3] + array9[4]) /static_cast<double>(counter[8]);
        }
	else {
        hWAvgArray[8] = 0;
        }
        }



	for(int i=45; i < 50; i++){
        if ( hWArray[i] != "<ungraded>") {
        array10[counter[9]] = atoi(hWArray[i].c_str());
        counter[9] += 1;
        }
        }

	if(studentArray[9] != "noName") {
	if(counter[9] != 0) {
        hWAvgArray[9] = (array10[0] + array10[1] + array10[2] + array10[3] + array10[4]) /static_cast<double>(counter[9]);
        }
	else {
        hWAvgArray[9] = 0;
        }
        }



	for(int i=50; i < 55; i++){
        if ( hWArray[i] != "<ungraded>") {
        array11[counter[10]] = atoi(hWArray[i].c_str());
        counter[10] += 1;
        }
        }

	if(studentArray[10] != "noName") {
	if(counter[10] != 0) {
        hWAvgArray[10] = (array11[0] + array11[1] + array11[2] + array11[3] + array11[4]) /static_cast<double>(counter[10]);
        }
	else {
        hWAvgArray[10] = 0;
        }
        }



	for(int i=55; i < 60; i++){
        if ( hWArray[i] != "<ungraded>") {
        array12[counter[11]] = atoi(hWArray[i].c_str());
        counter[11] += 1;
        }
        }

	if(studentArray[11] != "noName") {
	if(counter[11] != 0) {
        hWAvgArray[11] = (array12[0] + array12[1] + array12[2] + array12[3] + array12[4]) /static_cast<double>(counter[11]);
        }
	else {
        hWAvgArray[11] = 0;
        }
        }



	for(int i=60; i < 65; i++){
        if ( hWArray[i] != "<ungraded>") {
        array13[counter[12]] = atoi(hWArray[i].c_str());
        counter[12] += 1;
        }
        }

	if(studentArray[12] != "noName") {
	if(counter[12] != 0) {
        hWAvgArray[12] = (array13[0] + array13[1] + array13[2] + array13[3] + array13[4]) /static_cast<double>(counter[12]);
        }
	else {
        hWAvgArray[12] = 0;
        }
        }


	for(int i=65; i < 70; i++){
        if ( hWArray[i] != "<ungraded>") {
        array14[counter[13]] = atoi(hWArray[i].c_str());
        counter[13] += 1;
        }
        }

	if(studentArray[13] != "noName") {
	if(counter[13] != 0) {
        hWAvgArray[13] = (array14[0] + array14[1] + array14[2] + array14[3] + array14[4]) /static_cast<double>(counter[13]);
        }
	else {
        hWAvgArray[13] = 0;
        }
        }


	for(int i=70; i < 75; i++){
        if ( hWArray[i] != "<ungraded>") {
        array15[counter[14]] = atoi(hWArray[i].c_str());
        counter[14] += 1;
        }
        }
	
	if(studentArray[14] != "noName") {
	if(counter[14] != 0) {
        hWAvgArray[14] = (array15[0] + array15[1] + array15[2] + array15[3] + array15[4]) /static_cast<double>(counter[14]);
        }
	else {
        hWAvgArray[14] = 0;
        }
        }

	

}


void Gradebook::QuizAverage(string qZArray[], double qZAvgArray[], string studentArray[], int SIZE, int SIZE2) {

 	
        int counter[SIZE];
        int SIZE3 = 5;
        int array[SIZE3];
        int array2[SIZE3];
        int array3[SIZE3];
        int array4[SIZE3];
        int array5[SIZE3];
        int array6[SIZE3];
        int array7[SIZE3];
        int array8[SIZE3];
        int array9[SIZE3];
        int array10[SIZE3];
        int array11[SIZE3];
        int array12[SIZE3];
        int array13[SIZE3];
        int array14[SIZE3];
        int array15[SIZE3];

        for(int i=0; i < SIZE3; i++){
        array[i] = 0;
        array2[i] = 0;
        array3[i] = 0;
        array4[i] = 0;
        array5[i] = 0;
        array6[i] = 0;
        array7[i] = 0;
        array8[i] = 0;
        array9[i] = 0;
        array10[i] = 0;
        array11[i] = 0;
        array12[i] = 0;
        array13[i] = 0;
        array14[i] = 0;
        array15[i] = 0;
        }

        for(int i=0; i < SIZE; i++) {
        counter[i] = 0;
        }



        for(int i = 0; i < SIZE3; i++) {
        if(qZArray[i] != "<ungraded>"){
        array[counter[0]] = atoi(qZArray[i].c_str());
        counter[0] +=1;
	}
	}

	if(studentArray[0] != "noName") {
        if(counter[0] != 0) {
        qZAvgArray[0] = (array[0] + array[1] + array[2] + array[3] + array[4]) /static_cast<double>(counter[0]);
        }
        else {
        qZAvgArray[0] = 0;
        }
        }
	else {
        qZAvgArray[0] = 0;
        cout << qZAvgArray[0];
        }



        for(int i=5; i < 10; i++){
        if (qZArray[i] != "<ungraded>") {
        array2[counter[1]] = atoi(qZArray[i].c_str());
        counter[1] += 1;
        }
        }

        if(studentArray[1] != "noName") {
        if(counter[1] != 0) {
        qZAvgArray[1] = (array2[0] + array2[1] + array2[2] + array2[3] + array2[4]) /static_cast<double>(counter[1]);
        }
        else {
        qZAvgArray[1] = 0;
        }
        }
	else {
        qZAvgArray[1] = 0;
        }



        for(int i=10; i < 15; i++){
        if (qZArray[i] != "<ungraded>") {
        array3[counter[2]] = atoi(qZArray[i].c_str());
        counter[2] += 1;
        }
        }

	if(studentArray[2] != "noName") {
        if(counter[2] != 0) {
        qZAvgArray[2] = (array3[0] + array3[1] + array3[2] + array3[3] + array3[4]) /static_cast<double>(counter[2]);
        }
        else {
        qZAvgArray[2] = 0;
        }
        }
	else {
        qZAvgArray[2] = 0;
        }



        for(int i=15; i < 20; i++){
        if (qZArray[i] != "<ungraded>") {
        array4[counter[3]] = atoi(qZArray[i].c_str());
        counter[3] += 1;
        }
        }

        if(studentArray[3] != "noName") {
        if(counter[3] != 0) {
        qZAvgArray[3] = (array4[0] + array4[1] + array4[2] + array4[3] + array4[4]) /static_cast<double>(counter[3]);
        }
        else {
        qZAvgArray[3] = 0;
        }
        }
	else {
        qZAvgArray[3] = 0;
        }



        for(int i=20; i < 25; i++){
        if (qZArray[i] != "<ungraded>") {
        array5[counter[4]] = atoi(qZArray[i].c_str());
        counter[4] += 1;
        }
        }

	if(studentArray[4] != "noName") {
        if(counter[4] != 0) {
        qZAvgArray[4] = (array5[0] + array5[1] + array5[2] + array5[3] + array5[4]) /static_cast<double>(counter[4]);
        }
        else {
        qZAvgArray[4] = 0;
        }
        }
	else {
        qZAvgArray[4] = 0;
        }


        for(int i=25; i < 30; i++){
        if (qZArray[i] != "<ungraded>") {
        array6[counter[5]] = atoi(qZArray[i].c_str());
        counter[5] += 1;
        }
        }

        if(studentArray[5] != "noName") {
        if(counter[5] != 0) {
        qZAvgArray[5] = (array6[0] + array6[1] + array6[2] + array6[3] + array6[4]) /static_cast<double>(counter[5]);
        }
        else {
        qZAvgArray[5] = 0;
        }
        }
	else {
        qZAvgArray[5] = 0;
        }



        for(int i=30; i < 35; i++){
        if (qZArray[i] != "<ungraded>") {
        array7[counter[6]] = atoi(qZArray[i].c_str());
        counter[6] += 1;
        }
        }

        if(studentArray[6] != "noName") {
        if(counter[6] != 0) {
        qZAvgArray[6] = (array7[0] + array7[1] + array7[2] + array7[3] + array7[4]) /static_cast<double>(counter[6]);
        }
        else {
        qZAvgArray[6] = 0;
        }
        }
	else {
        qZAvgArray[6] = 0;
        }


	for(int i=35; i < 40; i++){
        if (qZArray[i] != "<ungraded>") {
        array8[counter[7]] = atoi(qZArray[i].c_str());
        counter[7] += 1;
        }
        }

        if(studentArray[7] != "noName") {
        if(counter[7] != 0) {
        qZAvgArray[7] = (array8[0] + array8[1] + array8[2] + array8[3] + array8[4]) /static_cast<double>(counter[7]);
        }
        else {
        qZAvgArray[7] = 0;
        }
        }
	else {
        qZAvgArray[7] = 0;
        }



        for(int i=40; i < 45; i++){
        if (qZArray[i] != "<ungraded>") {
        array9[counter[8]] = atoi(qZArray[i].c_str());
        counter[8] += 1;
        }
        }

        if(studentArray[8] != "noName") {
        if(counter[8] != 0) {
        qZAvgArray[8] = (array9[0] + array9[1] + array9[2] + array9[3] + array9[4]) /static_cast<double>(counter[8]);
        }
        else {
        qZAvgArray[8] = 0;
        }
	}
	else {
        qZAvgArray[8] = 0;
	}


        for(int i=45; i < 50; i++){
        if (qZArray[i] != "<ungraded>") {
        array10[counter[9]] = atoi(qZArray[i].c_str());
        counter[9] += 1;
        }
        }

	if(studentArray[9] != "noName") {
        if(counter[9] != 0) {
        qZAvgArray[9] = (array10[0] + array10[1] + array10[2] + array10[3] + array10[4]) /static_cast<double>(counter[9]);
        }
        else {
        qZAvgArray[9] = 0;
        }
	}
	else {
        qZAvgArray[9] = 0;
	}


        for(int i=50; i < 55; i++){
        if (qZArray[i] != "<ungraded>") {
        array11[counter[10]] = atoi(qZArray[i].c_str());
        counter[10] += 1;
        }
        }

        if(studentArray[10] != "noName") {
        if(counter[10] != 0) {
        qZAvgArray[10] = (array11[0] + array11[1] + array11[2] + array11[3] + array11[4]) /static_cast<double>(counter[10]);
        }
        else {
        qZAvgArray[10] = 0;
        }
	}
	else {
        qZAvgArray[10] = 0;
	}


        for(int i=55; i < 60; i++){
        if (qZArray[i] != "<ungraded>") {
        array12[counter[11]] = atoi(qZArray[i].c_str());
        counter[11] += 1;
        }
        }

        if(studentArray[11] != "noName") {
        if(counter[11] != 0) {
        qZAvgArray[11] = (array12[0] + array12[1] + array12[2] + array12[3] + array12[4]) /static_cast<double>(counter[11]);
        }
        else {
        qZAvgArray[11] = 0;
        }
	}
	else {
        qZAvgArray[11] = 0;
	}

	for(int i=60; i < 65; i++){
        if (qZArray[i] != "<ungraded>") {
        array13[counter[12]] = atoi(qZArray[i].c_str());
        counter[12] += 1;
        }
        }

        if(studentArray[12] != "noName") {
        if(counter[12] != 0) {
        qZAvgArray[12] = (array13[0] + array13[1] + array13[2] + array13[3] + array13[4]) /static_cast<double>(counter[12]);
        }
        else {
        qZAvgArray[12] = 0;
        }
	}
	else {
        qZAvgArray[12] = 0;
        }
	
	


        for(int i=65; i < 70; i++){
        if (qZArray[i] != "<ungraded>") {
        array14[counter[13]] = atoi(qZArray[i].c_str());
        counter[13] += 1;
        }
        }

        if(studentArray[13] != "noName") {
        if(counter[13] != 0) {
        qZAvgArray[13] = (array14[0] + array14[1] + array14[2] + array14[3] + array14[4]) /static_cast<double>(counter[13]);
        }
        else {
        qZAvgArray[13] = 0;
        }
	}
	else {
        qZAvgArray[13] = 0;
        }


        for(int i=70; i < 75; i++){
        if(qZArray[i] != "<ungraded>") {
        array15[counter[14]] = atoi(qZArray[i].c_str());
        counter[14] += 1;
        }
        }

	if(studentArray[14] != "noName") {
        if(counter[14] != 0) {
        qZAvgArray[14] = (array15[0] + array15[1] + array15[2] + array15[3] + array15[4]) /static_cast<double>(counter[14]);
        }
        else {
        qZAvgArray[14] = 0;
        }
	}
	else {
	qZAvgArray[14] = 0;
	}



}

void Gradebook::ExamAverage(string eXArray[], double eXAvgArray[], string studentArray[], int SIZE, int SIZE2) {

	//Variables
        int counter[SIZE];
        int SIZE3 = 3;
        int array[SIZE3];
        int array2[SIZE3];
        int array3[SIZE3];
        int array4[SIZE3];
        int array5[SIZE3];
        int array6[SIZE3];
        int array7[SIZE3];
        int array8[SIZE3];
        int array9[SIZE3];
        int array10[SIZE3];
        int array11[SIZE3];
        int array12[SIZE3];
        int array13[SIZE3];
        int array14[SIZE3];
        int array15[SIZE3];

        for(int i=0; i < SIZE3; i++){
        array[i] = 0;
        array2[i] = 0;
        array3[i] = 0;
        array4[i] = 0;
        array5[i] = 0;
        array6[i] = 0;
        array7[i] = 0;
        array8[i] = 0;
        array9[i] = 0;
        array10[i] = 0;
        array11[i] = 0;
        array12[i] = 0;
        array13[i] = 0;
        array14[i] = 0;
        array15[i] = 0;
        }

        for(int i=0; i < SIZE; i++) {
        counter[i] = 0;
        }

	for(int i = 0; i < SIZE3; i++) {
        if(eXArray[i] != "<ungraded>"){
        array[counter[0]] = atoi(eXArray[i].c_str());
        counter[0] +=1;
        }
        }

        if(studentArray[0] != "noName") {
        if(counter[0] != 0) {
        eXAvgArray[0] = (array[0] + array[1] + array[2]) /static_cast<double>(counter[0]);
        }
        else {
        eXAvgArray[0] = 0;
        }
        }



        for(int i=3; i < 6; i++){
        if (eXArray[i] != "<ungraded>") {
        array2[counter[1]] = atoi(eXArray[i].c_str());
        counter[1] += 1;
        }
        }

        if(studentArray[1] != "noName") {
        if(counter[1] != 0) {
        eXAvgArray[1] = (array2[0] + array2[1] + array2[2]) /static_cast<double>(counter[1]);
        }
        else {
        eXAvgArray[1] = 0;
        }
        }


        for(int i=6; i < 9; i++){
        if (eXArray[i] != "<ungraded>") {
        array3[counter[2]] = atoi(eXArray[i].c_str());
        counter[2] += 1;
        }
        }

	if(studentArray[2] != "noName") {
        if(counter[2] != 0) {
        eXAvgArray[2] = (array3[0] + array3[1] + array3[2]) /static_cast<double>(counter[2]);
        }
        else {
        eXAvgArray[2] = 0;
        }
        }


        for(int i=9; i < 12; i++){
        if (eXArray[i] != "<ungraded>") {
        array4[counter[3]] = atoi(eXArray[i].c_str());
        counter[3] += 1;
        }
        }

        if(studentArray[3] != "noName") {
        if(counter[3] != 0) {
        eXAvgArray[3] = (array4[0] + array4[1] + array4[2]) /static_cast<double>(counter[3]);
        }
        else {
        eXAvgArray[3] = 0;
        }
        }


        for(int i=12; i < 15; i++){
        if (eXArray[i] != "<ungraded>") {
        array5[counter[4]] = atoi(eXArray[i].c_str());
        counter[4] += 1;
        }
        }

        if(studentArray[4] != "noName") {
        if(counter[4] != 0) {
        eXAvgArray[4] = (array5[0] + array5[1] + array5[2]) /static_cast<double>(counter[4]);
        }
        else {
        eXAvgArray[4] = 0;
        }
        }

	for(int i=15; i < 18; i++){
        if (eXArray[i] != "<ungraded>") {
        array6[counter[5]] = atoi(eXArray[i].c_str());
        counter[5] += 1;
        }
        }

        if(studentArray[5] != "noName") {
        if(counter[5] != 0) {
        eXAvgArray[5] = (array6[0] + array6[1] + array6[2]) /static_cast<double>(counter[5]);
        }
        else {
        eXAvgArray[5] = 0;
        }
        }


        for(int i=18; i < 21; i++){
        if (eXArray[i] != "<ungraded>") {
        array7[counter[6]] = atoi(eXArray[i].c_str());
        counter[6] += 1;
        }
        }

        if(studentArray[6] != "noName") {
        if(counter[6] != 0) {
        eXAvgArray[6] = (array7[0] + array7[1] + array7[2]) /static_cast<double>(counter[6]);
        }
        else {
        eXAvgArray[6] = 0;
        }
        }

        for(int i=21; i < 24; i++){
        if (eXArray[i] != "<ungraded>") {
        array8[counter[7]] = atoi(eXArray[i].c_str());
        counter[7] += 1;
        }
        }

	if(studentArray[7] != "noName") {
        if(counter[7] != 0) {
        eXAvgArray[7] = (array8[0] + array8[1] + array8[2]) /static_cast<double>(counter[7]);
        }
        else {
        eXAvgArray[7] = 0;
        }
        }


        for(int i=24; i < 27; i++){
        if (eXArray[i] != "<ungraded>") {
        array9[counter[8]] = atoi(eXArray[i].c_str());
        counter[8] += 1;
        }
        }

        if(studentArray[8] != "noName") {
        if(counter[8] != 0) {
        eXAvgArray[8] = (array9[0] + array9[1] + array9[2]) /static_cast<double>(counter[8]);
        }
        else {
        eXAvgArray[8] = 0;
        }
        }


        for(int i=27; i < 30; i++){
        if (eXArray[i] != "<ungraded>") {
        array10[counter[9]] = atoi(eXArray[i].c_str());
        counter[9] += 1;
        }
        }

        if(studentArray[9] != "noName") {
        if(counter[9] != 0) {
        eXAvgArray[9] = (array10[0] + array10[1] + array10[2]) /static_cast<double>(counter[9]);
        }
        else {
        eXAvgArray[9] = 0;
        }
        }

	for(int i=30; i < 33; i++){
        if (eXArray[i] != "<ungraded>") {
        array11[counter[10]] = atoi(eXArray[i].c_str());
        counter[10] += 1;
        }
        }

        if(studentArray[10] != "noName") {
        if(counter[10] != 0) {
        eXAvgArray[10] = (array11[0] + array11[1] + array11[2]) /static_cast<double>(counter[10]);
        }
        else {
        eXAvgArray[10] = 0;
        }
        }


        for(int i=33; i < 36; i++){
        if (eXArray[i] != "<ungraded>") {
        array12[counter[11]] = atoi(eXArray[i].c_str());
        counter[11] += 1;
        }
        }

        if(studentArray[11] != "noName") {
        if(counter[11] != 0) {
        eXAvgArray[11] = (array12[0] + array12[1] + array12[2]) /static_cast<double>(counter[11]);
        }
        else {
        eXAvgArray[11] = 0;
        }
        }

        for(int i=36; i < 39; i++){
        if (eXArray[i] != "<ungraded>") {
        array13[counter[12]] = atoi(eXArray[i].c_str());
        counter[12] += 1;
        }
        }

	if(studentArray[12] != "noName") {
        if(counter[12] != 0) {
        eXAvgArray[12] = (array13[0] + array13[1] + array13[2]) /static_cast<double>(counter[12]);
        }
        else {
        eXAvgArray[12] = 0;
        }
        }


        for(int i=39; i < 42; i++){
        if (eXArray[i] != "<ungraded>") {
        array14[counter[13]] = atoi(eXArray[i].c_str());
        counter[13] += 1;
        }
        }

        if(studentArray[13] != "noName") {
        if(counter[13] != 0) {
        eXAvgArray[13] = (array14[0] + array14[1] + array14[2]) /static_cast<double>(counter[13]);
        }
        else {
        eXAvgArray[13] = 0;
        }
        }


        for(int i=42; i < 45; i++){
        if(eXArray[i] != "<ungraded>") {
        array15[counter[14]] = atoi(eXArray[i].c_str());
        counter[14] += 1;
        }
        }

        if(studentArray[14] != "noName") {
        if(counter[14] != 0) {
        eXAvgArray[14] = (array15[0] + array15[1] + array15[2]) /static_cast<double>(counter[14]);
        }
        else {
        eXAvgArray[14] = 0;
        }
        }



}
