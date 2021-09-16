// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

#include "Employee.h"
#include "input.h"

#include<sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

// Function Prototypes

// this prototype will throw error
//void displayRecords(std::vector<Employee> obj, char option = NULL);
void readData(std::vector<Employee>& obj);
void writeData(std::vector<Employee> obj);
void insertEmployee(std::vector<Employee>& obj);
void updateRecord(Employee& thisEmployee, std::string option);

bool dateValidation(std::string date);
bool isLeap(int year);

// Function Definitions

void readData(std::vector<Employee>& obj)
{
    std::vector<vector<string>> fileData;

    std::ifstream source;
    while (true)
    {
        string s;
        source.open(inputString("\n\t\tEnter the file name: ", true));
        if (!source.fail()) break;
        std::cout << "\t\tOpen failed, try again" << std::endl;
        source.clear();
    }

    while (true)
    {
        std::string line;
        std::getline(source, line);
        if (source.fail()) break; // not "failure", just end of file

        std::vector<string> fileLine;
        std::stringstream stream(line);
        while (stream.good()) {
            string substr;
            getline(stream, substr, ',');
            if (substr.empty()) break;
            fileLine.push_back(substr);
        }
        fileData.push_back(fileLine);
    }

    for (int i = 0; i < fileData.size(); i++)
    {
        if (fileData[i].size() != 6) continue; // if employee data is incomplete skip to next data set

        // wont add data to list if entry with same id is present
        bool idAlreadyExists = false;
        for (int y = 0; y < obj.size(); y++)
        {
            if ( obj[y].getEmployeeNumber() == fileData[i][1])
            {
                idAlreadyExists = true;
                break;
            }
        }
        
        if (idAlreadyExists) continue;

        Employee employee;

        if (fileData[i][0] == "a" || fileData[i][0] == "A" || fileData[i][0] == "i" || fileData[i][0] == "I" || fileData[i][0] == "u" || fileData[i][0] == "U")
            employee.setStatus(fileData[i][0]);
        else
            employee.setStatus("U");

        employee.setEmployeeNumber(fileData[i][1]);
        employee.setLastName(fileData[i][2]);
        employee.setFirstName(fileData[i][3]);

        if (!dateValidation(fileData[i][4]) && (fileData[i][4] != "Current" || fileData[i][4] != "current"))
            employee.setStartDate("01/01/1900");
        else
            employee.setStartDate(fileData[i][4]);

        if (!dateValidation(fileData[i][5]) || fileData[i][5] == "current" || fileData[i][5] == "Current")
            employee.setEndDate(true);
        else
            employee.setEndDate(fileData[i][5]);

        obj.push_back(employee);
    }
}

void writeData(std::vector<Employee> obj)
{
    if (obj.size() == 0)
    {
        std::cout << "\n\t\tERROR: list is empty." << std::endl;
        return;
    }
    std::string fileName = inputString("\n\t\tEnter a file name: ", false);
    std::ofstream outFile(fileName);
    if (outFile.is_open())
    {
        for (int i = 0; i < obj.size(); i++)
        {
            outFile << std::string(1, obj[i].getStatus()) + "," + obj[i].getEmployeeNumber() + "," + obj[i].getLastName()
                + "," + obj[i].getFirstName() + "," + obj[i].getStartDate() + "," + obj[i].getEndDate() << std::endl;
        }
        outFile.close();
    }
    else std::cout << "\n\t\tError: File could not be opened" << std::endl;

}

