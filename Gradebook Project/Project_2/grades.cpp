#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
using namespace std;

#include "grades.h"
#include "student.h"

Grades::Grades() {
	
	defaultGrades = "<ungraded>";
}

string Grades::GetGrades() {
	return defaultGrades;
}

//Shifting Homework, Quizzes, and Exam Grades 
void Grades::ShiftGrades(string homeWork[], string exams[], string quizzes[], int numRemoved) {

	int numRemoved2;

	switch(numRemoved) {
	
	case 0: 
	numRemoved = 0;
	numRemoved2 = 0;
	break;
	
	case 1:
	numRemoved = 5;
	numRemoved2 = 3;
	break;
	
	case 2:
	numRemoved = 10;
	numRemoved2 = 6;
	break;

	case 3:
	numRemoved = 15;
	numRemoved2 = 9;
	break;

	case 4:
	numRemoved = 20;
	numRemoved2 = 12;
	break;

	case 5:
	numRemoved = 25;
	numRemoved2 = 15;
	break;

	case 6:
	numRemoved = 30;
	numRemoved2 = 18;
	break;

	case 7:
	numRemoved = 35;
	numRemoved2 = 21;
	break;

	case 8:
	numRemoved = 40;
	numRemoved2 = 24;
	break;

	case 9:
	numRemoved = 45;
	numRemoved2 = 27;
	break;

	case 10:
	numRemoved = 50;
	numRemoved2 = 30;
	break;
	
	case 11:
	numRemoved = 55;
	numRemoved2 = 33;
	break;
	
	case 12:
	numRemoved =60;
	numRemoved2 = 36;
	break;

	case 13:
	numRemoved = 65;
	numRemoved2 = 39;
	break;
	
	case 14:
	numRemoved = 70;
	numRemoved2 = 42;
	break;
	}

	for(int i = numRemoved; i < 75; i++) {
	if(i >= 70 && i < 75) {
	homeWork[i] = "<ungraded>";
	quizzes[i] = "<ungraded>";
	}
	else {
	homeWork[i] = homeWork[i+5];
	quizzes[i] = quizzes[i+5];
	}	
	}

	for(int i = numRemoved2; i < 45; i++) {
	if(i >= 42 && i < 45) {
        exams[i] = "<ungraded>";
        }
        else {
        exams[i] = exams[i+3];
        }
        }
}


