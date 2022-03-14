#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch.hpp"
#include "classtime.h"
#include "instructor.h"
#include "course.h"


TEST_CASE("ClassTime Class")
{
	std::ostringstream courseInfo;
	ClassTime ct;
	courseInfo << ct;
	REQUIRE(courseInfo.str() == "");

	courseInfo.str("");
	ClassTime ct2("0,1,2,3,4,5,6", "13:30-14:45");
	courseInfo << ct2;
	REQUIRE(courseInfo.str() == "Class is on Sunday & Monday & Tuesday & Wednesday & Thursday & Friday & Saturday from 13:30 to 14:45");

	// Test break of invalid day of week

	courseInfo.str("");
	ClassTime ct3("3,-1,4", "13:30-14:45");
	courseInfo << ct3;
	REQUIRE(courseInfo.str() == "Class is on Wednesday from 13:30 to 14:45");
}

TEST_CASE("Instructor Class")
{
	std::ostringstream instructor;

	Instructor oaklandAs;
	instructor << oaklandAs;
	REQUIRE(instructor.str() == "Crazy George");

	instructor.str("");
	Instructor adm("Hopper,Grace");
	instructor << adm;
	REQUIRE(instructor.str() == "Grace Hopper");

}

TEST_CASE("Course Class")
{
	std::ostringstream printedCourse;

	Course cs1;
	printedCourse << cs1;
	REQUIRE(printedCourse.str() == "CS 1\n\t0 seats remaining of 0.\n\tInstructor: Foo Bar.\n\tClass is on Monday & Tuesday & Wednesday from 1:00 to 1:15");
		
	
	Instructor instr("Turning,Alan");
	ClassTime ct("1,2,3", "12:15-13:30");
	
	Course cop3530("COP", 3530, instr, 30, 1, ct);
	printedCourse.str("");
	printedCourse << cop3530;
	REQUIRE(printedCourse.str() == "COP 3530\n\t1 seat remaining of 30.\n\tInstructor: Alan Turing.\n\tClass is on Monday & Tuesday & Wednesday from 12:15 to 13:30");
	
	printedCourse.str("");
	printedCourse << cop3530;
	REQUIRE(printedCourse.str() == "COP 3530\n\t0 seats remaining of 30.\n\tInstructor: Alan Turing.\n\tClass is on Monday & Tuesday & Wednesday from 12:15 to 13:30");
}
//
// Compile & run:
// make clean test
