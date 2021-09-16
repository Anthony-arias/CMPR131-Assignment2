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

    do
    {

        clearScreen();

        displayMainMenu();


        int userInput = inputInteger("\t\tOption: ");
        switch (userInput)
        {
        case 0: clearScreen(); return;
        case 1: clearScreen(); programOne(employees); break;
        case 2: clearScreen(); programTwo(); break;
        default: cout << "\tERROR-3A: Invalid input. Must be from 0..2." << endl << endl; break;
        }

        employees.clear();

    } while (true);
}

void programOne(std::vector<Employee> employees)
{
    
    do
    {
        clearScreen();
        displayOptionOneMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': readData(employees); pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': insertEmployee(employees); pause("\n\tPress enter to continue...");  break;
        case 'c': case 'C': programOneSubProgramTwo(employees); break;
        case 'd': case 'D': programOneSubProgramOne(employees); break;
        case 'e': case 'E': writeData(employees); pause("\n\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
        }

    } while (true);
}

void programOneSubProgramOne(std::vector<Employee> employees)
{

    if (employees.size() == 0)
    {
        pause("\n\t\tERROR: list is empty.");
        return;
    }
    
    do
    {
        clearScreen();
        displayOptionOneSubMenuOne();

        int option = inputChar("\t\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': displayRecords(employees); pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': displayRecords(employees, 'A'); pause("\n\t\tPress enter to continue..."); break;
        case 'c': case 'C': displayRecords(employees, 'I'); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }

        break; 

    } while (true);
}

void programOneSubProgramTwo(std::vector<Employee> employees)
{
    if (employees.size() == 0)
    {
        pause("\n\t\tERROR: list is empty.");
        return;
    }

    int employeeListSize = employees.size();
    string prompt = "\n\t\t\Enter a valid employee ID (1.." + to_string(employeeListSize) + "): ";
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

    do
    {
        clearScreen();
        displayOptionOneSubMenuTwo(temp);

        int option = inputChar("\t\t\tOption: ");
        switch (option)
        {
        case '0': return;
        case '1': employees[employeeIndex] = temp; programOne(employees); break;
        case 'a': case 'A': updateRecord(temp, "status"); break;
        case 'b': case 'B': updateRecord(temp, "last"); break;
        case 'c': case 'C': updateRecord(temp, "first"); break;
        case 'd': case 'D': updateRecord(temp, "start"); break;
        case 'e': case 'E': updateRecord(temp, "end"); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }
    } while (true);
}

void programTwo(void)
{
    // stuff here
}