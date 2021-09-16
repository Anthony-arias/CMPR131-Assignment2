// menus.h

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter2 - ADT Assignments by Anthony, An, Van, Vincent, Nhan (9/16/21)" << endl;
    cout << "\t" + string(85, char(205)) << endl;
    cout << "\t\t1> List of Employees" << endl;
    cout << "\t\t2> Pseudorandom" << endl;
    cout << "\t" + string(85, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(85, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one menu options
void displayOptionOneMenu(void)
{
    cout << "\n\t1> List of Employees" << endl;
    cout << "\t" + string(85, char(205)) << endl;
    cout << "\t\tA> Read data from file and store into a list" << endl;
    cout << "\t\tB> Insert a new employee record into the list" << endl;
    cout << "\t\tC> Update an employee record from the list" << endl;
    cout << "\t\tD> Display all, active or inactive employee records from the list" << endl;
    cout << "\t\tE> Write data from the list to a file" << endl;
    cout << "\t" + string(85, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(85, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one sub menu options
void displayOptionOneSubMenuOne(void)
{
    cout << "\n\t\tDisplay Employee Record Information" << endl;
    cout << "\t\t" + string(85, char(205)) << endl;
    cout << "\t\t\tA> All records" << endl;
    cout << "\t\t\tB> Active records" << endl;
    cout << "\t\t\tC> Inactive records" << endl;
    cout << "\t\t" + string(85, char(196)) << endl;
    cout << "\t\t\t0> return" << endl;
    cout << "\t\t" + string(85, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one sub menu options
void displayOptionOneSubMenuTwo(Employee thisEmployee)
{
    char status = thisEmployee.getStatus();
    string statusOutput = "";

    if (thisEmployee.getStatus() == 'A') statusOutput = string(1, status) + "(active)";
    if (thisEmployee.getStatus() == 'I') statusOutput = string(1, status) + "(inactive)";
    if (thisEmployee.getStatus() == 'U') statusOutput = string(1, status) + "(unknown)";

    cout << "\n\t\tUpdate Employee ID: 1 Record Information" << endl;
    cout << "\t\t" + string(85, char(205)) << endl;
    cout << "\t\t\tA> Current status       : " << statusOutput << endl;
    cout << "\t\t\tB> Current last name    : " << thisEmployee.getLastName() << endl;
    cout << "\t\t\tC> Current first name   : " << thisEmployee.getFirstName() << endl;
    cout << "\t\t\tD> Current Starting date: " << thisEmployee.getStartDate() << endl;
    cout << "\t\t\tE> Current Ending date  : " << thisEmployee.getEndDate() << endl;
    cout << "\t\t" + string(85, char(196)) << endl;
    cout << "\t\t\t1> Commit the change(s) and return" << endl;
    cout << "\t\t\t0> Uncommit the change(s) and return" << endl;
    cout << "\t\t" + string(85, char(205)) << endl;
}