void updateRecord(Employee& thisEmployee, std::string option)
{
    if (option == "status")
    {
        char input;
        while (true)
        {
            input = inputChar("\n\t\t\tChange status to A-active, I-inactive or U-Unknown status: ");
            if (tolower(input) == 'a' || tolower(input) == 'i' || tolower(input) == 'u')
            {
                thisEmployee.setStatus(std::string(1, input));
                break;
            }

            cout << "\t\tERROR: Only A-Active, I-Inactive, or U-Unknown allowed. try again." << endl;
        }
    }

    else if (option == "last")
    {
        thisEmployee.setLastName(inputString("\n\t\t\tEnter the last name: ", true));
    }
    else if (option == "first")
    {
        thisEmployee.setFirstName(inputString("\n\t\t\tEnter the new first name: ", true));
    }
    else if (option == "start")
    {
        string startDate;
        while (true)
        {
            startDate = inputString("\n\t\t\tEnter the start date: ", false);
            if (!dateValidation(startDate))
            {
                std::cout << "\n\t\t\tERROR: Invalid date input. Must be a mm/dd/yyyy.\n";
                continue;
            }

            break;
        }
        thisEmployee.setStartDate(startDate);
    }
    else if (option == "end")
    {
        string endDate;
        while (true)
        {
            endDate = inputString("\n\t\t\tEnter the new ending date: ", false);
            if (!dateValidation(endDate) && (endDate != "Current" || endDate != "current"))
            {
                std::cout << "\n\t\tERROR: Invalid date input. Must be a mm/dd/yy.\n";
                continue;
            }

            break;
        }
        thisEmployee.setEndDate(endDate);
    }
}

void displayRecords(std::vector<Employee> obj, char option = NULL)
{
    if (obj.size() == 0)
    {
        std::cout << "\n\t\t\tNo record found." << std::endl;
        return;
    }

    if (option == NULL)
    {
        for (int i = 0; i < obj.size(); i++)
        {
            std::cout << "\n\t\tEmployee ID\t: " << obj[i].getEmployeeNumber() << std::endl;
            std::cout << "\t\tName\t\t: " << obj[i].getLastName() + ", " + obj[i].getFirstName() << std::endl;
            std::cout << "\t\tStatus\t\t: " << obj[i].getStatus() << std::endl;
            std::cout << "\t\tStart Date\t: " << obj[i].getStartDate() << std::endl;
            std::cout << "\t\tEnd Date\t: " << obj[i].getEndDate();
            std::cout << std::endl;
        }
    }
    else
    {
        int count = 0;

        for (int i = 0; i < obj.size(); i++)
        {
            if (obj[i].getStatus() == option || obj[i].getStatus() == tolower(option))
            {
                std::cout << "\n\t\tEmployee ID   : " << obj[i].getEmployeeNumber() << std::endl;
                std::cout << "\t\tName          : " << obj[i].getLastName() + ", " + obj[i].getFirstName() << std::endl;
                std::cout << "\t\tStatus        : " << obj[i].getStatus() << std::endl;
                std::cout << "\t\tStart Date    : " << obj[i].getStartDate() << std::endl;
                std::cout << "\t\tEnd Date      : " << obj[i].getEndDate();
                std::cout << std::endl;

                count++;
            }
        }

        if (count == 0)
        {
            std::cout << "\n\t\t\tNo record found." << std::endl;
            return;
        }
    }
}

void insertEmployee(std::vector<Employee>& obj)
{
    clearScreen();
    std::cout << "\t\tInsert a new employee record into the list" << endl;
    std::cout << "\t" + string(85, char(205)) << endl << endl;
    std::string lastName = inputString("\t\tEnter the last name: ", true);
    std::string firstName = inputString("\t\tEnter the first name: ", true);
    std::string startDate;
    while (true)
    {
        startDate = inputString("\t\tEnter the start date: ", false);
        if (!dateValidation(startDate))
        {
            std::cout << "\t\tERROR: Invalid date input. Must be a mm/dd/yy.\n";
            continue;
        }

        break;
    }

    Employee temp(lastName, firstName, startDate);
    obj.push_back(temp);

}

bool dateValidation(std::string date)
{
    if (date.length() < 10 || date.length() > 10)
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

bool isLeap(int year)
{
    if (year < 1)
        return false;

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}


#endif