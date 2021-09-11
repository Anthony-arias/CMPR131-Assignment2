// main.cpp

#include "menus.h"
#include "input.h"
#include "optionOne.h"
#include "Employee.h"

void mainMenu(void);
void programOne(void);
void programTwo(void);

int main(void)
{
    mainMenu();
    return EXIT_SUCCESS;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    clearScreen();

    displayMainMenu();

    do
    {
        int userInput = inputInteger("\t\tOption: ");
        switch (userInput)
        {
        case 0: clearScreen(); exit(1);  break;
        case 1: clearScreen(); programOne(); break;
        case 2: clearScreen(); programTwo(); break;
        default: cout << "\tERROR-3A: Invalid input. Must be from 0..2." << endl << endl; break;
        }
    } while (true);
}

void programOne(void)
{
    displayOptionOneMenu();
    std::vector<Employee> Employees;
    do
    {
        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': mainMenu(); break;
        case 'a': case 'A': readData(Employees); displayOptionOneMenu(); break;
        case 'b': case 'B': /*function here*/; displayOptionOneMenu(); break;
        case 'c': case 'C': /*function here*/; displayOptionOneMenu(); break;
        case 'd': case 'D': /*function here*/; displayOptionOneMenu(); break;
        case 'e': case 'E': /*function here*/; displayOptionOneMenu(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
                 displayOptionOneMenu(); continue;
        }
    } while (true);
}

void programOneSubProgram(std::vector<Employee> Employees)
{
    displayOptionOneSubMenu();
    do
    {
        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': mainMenu(); break;
        case 'a': case 'A': displayAllRecords(Employees); displayOptionOneSubMenu(); break;
        case 'b': case 'B': /*function here*/; displayOptionOneSubMenu(); break;
        case 'c': case 'C': /*function here*/; displayOptionOneSubMenu(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }
    } while (true);
}

void programTwo(void)
{
    // stuff here
}