// CS 201R - Assignment 4
// Due 10/30/16

// Program for Checked-In and Checked-Out Gym Items for Swinney Rec
// Keep track of items currently checked-out and update the file at the end of the day

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Student.h"

using namespace std;

int incArray(Student* &students_, int oldSize);

int main()
{
	int size = 30, studentCount = 0;
	unsigned int ID = 0;
	string itemDesc = "", itemCheckedIn;
	Student* students;
	students = new Student[size];

	// Input File - Read in Student information from the file
	ifstream roster("Students.txt");

	// Error handling - check if file is opened successfully or not
	if (!roster)
	{
		cout << "Error opening roster.txt";
		system("pause");
		return 1;
	}

	// Read in data to the array 
	while (roster.good())
	{
		roster >> students[studentCount];
		studentCount++;
		if (studentCount == size)
			size = incArray(students, size);
	}

	roster.close();

	// Input File - Read in checked-out items from the file with the ID number of the student who checked that out
	ifstream itemsOut("checkouts.txt");

	// Error handling - check if file is opened successfully or not
	if (!itemsOut)
	{
		cout << "Error opening checkouts.txt";
		system("pause");
		return 1;
	}

	while (itemsOut.good())
	{
		bool found = false;
		itemsOut >> ID >> itemDesc;

		for (int i = 0; i < studentCount; i++)
		{
			if (ID == students[i].getID())
			{
				students[i].CheckOut(itemDesc);
				found = true;
				break;
			}
		}

if (found == false)
		{
			studentCount++;
			if (studentCount == size)
				size = incArray(students, size);
			students[studentCount - 1].setID(ID);
			students[studentCount - 1].CheckOut(itemDesc);
		}

	}

	itemsOut.close();

	// Input File - Read in checked in items from the file 
	ifstream itemsIn("checkins.txt");

	// Error handling - check if file is opened successfully or not
	if (!itemsIn)
	{
		cout << "Error opening checkins.txt";
		system("pause");
		return 1;
	}

	// Check if the item is on the Student's checked-out list
	while (itemsIn.good())
	{
		bool found = false;
		itemsIn >> itemCheckedIn;
		for (int i = 0; i < studentCount; i++) 
		{
			if (students[i].HasCheckedOut(itemCheckedIn))
			{
				found = students[i].CheckIn(itemCheckedIn);
			}
			if (found == true)
				break;
		}
	}

	itemsIn.close();

	// Output File - Write in (update) the file of the checked-out info 
	ofstream fout("Updated_Students.txt");

	for (int i = 0; i < studentCount; i++)
		fout << students[i];

	fout.close();
	
	system("pause");
	return 0;
}

// Function for resizing array ( doulbe the old size ) when the size exceeds 5
int incArray(Student* &students_, int oldSize)
{
	int newSize = oldSize * 2;

	Student* newStudents = new Student[newSize];

	for (int i = 0; i < oldSize; i++)
		newStudents[i] = students_[i];

	students_ = newStudents;

	return newSize;
}