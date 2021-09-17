// Employee.h

#include<string>
#include<iostream>

#ifndef EMPLOYEE_LOCK
#define EMPLOYEE_LOCK

class Employee
{
private:

	char status;

	std::string employeeNumber;
	std::string lastName;
	std::string firstName;
	std::string startDate;
	std::string endDate;

	bool isTemporary = false; // used for new constructor to check if object is made is temporary or not

	bool isLeap(int year);
	bool dateValidation(std::string date);

public:

	Employee();
	Employee(std::string sts, std::string employeeNumber, std::string lstNme, std::string frstNme, std::string strtDte, std::string endDte);
	Employee(std::string lstNme, std::string frstName, std::string strtDate, std::string employeeNumber);

	void setStatus(std::string sts);
	void setLastName(std::string name);
	void setFirstName(std::string name);
	void setEmployeeNumber(std::string iD);

	bool setStartDate(std::string date);
	bool setEndDate(std::string date);
	bool setEndDate(bool sts);

	char getStatus();

	std::string getEmployeeNumber();
	std::string getLastName();
	std::string getFirstName();
	std::string getStartDate();
	std::string getEndDate();
};

#endif