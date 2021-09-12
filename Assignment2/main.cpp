// main.cpp

#include "menus.h"
#include "input.h"
#include "optionOne.h"
#include "Employee.h"

#include<cctype>

void mainMenu(void);
void programOne(std::vector<Employee> employees);
void programTwo(void);
void programOneSubProgram(std::vector<Employee> employees);

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
        case 'c': case 'C': /*function here*/; pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        case 'd': case 'D': programOneSubProgram(employees); pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        case 'e': case 'E': /*function here*/; pause("\t\tPress enter to continue..."); clearScreen(); displayOptionOneMenu(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }

    } while (true);
}

void programOneSubProgram(std::vector<Employee> employees)
{
    system("CLS");
    displayOptionOneSubMenu();
    do
    {
        int option = inputChar("\t\t\tOption: ");

        switch (option)
        {
        case '0': programOne(employees); break;
        case 'a': case 'A': displayAllRecords(employees); displayOptionOneSubMenu(); break;
        case 'b': case 'B': displayAllActiveRecords(employees); displayOptionOneSubMenu(); break;
        case 'c': case 'C': displayAllInactiveRecords(employees); displayOptionOneSubMenu(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }
    } while (true);
}

void programTwo(void)
{
    // stuff here
}