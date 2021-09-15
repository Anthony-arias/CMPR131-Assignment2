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
    
    do
    {
        clearScreen();
        displayOptionOneMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': mainMenu(); break;
        case 'a': case 'A': readData(employees); pause("\t\tPress enter to continue..."); break;
        case 'b': case 'B': insertEmployee(employees); pause("\t\tPress enter to continue...");  break;
        case 'c': case 'C': programOneSubProgramTwo(employees); break;
        case 'd': case 'D': programOneSubProgramOne(employees); break;
        case 'e': case 'E': writeData(employees); pause("\t\tPress enter to continue..."); break;
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
        case '0': programOne(employees); break;
        case 'a': case 'A': displayRecords(employees); pause("\t\t\tPress enter to continue..."); break;
        case 'b': case 'B': displayRecords(employees, 'A'); pause("\t\t\tPress enter to continue..."); break;
        case 'c': case 'C': displayRecords(employees, 'I'); pause("\t\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            displayOptionOneMenu(); continue;
        }
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
        case '0': programOne(employees); break;
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
    clearScreen();
	cout << "2> Pseudorandom Project" << endl;
	cout << string(100, char(196)) << endl;
    srand(time(0));
    const int SEED = 1;
    int multiplier = rand() % 999;
    int increment = rand() % 999;
    int modulus = rand() % 999;

//Project 11
	cout << "\t2> Pseudorandom Project" << endl;

	Pseudorandom object(seed, multiplier, increment, modulus);
    cout << "\ttest1 (pseudorandom): " << endl;
    cout << "\t\tSeed " << object.getSeed() << endl;
    cout << "\t\tGenerated random " << object.getModulus() << " different numbers.\n" << endl;
	cout << "\tFirst number: \n" << endl;
    cout << "\t\tmultiplier = " << object.getMultiplier() << 
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() << 
        ", and the new seed = " << object.returnNextNumber() << "\n" << endl;
    //next number
    cout << "\tNext number: \n" << endl;
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new seed = " << object.returnNextNumber() << "\n" << endl;
    //next number
    cout << "\tNext number: \n" << endl;
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new seed = " << object.returnNextNumber() << "\n" << endl;

 //Project 12


    vector<double> storeArray; // vector to store the element while looping 1 million times
    for (int i = 0; i < 1000000; i++)
    {
        //cout << "Div num: #" << i + 1 << " = " << object.returnDividedNextNumber() << endl;
        storeArray.push_back(static_cast<double>(object.returnDividedNextNumber()));
    }
    sort(storeArray.begin(), storeArray.end());

    cout << "\t\tRange           Number of Occurrences" << endl;
	cout << "\t\t[0.0 ... 0.1)   " << countElementsWithinRange(0.0, 0.1, storeArray) << endl;
	cout << "\t\t[0.1 ... 0.2)   " << countElementsWithinRange(0.1, 0.2, storeArray) << endl;
	cout << "\t\t[0.2 ... 0.3)   " << countElementsWithinRange(0.2, 0.3, storeArray) << endl;
	cout << "\t\t[0.3 ... 0.4)   " << countElementsWithinRange(0.3, 0.4, storeArray) << endl;
	cout << "\t\t[0.4 ... 0.5)   " << countElementsWithinRange(0.4, 0.5, storeArray) << endl;
	cout << "\t\t[0.5 ... 0.6)   " << countElementsWithinRange(0.5, 0.6, storeArray) << endl;
	cout << "\t\t[0.6 ... 0.7)   " << countElementsWithinRange(0.6, 0.7, storeArray) << endl;
	cout << "\t\t[0.7 ... 0.8)   " << countElementsWithinRange(0.7, 0.8, storeArray) << endl;
	cout << "\t\t[0.8 ... 0.9)   " << countElementsWithinRange(0.8, 0.9, storeArray) << endl;
	cout << "\t\t[0.9 ... 1.0)   " << countElementsWithinRange(0.9, 1.0, storeArray) << endl;
}
