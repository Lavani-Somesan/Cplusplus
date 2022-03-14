#include "classtime.h"

//Default Constructor
ClassTime::ClassTime()
{
	for(int i = 0; i < 7; i++)
	{
	this->daysOfTheWeek[i] = -1;
	}
	
	for(int i = 0; i < 4; i++)
	{
	this->times[i] = 0;
	}
}


//Parameterized Constructor
ClassTime::ClassTime(string days, string times)
{
	this->SetDaysOfTheWeek(days);
	this->SetTime(times);
}


//Private Function that Sets the Days of the
//Week from the argument days.
void ClassTime::SetDaysOfTheWeek(string days)
{
	for(int i = 0; i < 7; ++i)
	{
		this->daysOfTheWeek[i] = -1;
	}

	istringstream is(days);
	string day;
	int i = 0;
	
	//Split the string at the comma (,)
	while(getline(is, day, ','))
	{
		this->daysOfTheWeek[i++] = atoi(day.c_str());
	}
}


//Private Function that Sets the Time of the
//Course from the argument times
void ClassTime::SetTime(string times)
{
	if(times == "")
	{
		this->times[ClassTime::START_HOUR] = 0;
		this->times[ClassTime::START_MINUTE] = 0;
		
		this->times[ClassTime::END_HOUR] = 0;
		this->times[ClassTime::END_MINUTE] = 0;
		return;
	}

	istringstream is(times);
	string part;
	string minOrHour;
	
	istringstream is2;

	for(int i = 0; i < 2; ++i)
	{
		//reset the string stream and set to new substring
		is2.str("");
		is2.clear();

		getline(is, part, '-');
		is2.str(part);
		getline(is2, minOrHour, ':');
		
		//we fetched the hours value as a string (required by getline), so lets cast it to an integer
		this->times[2*i] = atoi(minOrHour.c_str());

		//We can use the stream directly now that it's been setup with getline, so no need to cast anymore
		is2 >> this->times[2*i + 1];
	}
}


//Formats Output of ClassTime
ostream& operator<<(ostream& os, const ClassTime& ct)
{
	bool hasOtherDay = false;
	
	if(ct.daysOfTheWeek[0] >= 0)
	{
		os << "Class is on ";

		for(int i = 0; i < 7; i++)
		{
			if(ct.daysOfTheWeek[i] < 0)
			{
				break;
			}
			
			if(hasOtherDay)
			{
				os << "&";
			}

			else
			{
				hasOtherDay = true;
			}

			switch(ct.daysOfTheWeek[i])
			{
				
				case 0:
					os << "Sunday";
					break;
				case 1:
					os << "Monday";
					break;
				case 2:
					os << "Tuesday";
					break;
				case 3:
					os << "Wednesday";
					break;
				case 4:
					os << "Thrusday";
					break;
				case 5: 
					os << "Friday";
					break;
				case 6:
					os << "Saturday";
					break;
			}
		}
		
		os << " from " << ct.times[ClassTime::START_HOUR] << ":";
		os << std::setw(2) << std::setfill('0') << ct.times[ClassTime::START_MINUTE];
		os << " to " << ct.times[ClassTime::END_HOUR] << ":";
		os << std::setw(2) << std::setfill('0') << ct.times[ClassTime::END_MINUTE];
	}
	
	return os;
}


