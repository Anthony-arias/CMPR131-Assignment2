// main.cpp

#include "menus.h"
#include "input.h"
#include "optionOne.h"
#include "Employee.h"

#include<cctype>

void mainMenu(void);
void programOne(std::vector<Employee> employees);
void programTwo(void);
void programOneSubProgramOne(std::vector<Employee> employees);
void programOneSubProgramTwo(std::vector<Employee> employees);

int main(void)
{
    mainMenu();
    return EXIT_SUCCESS;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{

    std::vector<Employee> employees;

    clearScreen();

    displayMainMenu();

    do
    {
        int userInput = inputInteger("\t\tOption: ");
        switch (userInput)
        {
        case 0: clearScreen(); exit(1);  break;
        case 1: clearScreen(); programOne(employees); break;
        case 2: clearScreen(); programTwo(); break;
        default: cout << "\tERROR-3A: Invalid input. Must be from 0..2." << endl << endl; break;
        }
    } while (true);
}

void programOne(std::vector<Employee> employees)
{
    system("CLS");
    displayOptionOneMenu();
    do
    {
        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': mainMenu(); break;
        case 'a': case 'A': readData(employees); pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        case 'b': case 'B': insertEmployee(employees); pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        case 'c': case 'C': programOneSubProgramTwo(employees);; pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        case 'd': case 'D': programOneSubProgramOne(employees); pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        case 'e': case 'E': writeData(employees); pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }

    } while (true);
}

void programOneSubProgramOne(std::vector<Employee> employees)
{
    system("CLS");
    displayOptionOneSubMenuOne();
    do
    {
        int option = inputChar("\t\t\tOption: ");

        switch (option)
        {
        case '0': programOne(employees); break;
        case 'a': case 'A': displayAllRecords(employees); displayOptionOneSubMenuOne(); break;
        case 'b': case 'B': displayAllActiveRecords(employees); displayOptionOneSubMenuOne(); break;
        case 'c': case 'C': displayAllInactiveRecords(employees); displayOptionOneSubMenuOne(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }
    } while (true);
}

void programOneSubProgramTwo(std::vector<Employee> employees)
{
    system("CLS");

    int employeeListSize = employees.size();
    string prompt = "\t\t\Enter a valid employee ID (1.." + to_string(employeeListSize) + "): ";
    char employeeId = inputInteger(prompt, 1, employeeListSize);


    Employee temp;
    int employeeIndex = 0;
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].getEmployeeNumber()[0] == to_string(employeeId)[0])
        {
            temp = employees[i];
            employeeIndex = i;
            break;
        }
    }

    displayOptionOneSubMenuTwo(temp);

    do
    {
        int option = inputChar("\t\t\tOption: ");
        switch (option)
        {
        case '0': programOne(employees); break;
        case '1': employees[employeeIndex] = temp; programOne(employees); break;
        case 'a': case 'A': updateRecord(temp, "status"); displayOptionOneSubMenuTwo(temp); break;
        case 'b': case 'B': updateRecord(temp, "last"); displayOptionOneSubMenuTwo(temp); break;
        case 'c': case 'C': updateRecord(temp, "first"); displayOptionOneSubMenuTwo(temp); break;
        case 'd': case 'D': updateRecord(temp, "start"); displayOptionOneSubMenuTwo(temp); break;
        case 'e': case 'E': updateRecord(temp, "end"); displayOptionOneSubMenuTwo(temp); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }
    } while (true);
}

void programTwo(void)
{
    // stuff here
}