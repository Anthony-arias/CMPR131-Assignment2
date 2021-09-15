// Employee.h

#include<string>
#include<iostream>
// #include"ObjectCount.h"

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

	bool isTemporary; // used for new constructor to check if object is made is temporary or not

	void setEmployeeNumber();

	bool isLeap(int year);
	bool dateValidation(std::string date);

	static int objectCount;

public:

	Employee();
	Employee(std::string sts, std::string id, std::string lstNme, std::string frstNme, std::string strtDte, std::string endDte);
	Employee(std::string lstNme, std::string frstName, std::string strtDate);
	Employee(bool isTemp);
	~Employee();

	void setStatus(std::string sts);
	void setLastName(std::string name);
	void setFirstName(std::string name);
	void setEmployeeNumber(std::string iD);
	void resetEmployeeCount();

	bool setStartDate(std::string date);
	bool setEndDate(std::string date);
	bool setEndDate(bool sts);

	char getStatus();

	std::string getEmployeeNumber();
	std::string getLastName();
	std::string getFirstName();
	std::string getStartDate();
	std::string getEndDate();

	int getObjectCount() const;

	//std::ostream& operator<<(const Employee& obj);
	//friend std::ostream& operator<< (std::ostream& out, Employee const& obj);
};

#endif