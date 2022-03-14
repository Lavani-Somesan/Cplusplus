#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
using namespace std;

#include "student.h"
#include "grades.h"

Student::Student() {
	defaultName = "noName";
}


string Student::GetName() {
	return defaultName;
}

void Student::AddStudent(string studentArray[], int size) {
	
	//If statement to make sure no more that 15 are added to gradebook
	if(studentArray[14] == "noName") {
	cout << "Please Enter the Student's Name: " << endl;
	
	//Lets user Enter First, Last and Middle Name in one string
	getline(cin,stuName);
	getline(cin, stuName);
	int position;
	
	//Loop that add a student name from position 1 to 15
	for(int i = 14; i >=0; i--) {
	if(studentArray[i] == "noName") {
	position = i;
	}
	}
	//Assigns name to position in the student list 
	studentArray[position] = stuName;
	cout << endl;
	cout << studentArray[position] << " Has Been Successfully Added to the Gradebook!" << endl;
	cout << endl;
	}

	else {
	cout << endl;
	cout << "Students Cannot Be Added Because the Gradebook is Full!" << endl;
	}
}

void Student::RemoveStudent(string studentArray[], int size) {
	
	int studentRemoved;
	cout << endl;
	
	//Prints Out Student List
	for(int i = 0; i < size; i++) {
	if(studentArray[i] != "noName") {
	cout << i+1 << ". " << studentArray[i] << endl;
	}
	}
	cout << endl;	
	cout << "Enter Student You Wish to Remove (Enter their Position)" << endl;
	cin >> studentRemoved;
	studentRemoved = studentRemoved - 1;
	
	studentMoved = studentRemoved;
	
	if(studentRemoved < 0 || studentRemoved > (size -1)) {
	cout << "Please Enter a Position from 1 to 15 of the Student you Want to Remove." << endl;
	}
	
	
	cout << studentArray[studentRemoved] << " Has Successfully Been Removed!" << endl;
	
	for(int i = studentRemoved; i < size ; i++) {
	if(i == 14) {
	studentArray[i] = "noName";
	}
	else {
	studentArray[i] = studentArray[i+1];
	}
	}

}

int Student::GetShiftedPos() {
	return studentMoved; 
}

	
