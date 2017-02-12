#pragma once

#ifndef DEPTSTOREMEMBER_H
#define DEPTSTOREMEMBER_H

// Set up class DeptstoreMember
class DeptstoreMember
{
private:
	// Member Variables
	int idNumber, num_outstanding, num_purchased, price_purchased;
	double price_original;
	std::string first_name;
	std::string last_name;
	std::string fullName;

public:
	// Default Constructor
	DeptstoreMember();

	// Destructor
	~DeptstoreMember();

	//Accessor Functions:

	//Member ID
	void setID(int);
	int getID();
	// getID() - return the ID number of the member


	//First Name
	void setFirstName(std::string);
	std::string getFirstName();
	// getFirstName() - return the First name of the member


	//Last Name
	void setLastName(std::string);
	std::string getLastName();
	// getLastName() - return the Last name of the member


	//Full Name
	void setFullName(std::string, std::string);
	std::string getFullName();
	// getFullName() - return the full name of the member in the format of Last name, First name
	

	//Original Price
	void setoriginal_price(double);
	double getoriginal_price();
	// getoriginal_price() - return the original price of the item


	//Discounted Price
	double DiscountedPrice(double);
	//DiscountedPrice - return the discounted price of the item


	//Reward
	double reward(double);
	//reward - return the reward of the item


	bool ReadData(int istream);
	//ReadData - return true if the data is read in correctly
};


#endif