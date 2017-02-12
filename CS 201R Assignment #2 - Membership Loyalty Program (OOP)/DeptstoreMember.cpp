#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "DeptstoreMember.h"

using namespace std;

//DeptstoreMember.cpp
//CPP file for header "DeptstoreMember.h"

// Default Constructor
DeptstoreMember::DeptstoreMember()
{
	idNumber = 0;
	num_outstanding = 0;
	price_original = 0.0;
	first_name = "";
	last_name = "";
	fullName = "";
}

// Deconstructor
DeptstoreMember::~DeptstoreMember()
{
}

// ID Number
void DeptstoreMember::setID(int idnum)
{
	idNumber = idnum;
}
int DeptstoreMember::getID()
{
	return idNumber;
}


// First Name
void DeptstoreMember::setFirstName(std::string firstn)
{
	first_name = firstn;
}
string DeptstoreMember::getFirstName()
{
	return first_name;
}

// Last Name
void DeptstoreMember::setLastName(std::string lastn)
{
	last_name = lastn;
}
string DeptstoreMember::getLastName()
{
	return last_name;
}


// Full Name
void DeptstoreMember::setFullName(std::string lastn, std::string firstn)
{
	fullName = lastn + ", " + firstn;
}

string DeptstoreMember::getFullName()
{
	return fullName;
}

// Original Price
void DeptstoreMember::setoriginal_price(double original)
{
	price_original = original;
}
double DeptstoreMember::getoriginal_price()
{
	return price_original;
}

// Discounted Price
double DeptstoreMember::DiscountedPrice(double price)
{
	return price * 0.95;
}

// Reward Price
double DeptstoreMember::reward(double calcreward)
{
	return calcreward * 0.95 * 0.01;
}

// Validity when reading in data
bool DeptstoreMember::ReadData(int istream)
{
	if (num_outstanding < 0 || num_outstanding > 10)
	{
		return false;
	}

	else
	{
		return true;
	}

}