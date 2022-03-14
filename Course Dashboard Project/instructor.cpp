#include "instructor.h"
#include "course.h"


//Default Constructor
Instructor::Instructor()
{

	this->firstName = "Hash-Slinging";
	this->lastName = "Slasher";	
}


//Parameterized Constructor 
Instructor::Instructor(string names)
{
	this->SetName(names);
}



//Private Function that Sets the Name of the Instructor by paring the string
void Instructor::SetName(string names)
{
	string name;  //Holds parsed name of names argument

	istringstream is(names);

	//Separates String Name Into First Name and Last Name
	while(getline(is, name, ','))
	{
		this->lastName = name;
		
		if(getline(is, name, ','))
		{
			this->firstName = name;
		}
	}
}



//Outputs Instructor Object
ostream& operator<<(ostream& os, const Instructor& instr)
{
	os << "Instructor: " << instr.firstName << " " << instr.lastName;

	return os;
}

