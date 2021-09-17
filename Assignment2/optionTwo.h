// optionTwo.h 

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include <math.h>
#include <vector>

using namespace std;
// Functions Prototype
int countElementsWithinRange(double begin, double end, vector<double> v);
double checkUniformDistributed(int count);

// Class
class Pseudorandom
{
private:
	int seed = 0;
	int multiplier = 0;
	int increment = 0;
	int modulus = 0;

public:

	// Argument constructor
	Pseudorandom(int initialSeed, int newMultiplier, int newIncrement, int newModulus)
	{
		seed = initialSeed;
		multiplier = newMultiplier;
		increment = newIncrement;
		modulus = newModulus;
	}

	// Precondition: valid integer data
	// Postcondition: it will change the value of current "seed"
	void changeSeed(int newSeed)
	{
		seed = newSeed;
	}
	// Precondition: NA
	// Postcondition: return the next "seed" to replace the current "seed"
	int returnNextNumber()
	{
		int next;
		next = (multiplier * seed + increment) % modulus;
		seed = next;
		return next;
	}
	// Precondition: NA
	// Postcondition: return the value of "seed"
	int getSeed() const
	{
		return  seed;
	}
	// Precondition: NA
	// Postcondition: return the value of "multiplier"
	int getMultiplier() const
	{
		return  multiplier;
	}
	// Precondition: NA
	// Postcondition: return the value of "increment"
	int getIncrement() const
	{
		return  increment;
	}
	// Precondition: NA
	// Postcondition: return the value of "modulus"
	int getModulus() const
	{
		return  modulus;
	}
	// Precondition: NA
	// Postcondition: return the next value of divided number
	double returnDividedNextNumber()
	{
		int next = returnNextNumber();
		return next / double(modulus);
	}

};

// Additional functions

// Precondition: valid initial range and end range, valid vector that has double type
// Postcondition: count the elements that appear within range
int countElementsWithinRange(double begin, double end, vector<double> v)
{
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= begin && v[i] < end)
		{
			count++;
		}
	}
	return count;
}

// Precondition: the occurances of number in each interval
// Postcondition: return the percentage of number in each interval
double checkUniformlyDistributed(int count)
{
	return static_cast<double>((static_cast<double>(count) / 1000000.0) * 100.0);
}

#endif