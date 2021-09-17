// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 2: Abstract Data Types and C++ CLasses
// 09/16/2021

#include "menus.h"
#include "input.h"
#include "optionOne.h"
#include "Employee.h"
#include "optionTwo.h"
#include <cctype>

void mainMenu(void);
void programOne(std::vector<Employee> employees);
void programTwo(void);
void programOneSubProgramOne(std::vector<Employee> employees);
void programOneSubProgramTwo(std::vector<Employee>& employees);

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
        case 2: clearScreen(); programTwo(); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..2." << endl;
            pause("\n\t\tPress enter to continue...");
        }

        employees.clear();

    } while (true);
}

//PreCondition: input is an Employee vector
//PostCondition: lets user choose actions found in program one
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
        case 'b': case 'B': insertEmployee(employees); pause("\n\t\tPress enter to continue...");  break;
        case 'c': case 'C': programOneSubProgramTwo(employees); break;
        case 'd': case 'D': programOneSubProgramOne(employees); break;
        case 'e': case 'E': writeData(employees); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            pause("\n\t\tPress enter to continue...");
        }

    } while (true);
}

//PreCondition: input is an Employee vector
//PostCondition: lets user choose actions found in sub program one
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
            pause("\n\t\tPress enter to continue...");
        }

    } while (true);
}

//PreCondition: input is an Employee vector
//PostCondition: lets user choose actions found in sub program two
void programOneSubProgramTwo(std::vector<Employee>& employees)
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
        case '1': employees[employeeIndex] = temp; return;
        case 'a': case 'A': updateRecord(temp, "status"); break;
        case 'b': case 'B': updateRecord(temp, "last"); break;
        case 'c': case 'C': updateRecord(temp, "first"); break;
        case 'd': case 'D': updateRecord(temp, "start"); break;
        case 'e': case 'E': updateRecord(temp, "end"); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}

//PreCondition: NA
//PostCondition: generate a sequence of pseudorandom integers
void programTwo(void)
{
    clearScreen();
    cout << "2> Pseudorandom Project" << endl;
    cout << string(100, char(196)) << endl;
    srand(time(0));
    int seed = rand() % 9999;
    int multiplier = rand() % 9999;
    int increment = rand() % 9999;
    int modulus = rand() % 9999;

    //Project 11

    Pseudorandom object(seed, multiplier, increment, modulus);
    cout << "\ttest1 (pseudorandom): \n" << endl;
    cout << "\t\tSeed " << object.getSeed() << endl;
    cout << "\n\t\tGenerated random " << object.getModulus() << " different numbers.\n\n";
    cout << "\tFirst number: \n\n";
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new seed = " << object.returnNextNumber() << "\n\n";
    //next number
    cout << "\tNext number: \n\n";
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new seed = " << object.returnNextNumber() << "\n\n";
    //next number
    cout << "\tNext number: \n\n";
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new seed = " << object.returnNextNumber() << "\n\n";

    //Project 12

    cout << "\tFirst divided number: \n\n";
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new divided number = " << object.returnDividedNextNumber() << "\n\n";
    //next number
    cout << "\tNext divided number: \n\n";
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new divided number = " << object.returnDividedNextNumber() << "\n\n";
    //next number
    cout << "\tNext divided number: \n\n";
    cout << "\t\tmultiplier = " << object.getMultiplier() <<
        ", increment = " << object.getIncrement() << ", modulus = " << object.getModulus() <<
        ", and the new divided number = " << object.returnDividedNextNumber() << "\n\n";

    //Project 13
    vector<double> storeArray; // vector to store the element while looping 1 million times
    for (int i = 0; i < 1000000; i++)
    {
        storeArray.push_back(static_cast<double>(object.returnDividedNextNumber()));
    }
    sort(storeArray.begin(), storeArray.end());

    cout << "\t\tRange           Number of Occurrences\n" << endl;
    cout << "\t\t[0.0 ... 0.1)   " << countElementsWithinRange(0.0, 0.1, storeArray);
    cout << "\n\t\t[0.1 ... 0.2)   " << countElementsWithinRange(0.1, 0.2, storeArray);
    cout << "\n\t\t[0.2 ... 0.3)   " << countElementsWithinRange(0.2, 0.3, storeArray);
    cout << "\n\t\t[0.3 ... 0.4)   " << countElementsWithinRange(0.3, 0.4, storeArray);
    cout << "\n\t\t[0.4 ... 0.5)   " << countElementsWithinRange(0.4, 0.5, storeArray);
    cout << "\n\t\t[0.5 ... 0.6)   " << countElementsWithinRange(0.5, 0.6, storeArray);
    cout << "\n\t\t[0.6 ... 0.7)   " << countElementsWithinRange(0.6, 0.7, storeArray);
    cout << "\n\t\t[0.7 ... 0.8)   " << countElementsWithinRange(0.7, 0.8, storeArray);
    cout << "\n\t\t[0.8 ... 0.9)   " << countElementsWithinRange(0.8, 0.9, storeArray);
    cout << "\n\t\t[0.9 ... 1.0)   " << countElementsWithinRange(0.9, 1.0, storeArray);

    cout << "\n\n\t\tA pseudorandom number generator with this equal-interval behavior is called uniformly distributed.";
    cout << "\n\t\tWith good choices of the constants, you will end up with about 10 % of the numbers in each interval.\n\n";
    cout << "\t\tRange           Percentage (%)";
    cout << "\n\t\t[0.0 ... 0.1)   " << checkUniformlyDistributed(countElementsWithinRange(0.0, 0.1, storeArray));
    cout << "\n\t\t[0.1 ... 0.2)   " << checkUniformlyDistributed(countElementsWithinRange(0.1, 0.2, storeArray));
    cout << "\n\t\t[0.2 ... 0.3)   " << checkUniformlyDistributed(countElementsWithinRange(0.2, 0.3, storeArray));
    cout << "\n\t\t[0.3 ... 0.4)   " << checkUniformlyDistributed(countElementsWithinRange(0.3, 0.4, storeArray));
    cout << "\n\t\t[0.4 ... 0.5)   " << checkUniformlyDistributed(countElementsWithinRange(0.4, 0.5, storeArray));
    cout << "\n\t\t[0.5 ... 0.6)   " << checkUniformlyDistributed(countElementsWithinRange(0.5, 0.6, storeArray));
    cout << "\n\t\t[0.6 ... 0.7)   " << checkUniformlyDistributed(countElementsWithinRange(0.6, 0.7, storeArray));
    cout << "\n\t\t[0.7 ... 0.8)   " << checkUniformlyDistributed(countElementsWithinRange(0.7, 0.8, storeArray));
    cout << "\n\t\t[0.8 ... 0.9)   " << checkUniformlyDistributed(countElementsWithinRange(0.8, 0.9, storeArray));
    cout << "\n\t\t[0.9 ... 1.0)   " << checkUniformlyDistributed(countElementsWithinRange(0.9, 1.0, storeArray)) << "\n";
}
