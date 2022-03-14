#ifndef COURSE_H
#define COURSE_H

#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include <algorithm>
#include <bits/stdc++.h>

#include "instructor.h"
#include "classtime.h"

using namespace std;

class Course {

	private:
		string coursePrefix;  //Holds Course Prefix of the Course
		int courseNum;  //Holds Course Number of the Course
		int seatsAvailable;  //Holds Number of Seats Available of the Course
		int maxSeats;  //Holds Max Number of Seats of the Course
		int idNum;  //Holds ID Number of the Course
		vector<Course> enrolled;  //Holds List of Enrolled Courses
		Instructor instructor;  //Holds Instructor Object		
		ClassTime classtimes;  //Holds ClassTime Object

		//Private Functions
		bool MatchesCoursePrefixSearch(string coursePrefix, vector<Course> courseList, int position);
		bool MatchesCourseNumSearch(int courseNum, vector<Course> courseList, int position);
		bool Enroll(vector<Course> &courseList, int idEnroll);
	
	public:
		static int nextId;  //Increments id num 

		//Default Constructor
		Course();

		//Paramterized Constructor
		Course(string coursePrefix, int courseNum, Instructor& instructor, int maxSeats, int seatsAvailable, ClassTime& classtimes);
		
		//Getters
		int GetCourseNum();
		string GetCoursePrefix();
		int GetSeatsAvailable();
		int GetMaxSeats();	
		int GetIdNum();
		
		//Public Functions
		void GetAllCourses(vector<Course> courseList);
		void CourseNumSearch(vector<Course> courseList);
		void CoursePrefixSearch(vector<Course> courseList);
		void Enrolled(vector<Course> &courseList);
		void EnrollmentStatus();	
	
		friend ostream& operator<<(ostream& os, const Course& course);
};


#endif