//Function That Adds Homework 
void Grades::AddHomeWork(string homeWork[], string studentArray[], int size, int size2) {

	int userInput;
	int gradeInput;
	int counter = 1;
	int studentList = 0;
	string gradeChange;
	cout << endl;
	
	for(int i=0; i < size; i++) {
	if(studentArray[i] != "noName") {
	cout << i+1 << ". " << studentArray[i] << endl;
	studentList = studentList + i;
        }
        }

        cout << endl;

        cout << "Which Student's Grade Would You Like To Change?" << endl;
        cin >> userInput;

        userInput = userInput - 1;

        while (userInput < 0 || userInput > studentList) {
        cout << "Please Enter a Number Coressponding to the  Student's Name." << endl;
        cin >> userInput;
        userInput = userInput -1;
        }


	cout << endl;

	cout << setw(5) << left << "-=|" << "CHANGING  " << studentArray[userInput] << "'s HOMEWORK GRADE";
	cout << setw(5) << right << "|=-" << endl;
	
	switch(userInput) {
	
	case 0: 
	
	for(int i=0; i < 5; i++) {
	cout << counter << ". " <<  homeWork[i] << endl;
	counter = counter + 1;
	}
	cout << "Which Grade Would You Like To Change? " << endl;
	cin >> gradeInput;

	while(gradeInput < 0 || gradeInput > 5) {
	cout << "Please Enter a Number 1 through 5 To Change." << endl;
	cin >> gradeInput;
	}
	
	gradeInput = gradeInput - 1;
	cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
	cin >> gradeChange;
	
	if(gradeChange == "-1") {
	homeWork[gradeInput] = "<ungraded>";
	} 
	else {
	homeWork[gradeInput] = gradeChange;
	}
	cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput + 1 << " Was Changed To " << gradeChange << endl;
	break;


	case 1:
	
        for(int i=5; i >= 5 && i < 10; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 4;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 4 << " Was Changed To " << gradeChange << endl;
        break;


	case 2:

        for(int i=10; i >= 10 && i < 15; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 9;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 9 << " Was Changed To " << gradeChange << endl;
        break;


	case 3:

        for(int i=15; i >=15 && i < 20; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 14;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 14 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 4:

        for(int i=20; i >=20 && i < 25; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 19;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
         cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 19 << " Was Changed To " << gradeChange << endl;
	break;

	
	case 5:

        for(int i=25; i >=25 && i < 30; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 24;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 24 << " Was Changed To " << gradeChange << endl;
        break;


	case 6:

        for(int i=30; i >=30 && i < 35; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 29;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 29 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 7:

        for(int i=35; i >=35 && i < 40; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 34;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 34 << " Was Changed To " << gradeChange << endl;
        break;


	case 8:

        for(int i=40; i >=40 && i < 45; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 39;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 39 << " Was Changed To " << gradeChange << endl;
        break;


	case 9:

        for(int i=45; i >=45 && i < 50; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 44;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 44 << " Was Changed To " << gradeChange << endl;
        break;


	case 10:

        for(int i=50; i >=50 && i < 55; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 49;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 49 << " Was Changed To " << gradeChange << endl;
        break;


	case 11:

        for(int i=55; i >=55 && i < 60; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 54;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 54 << " Was Changed To " << gradeChange << endl;
        break;


	case 12:

        for(int i=60; i >=60 && i < 65; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 59;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 59 << " Was Changed To " << gradeChange << endl;
        break;


	case 13:

        for(int i=65; i >=65 && i < 60; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 64;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 64 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 14:

        for(int i=70; i >=70 && i < 75; i++) {
        cout << counter << ". " <<  homeWork[i] << endl;
        counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 69;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        homeWork[gradeInput] = "<ungraded>";
        }
        else {
        homeWork[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s HomeWork Grade " << gradeInput - 69 << " Was Changed To " << gradeChange << endl;
        break;
	}

}



void Grades::AddQuizzes(string quizzes[], string studentArray[], int size, int size2) {

	int userInput;
        int gradeInput;
	int counter = 1;
	int studentList = 0;
        string gradeChange;
        cout << endl;
        
	for(int i=0; i < size; i++) {
        if(studentArray[i] != "noName") {
	cout << i+1 << ". " << studentArray[i] << endl;
	studentList = studentList + i;
        }
        }

        cout << endl;

        cout << "Which Student's Grade Would You Like To Change?" << endl;
        cin >> userInput;

        userInput = userInput - 1;

        while (userInput < 0 || userInput > studentList) {
        cout << "Please Enter a Number Coressponding to the  Student's Name." << endl;
        cin >> userInput;
        userInput = userInput -1;
        }
	
	cout << endl;

        cout << setw(5) << left << "-=|" << "CHANGING " << studentArray[ userInput] << "'s QUIZ GRADE";
        cout << setw(5) << right << "|=-" << endl;

        switch(userInput) {

        case 0:
	
        for(int i=0; i < 5; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter + 1;
	}
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	//User input Validation
        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput - 1;
       
	cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
      	quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput + 1 << " Was Changed To " << gradeChange << endl;
        break;


	case 1:
        for(int i=5; i >= 5 && i < 10; i++) {
	cout << counter << ". " <<  quizzes[i] << endl;
	counter = counter +1;
        }
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	//User Input Validation
	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 4;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	 cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 4 << " Was Changed To " << gradeChange << endl;
        break;
	
	
	case 2 :
	
        for(int i=10; i >= 10 && i < 15; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }
	
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	//User Input Validation
	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 9;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 9 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 3:

        for(int i=15; i >= 15 && i < 20; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	//User Input Validation
	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 14;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 14 << " Was Changed To " << gradeChange << endl;
        break;


	case 4:

        for(int i=20; i >= 20 && i < 25; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	//User Input Validation
	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 19;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 19 << " Was Changed To " << gradeChange << endl;
        break;


	case 5:

        for(int i=25; i >= 25 && i < 30; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	//User Input Validation
	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 24;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 24 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 6:

        for(int i=30; i >= 30 && i < 35; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	//User Input Validation
	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 29;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 29 << " Was Changed To " << gradeChange << endl;
        break;


	case 7:

        for(int i=35; i >= 35 && i < 40; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


	while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 34;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 34 << " Was Changed To " << gradeChange << endl;
        break;


	case 8:

        for(int i=40; i >= 40 && i < 45; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 39;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 39 << " Was Changed To " << gradeChange << endl;
        break;


	 case 9:

        for(int i=45; i >= 45 && i < 50; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 44;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 44 << " Was Changed To " << gradeChange << endl;
        break;


	case 10:

        for(int i=50; i >= 50 && i < 55; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 49;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 49 << " Was Changed To " << gradeChange << endl;
        break;


	case 11:

        for(int i=55; i >= 55 && i < 60; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 54;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 54 << " Was Changed To " << gradeChange << endl;
        break;


	case 12:

        for(int i=60; i >= 60 && i < 65; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 59;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 59 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 13:

        for(int i=65; i >= 65 && i < 70; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 64;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 64 << " Was Changed To " << gradeChange << endl;
        break;


	case 14:

        for(int i=70; i >= 70 && i < 75; i++) {
        cout << counter << ". " <<  quizzes[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 5) {
        cout << "Please Enter a Number 1 through 5 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 69;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        quizzes[gradeInput] = "<ungraded>";
        }
        else {
        quizzes[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Quiz Grade " << gradeInput - 69 << " Was Changed To " << gradeChange << endl;
        break;
	}
}



void Grades::AddExams(string exams[], string studentArray[], int size, int size2) {
	
	int userInput;
        int gradeInput;
        int counter = 1;
	int studentList = 0;
        string gradeChange;
        cout << endl;
        
	for(int i=0; i < size; i++) {
        if(studentArray[i] != "noName") {
	cout << i+1 << ". " << studentArray[i] << endl;
       	studentList = studentList + i;
	}
	}

        cout << endl;

        cout << "Which Student's Grade Would You Like To Change?" << endl;
        cin >> userInput;
	
	userInput = userInput - 1;

	while (userInput < 0 || userInput > studentList) {
        cout << "Please Enter a Number Coressponding to the  Student's Name." << endl;
       	cin >> userInput;
	userInput = userInput -1;
	}

	cout << endl;

        cout << setw(5) << left << "-=|" << "CHANGING " << studentArray[userInput] << "'s EXAM GRADES";
	cout << setw(5) << right << "|=-" << endl;

        switch(userInput) {

        case 0:
        for(int i=0; i < 3; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter + 1;
	}
        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;

	while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput - 1;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput + 1 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 1:

        for(int i=3; i >= 3 && i < 6; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 2;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 2 << " Was Changed To " << gradeChange << endl;
        break;
        
	
	case 2:

        for(int i=6; i >= 6 && i < 9; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 5;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 5 << " Was Changed To " << gradeChange << endl;
        break;


	case 3:

        for(int i=9; i >= 9 && i < 12; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 8;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 8 << " Was Changed To " << gradeChange << endl;
        break;


	case 4:

        for(int i=12; i >= 12 && i < 15; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 11;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 11 << " Was Changed To " << gradeChange << endl;
        break;


	case 5:

        for(int i=15; i >= 15 && i < 18; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 14;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 14 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 6:

        for(int i=18; i >= 18 && i < 21; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 17;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 17 << " Was Changed To " << gradeChange << endl;
        break;


	case 7:

        for(int i=21; i >= 21 && i < 24; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 20;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 20 << " Was Changed To " << gradeChange << endl;
        break;


	case 8:

        for(int i=24; i >= 24 && i < 27; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 23;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 23 << " Was Changed To " << gradeChange << endl;
        break;
	

	case 9:

        for(int i=27; i >= 27 && i < 30; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 26;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 26 << " Was Changed To " << gradeChange << endl;
        break;


	case 10:

        for(int i=30; i >= 30 && i < 33; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 29;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 29 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 11:

        for(int i=33; i >= 33 && i < 36; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 32;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 32 << " Was Changed To " << gradeChange << endl;
        break;
	

	case 12:

        for(int i=36; i >= 36 && i < 39; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 35;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 35 << " Was Changed To " << gradeChange << endl;
        break;

	
	case 13:

        for(int i=39; i >= 39 && i < 42; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 38;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 38 << " Was Changed To " << gradeChange << endl;
        break;


	case 14:

        for(int i=42; i >= 42 && i < 45; i++) {
        cout << counter << ". " <<  exams[i] << endl;
        counter = counter +1;
        }

        cout << "Which Grade Would You Like To Change? " << endl;
        cin >> gradeInput;


        while(gradeInput < 0 || gradeInput > 3) {
        cout << "Please Enter a Number 1 through 3 To Change." << endl;
        cin >> gradeInput;
        }

        gradeInput = gradeInput + 41;

        cout << "What Would You Like To Change it To? (-1 for ungraded)" << endl;
        cin >> gradeChange;

        if(gradeChange == "-1") {
        exams[gradeInput] = "<ungraded>";
        }
        else {
        exams[gradeInput] = gradeChange;
        }
	cout << studentArray[userInput] << "'s Exam Grade " << gradeInput - 41 << " Was Changed To " << gradeChange << endl;
        break;
	}

}	
