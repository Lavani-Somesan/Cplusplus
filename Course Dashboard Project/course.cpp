#include "course.h"
#include "instructor.h"


int Course::nextId = 0;


//Default Constructor for Course
Course::Course() 
{
	coursePrefix = "NA";
	courseNum = 0;
	seatsAvailable = 0;
	maxSeats = 0;
	idNum = nextId;
}


//Parameter Constructor for Course Class
Course::Course(string coursePrefix, int courseNum, Instructor& instructor, int maxSeats, int seatsAvailable, ClassTime& classtimes)
{
	this->instructor = instructor;
	this->coursePrefix = coursePrefix;
	this->courseNum = courseNum;
	this->maxSeats = maxSeats;
	this->seatsAvailable = seatsAvailable;
	this->classtimes = classtimes;
	idNum = nextId;
	++nextId;
	
}


//Gets Course Number for the Course
int Course::GetCourseNum()
{
	return courseNum;
}


//Gets Course Prefix for the Course
string Course::GetCoursePrefix()
{
	return coursePrefix;
}


//Gets Maximum Seats in the Course
int Course::GetMaxSeats()
{
	return maxSeats;
}


//Gets Seats Available for the Course
int Course::GetSeatsAvailable()
{
	return seatsAvailable;
}


//Gets ID Number of Course
int Course::GetIdNum()
{
	return idNum;
}



//Function that tests if the Course Number entered by the user mathces one of the Course Numbers
//in the course list vector. If so, it the function returns true, if not it returns false.
bool Course::MatchesCourseNumSearch(int courseNum, vector<Course> courseList, int position)
{
	if(courseNum == courseList[position].GetCourseNum())
	{
		return true;
	}
		
	return false;
}


//Function that prompts the user to enter a course number and calls a private function
//to see if the course number matches one of the coures. Prints out the course if matched.
void Course::CourseNumSearch(vector<Course> courseList)
{
	int courseNumSearch;
	bool matchFound = false;
	

	cout << "Enter the Course Number to Search for: ";
        cin >> courseNumSearch;


        for(unsigned i = 0; i < courseList.size(); i++)
        {
        	if(MatchesCourseNumSearch(courseNumSearch, courseList, i) == true)
                {
                	cout << courseList[i];
                        cout << endl;
                        matchFound = true;
                }
        }


        if(matchFound == false)
        {
        	cout << "No Match Was Found." << endl;
        }
}


//Function that tests if the Course Prefix entered by the user mathces one of the Course Prefix
//position in the course list. If so, the function returns true, if not it returns false.
bool Course::MatchesCoursePrefixSearch(string coursePrefix, vector<Course> courseList, int position)
{
	//Makes user entered prefix into upper case 
	transform(coursePrefix.begin(), coursePrefix.end(), coursePrefix.begin(),::toupper);
	
	if(coursePrefix == courseList[position].GetCoursePrefix())
	{
		return true;
	}
	 
	
	return false;
}



//Function that prompts the user to enter a course prefix and calls a private function
////to see if the course prefix matches one of the coures. Prints out the course if matched.
void Course::CoursePrefixSearch(vector<Course> courseList)
{
	string coursePrefixSearch;  //Holds User Entered Prefix
	bool matchFound = false;  //Holds Match Found boolean

	
	cout << "Enter the Course Prefix to Search for: ";
        cin >> coursePrefixSearch;


	//Loop that loops through courseList and calls private function to check
	//if there is a course match
	for(unsigned i = 0; i < courseList.size(); i++)
        {
        	if(MatchesCoursePrefixSearch(coursePrefixSearch, courseList, i) == true)
                {
                	cout << courseList[i];
                        cout << endl;
                        matchFound = true;
               	}
        }

        if(matchFound == false)
        {
        	cout << "No Match Was Found." << endl;
        }
}



//Private Function that takes in a user entered id number and checks to
//see if it exists and then checks if seats are available. If true, it 
//adds course to enrolled list and deincrements a seat. 
bool Course::Enroll(vector<Course> &courseList, int idEnroll)
{

	if(idEnroll <= idNum)
	{
		if(courseList[idEnroll].GetSeatsAvailable() > 0)
		{	
			courseList[idEnroll].seatsAvailable = courseList[idEnroll].seatsAvailable - 1;
			this->enrolled.push_back(courseList[idEnroll]);
			return true;
		}
	}

	return false;

}


//Function that calls a private function to enroll in a course using
//an id number. If true prints out Enrolled.
void Course::Enrolled(vector<Course> &courseList)
{
	 int idEnroll;

        cout << "Enter the ID Number of the Course You Want to Enroll In: " << endl;
        cin >> idEnroll;


	if(Enroll(courseList, idEnroll) == true)
        {
        	cout << "Enrolled in " << idEnroll << endl;
        }

        else
        {
        	cout << "Could not Enroll in Course either due to course being full or wrong id number." << endl;
        }	
}



//Function that Prints out the List of Classes Enrolled in.
//If False if prints out not enrolled in any courses.
void Course::EnrollmentStatus()
{
	if(enrolled.size() >= 1)
	{
		for(unsigned i = 0; i < enrolled.size(); i++)
		{
			cout << enrolled[i];
		}
	}

	else
	{
	cout << "You are not Enrolled in Any Courses." << endl;
	}
}


//Prints out all courses read from the file
void Course::GetAllCourses(vector<Course> courseList)
{
	for(unsigned i = 0; i < courseList.size(); i++)
	{
		cout << courseList[i];
	}
}


//Formats Output
ostream& operator<<(ostream& os, const Course& course)
{

	os<< endl;
	os << "ID " << course.idNum  << ":  ";
        os << course.coursePrefix << " " << course.courseNum << endl;
	os << course.instructor << endl;
	os << course.seatsAvailable << " seat remaining of " << course.maxSeats << endl;
	os << course.classtimes << endl;
        return os;
}

