// CS 201R - Assignment 4
// Due 10/30/16

#pragma once

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
	// Constructors
	Student();
	Student(unsigned ID_);
	~Student();

	// Getters
	unsigned getID() const;
	string getFName() const;
	string getLName() const;
	unsigned CheckoutCount() const;

	// Setters
	void setID(unsigned ID_);
	void setFName(string fName_);
	void setLName(string lName_);

	// Verify Checked-out & Check-in Status
	bool CheckOut(const string &item);
	bool CheckIn(const string &item);
	bool HasCheckedOut(const string &item);

	// Remove all of object's data
	void Clear();

	// Overloading operators for output result (student and items checked-out)
	friend const Student operator + (unsigned ID_, string & item_);
	friend const void operator += (Student student_, string & item_);
	const bool operator == (Student & student_);
	const bool operator != (Student & student_);

	// Stream I/O for reading in data and writing in them into files
	friend ostream& operator << (ostream & output, const Student & student_);
	friend istream& operator >> (istream & input, Student& student_);

private:
	// Variables 
	string fName;
	string lName;
	int listSize;
	unsigned ID;
	unsigned itemsOut;
	string *list;
	string * resizeList(int oldSize);
};

#endif