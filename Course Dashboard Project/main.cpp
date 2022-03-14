#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>

#include "instructor.h"
#include "course.h"
#include "classtime.h"

using namespace std;


int main() {

	ifstream inFS;
	string fileName;  //Holds the Name of the File
	string instructorName;  //Holds the Last,First Name of Instructor
	int maxSeats;  //Holds Max # of Seats in a Course
	int availableSeats;  //Holds Available Seats in a Course
	string coursePrefix;  //Holds Course Prefix of a Course
	int courseNum;  //Holds Course Number of a Course
	string days;  //Holds String of #'s 0-6 that corresponds to days of the week that course takes palce
	string times;  //Holds Times that course takes place
	vector<Course> courseList;  //Vector that holds the amount of courses
	int counter = 0;  //Counter for courseList
	char userOption;  //Holds User Option Choice for Menu
	char userOption2;  //Holds User Option Choice for Option on Menu

	
	cout << "Input the Name of the File that Contains the Course Data: " << endl;
	cin >> fileName;

	//Opens User Entered File Name
	inFS.open(fileName.c_str());


	//Validates if User File Exists 
        while(!inFS.is_open()) {
	cout << "Input the Name of the File that Contains the Course Data: " << endl;
        cin >> fileName;

        inFS.open(fileName.c_str());
        }

	cout << "Hello! Welcome to Fake Banner!" << endl;
	cout << "Below is a List of All Avaiable Courses" << endl << endl;

	
	//Declares Course Class
	Course courses;


	//Reads File and Parses it into the Classes which then is passed into a Course vector
	while(inFS >> coursePrefix >> courseNum >> instructorName >> maxSeats >> availableSeats >> days >> times)
	{

		Instructor instructor(instructorName);
		ClassTime classtimes(days, times);
		courses = Course(coursePrefix, courseNum, instructor,  maxSeats, availableSeats, classtimes);			
			
		//Adds courses to course list
		courseList.push_back(courses);
		
		//Prints out List of Courses if Seats are available
		if(availableSeats >= 1)
		{	
			cout << courseList[counter];
		}
		//Increments counter for printing available courses
		counter++;
	}

	//Closes File
	inFS.close();	

	//Option Menu
	do {
		cout << endl;
		cout << "To Search for a Course, Press 'S'. " << endl;
		cout << "To Enroll, press 'E'. " << endl;
		cout << "To View Your Current Enrollments, Press 'V'. " << endl;
		cout << "To Get All Courses Listed, Press 'A'. " << endl;
		cout << "Any Other Key Will Exit This Application. " << endl;
		cin >> userOption;

		if(toupper(userOption) == 'S')
		{
			cout << "Enter 'P' to Search by Course Prefix, or 'N' to Search by Course Number. 'N' is the default. " << endl;
			cin >> userOption2;

			if(toupper(userOption2) == 'N' || toupper(userOption2) != 'P')
			{
				courses.CourseNumSearch(courseList);
			}

			else if(toupper(userOption2) == 'P')
			{
				courses.CoursePrefixSearch(courseList);
			}
		}


		else if(toupper(userOption) == 'E')
		{
			courses.Enrolled(courseList);
		}


		else if(toupper(userOption) == 'V')
		{
			courses.EnrollmentStatus();
		}

		else if(toupper(userOption) == 'A')
		{
			courses.GetAllCourses(courseList);
		}
	}
	while(toupper(userOption) == 'S' || toupper(userOption) == 'E' || toupper(userOption) == 'V' || toupper(userOption) == 'A');


	return 0;
}
