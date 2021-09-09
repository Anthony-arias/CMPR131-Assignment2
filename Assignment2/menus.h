// menus.h

#include <iostream>
#include <string>

using namespace std;

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter2 - ADT Assignments by Prof Q (1/6/21)" << endl;
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