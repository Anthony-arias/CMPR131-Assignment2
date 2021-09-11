// Employee.cpp
// September 9, 2021
// Currently getting error:
//	- Error	LNK2001	unresolved external symbol "private: static int ObjectCount::count" (? count@ObjectCount@@0HA)	Assignment2	C : \Users\Vince\OneDrive\CLASS WORK AND HOMEWORK\CMPR131\Module 2\Assignment2\Employee.obj	1
//	- it appears to be an issue with ObjectCount but I can't quite figure it out as of now
//
// September 10, 2021


#include "Employee.h"
#include "ctype.h"

#include <iostream>

	// Default constructor
Employee::Employee()
{
	setStatus("A");
	setEmployeeNumber();
	setLastName("Unknown");
	setFirstName("Unknown");
	setStartDate("01/02/1900"); // Default start date to start of company date.
	setEndDate(true);

	objectCount++;
}

// Constructor with Args
Employee::Employee(std::string sts, std::string id, std::string lstNme, std::string frstNme, std::string strtDte, std::string endDte)
{
	setStatus(sts);
	setEmployeeNumber(id);
	setLastName(lstNme);
	setFirstName(frstNme);
	setStartDate(strtDte); // Default start date to start of company date.
	setEndDate(endDte);

	objectCount++;

}

Employee::~Employee()
{
	objectCount--;
}

// Private Functions =========================================================
// 
// Precondition: NA
// Postcondition: employeeNumber is set to the number of instances of Employee objects made
void Employee::setEmployeeNumber()
{
	employeeNumber = std::to_string(getObjectCount());
}

// Precondition: String cannot be empty
// Postcondition: employeeNumber is set to iD
void Employee::setEmployeeNumber(std::string iD)
{
	if (iD.length() == 0)
		return;

	employeeNumber = iD;
}

// Precondition: year must be greater than 0
// Postcondition: Returns true if the year is a leap year, false if it isn't
bool Employee::isLeap(int year)
{
	if (year < 1)
		return false;

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	else
		return false;
}

// Precondition: date must be in form mm/dd/yyyy
// Postcondition: returns true if the date is entered in correct format, flase if it is not
bool Employee::dateValidation(std::string date)
{
	if (date.length() < 10)
		return false;

	if (date[2] != '/' || date[5] != '/')
		return false;

	std::string month = date.substr(0, 2);
	std::string day = date.substr(3, 2);
	std::string year = date.substr(6, 9);

	int monthInt = std::stoi(month);
	int dayInt = std::stoi(day);
	int yearInt = std::stoi(year);

	if (monthInt < 1 || monthInt > 12)
	{
		std::cout << "ERROR: Month out of bounds. Enter a date in mm/dd/yyyy" << std::endl;
		return false;
	}
	if ((dayInt < 1) || (isLeap(yearInt) && dayInt > 29))
	{
		std::cout << "ERROR: Day out of bounds. Enter a date in mm/dd/yyyy" << std::endl;
		return false;
	}
	if (!isLeap(yearInt) && dayInt > 28)
	{
		std::cout << "ERROR: Day out of bounds. Enter a date in mm/dd/yyyy" << std::endl;
		return false;
	}
	if (yearInt < 1900 || yearInt > 2021) // 1900 can be changed to whatever we would like. Placeholder for now.
	{
		std::cout << "ERROR: Year out of bounds. Enter a date in mm/dd/yyyy" << std::endl;
		return false;
	}

	return true;
}

// Public Functions ==========================================================
//
// Precondition: sts must equate to either u, a, or i
// Postcondition: status is set to sts
void Employee::setStatus(std::string sts)
{
	/*if (std::tolower(sts[0]) == 'u' || std::tolower(sts[0]) == 'i' || std::tolower(sts[0] == 'a'))
		status = toupper(sts[0]);
	else
		status = 'U';*/                                                                              //commented this out to test displayAllActiveRecords();
	status = sts[0];
}

// Precondition: none
// Postcondition: lastName is set to name
void Employee::setLastName(std::string name)
{
	lastName = name;
}

// Precondition: none
// Postcondition: firstName is set to name
void Employee::setFirstName(std::string name)
{
	firstName = name;
}

// Precondition: date must be in format mm/dd/yyyy
// Postcondition: startDate is set to date
bool Employee::setStartDate(std::string date)
{
	if (date.length() == 0)
		return false;

	if (!dateValidation(date))
	{
		startDate = date;
		return true;
	}

	return false;
}

// Precondition: date must be in the format mm/dd/yyyy
// Postcondition: startDate is set to date
bool Employee::setEndDate(std::string date)
{
	if (date.length() == 0)
		return false;

	if (!dateValidation(date))
	{
		endDate = date;
		return true;
	}

	return false;
}

// Precondiiton: NA
// Postcondition: if sts is true endDate is set to Current and true is returned, else false is returned
bool Employee::setEndDate(bool sts)
{
	if (sts)
	{
		endDate = "Current";
		return true;
	}

	return false;
}

// Precondition: NA
// Postcondition: return status
char Employee::getStatus()
{
	return status;
}

// Precondition: NA
// Postcondition: returns employeeNumber
std::string Employee::getEmployeeNumber()
{
	return employeeNumber;
}

// Precondition: NA
// Postcondition: returns lastName
std::string Employee::getLastName()
{
	return lastName;
}

// Precondition: NA
// Postcondiiton: returns firstName
std::string Employee::getFirstName()
{
	return firstName;
}
// Precondition: NA
// Postcondition: returns startDate
std::string Employee::getStartDate()
{
	return startDate;
}

// Precondition: NA
// Postcondition: return endDate
std::string Employee::getEndDate()
{
	return endDate;
}

// Precondition: NA
// Postcondition: Returns the number of objects that have been created
int Employee::getObjectCount() const
{
	return objectCount;
}

int Employee::objectCount = 1;