// CS 201R - Assignment 4
// Due 10/30/16

#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;

// Default Constructor & Constructor - Initialize ID, First Name & Last Name
Student::Student() : ID(0), fName(""), lName(""), itemsOut(0)
{}

Student::Student(unsigned ID_) : ID(ID_), fName(""), lName(""), itemsOut(0)
{}

// Destructor
Student::~Student()
{
	if (list != nullptr)
		delete [] list;
}

// Getters - return constant ID(Unsinged-Prevent Negative Number), First Name & Last Name
unsigned Student::getID() const { return ID; }
string Student::getFName() const { return fName; }
string Student::getLName() const { return lName; }

// Count number of items being checked-out
unsigned Student::CheckoutCount() const { return itemsOut; }

// Setters - ID(Unsinged-Prevent Negative Number), First Name & Last Name
void Student::setID(unsigned ID_) { ID = ID_; }
void Student::setFName(string fName_) { fName = fName_; }
void Student::setLName(string lName_) { lName = lName_; }

// Verify if the item is NOT on the checked-out list; if successfully added, return true, else false
bool Student::CheckOut(const string & item)
{
	for (int i = 0; i < itemsOut; i++)
	{
		if (list[i] == item)
			return false;
	}

	if ((itemsOut % 5) == 0)             // Resize the array if it exceeds 5 
	{
		list = resizeList(itemsOut);
	}

	itemsOut++;

	list[itemsOut - 1] = item;

	return true;
}

//Verify the item is already on the checked-out list then remove it from the list
bool Student::CheckIn(const string & item)
{
	bool CheckInFlag = false;
	for (int i = 0; i < itemsOut; i++) {  // Loop through the list to find the matching item on the checked-out list
		if (list[i] == item) 
		{
			for (int j = i; j < itemsOut; j++) 
			{
				list[j] = list[j + 1];
			}
			CheckInFlag = true;
			itemsOut--;
		}
	}
	if (itemsOut == 0) {           // Delete the array if the item is the last one  in the list
		delete[] list;
	}
	return CheckInFlag;
}

// Verify the item is on the Student's Checked-out list or not
bool Student::HasCheckedOut(const string & item)
{
	bool found = false;
	for (int i = 0; i < itemsOut; i++)
	{
		if (list[i] == item)
		{
			found = true;
			break;
		}
	}
	return found;
}

// Delete all of the object's data - ID(0), First and Last name (""), all checked-out data erased
void Student::Clear()
{
	delete[] list;
	fName = "";
	lName = "";
	ID = 0;
}

// Overloading Comparisions Equality(==) & Inequality (!=) - check if 2 ojects have the same ID number
const bool Student::operator==(Student & student_) { return (ID == student_.ID); }
const bool Student::operator!=(Student & student_) { return (ID != student_.ID); }

// Increase list size by 5 spots when full
string * Student::resizeList(int oldSize)  
{
	int newSize = oldSize + 5;
	string* quickList = new string[newSize];
	for (int k = 0; k < oldSize; k++)
		quickList[k] = list[k];

	listSize = newSize;
	return quickList;
}

// Alias for CheckOut - Add Student on the left & unsigned integer on the right, return a new Object
const Student operator+(unsigned ID_, string & item_)
{
	Student student_(ID_);
	student_.CheckOut(item_);
	return student_;
}

// Alias for CheckOut - Add in place, doesn't create a new object, only check out for the student
const void operator+=(Student student_, string & item_)
{
	if (student_.itemsOut % 5 == 0)
	{
		student_.list = student_.resizeList(student_.itemsOut);
	}
	student_.itemsOut++;
	student_.list[student_.itemsOut - 1] = item_;
}

// Stream I/O - write in data (ID number, First Name, Last name and number of items currently checked-out)
ostream & operator << (ostream & output, const Student & student_)
{
	output << endl << setw(10) << left << student_.ID
		<< setw(20) << student_.fName + " " + student_.lName
		<< setw(3) << student_.itemsOut;
	for (int i = 0; i < student_.itemsOut; i++)
		output << " " << student_.list[i];
	output << endl;
	return output;
}

// Stream I/O - read in data from the text file
istream & operator >> (istream & input, Student & student_)
{
	int listSize = 5;
	input >> student_.ID;
	input >> student_.fName;
	input >> student_.lName;
	input >> student_.itemsOut;
	if (student_.itemsOut > 0)
	{
		student_.list = new string[listSize];
		for (int i = 0; i < student_.itemsOut; i++)
		{
			input >> student_.list[i];
			if (i == listSize - 1)                             // Resize the array if it exceeds size 5
				student_.list = student_.resizeList(listSize);
		}
	}
	return input;
}