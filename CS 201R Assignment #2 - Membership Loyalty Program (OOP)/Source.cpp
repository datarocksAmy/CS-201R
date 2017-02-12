// CS 201R Assignment #2 - Membership Loyalty Program for an Apartment Store
// Read in member data from file. Using class to store the member info and get discounted $ and rewards for each member.

// CHIA-HUI AMY LIN  16176145

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "DeptstoreMember.h"


using namespace std;

//--------------------------------------------------------------------------------- MAIN FUNCTION ---------------------------------------------------------------------------------
int main()
{	
	int idNumber, num_outstanding, count = 1;
	string Firstname, Lastname, nextLine;

	//File Read In
	ifstream inputfile("DeptCustomers.txt");
	if (inputfile.fail())
	{
		cout << "Input file opening fail. \n";
		exit(1);
	}

	
	DeptstoreMember member;
	double pricelist[50], discount[50], rewardcalc[50];

	//membervector to store information of each member
	vector <DeptstoreMember> membervector;
	
	while (inputfile >> idNumber >> Firstname >> Lastname >> num_outstanding)
	{
		if (member.ReadData(num_outstanding))
		{
			member.setID(idNumber);
			member.setFirstName(Firstname);
			member.setLastName(Lastname);

			double original_price = 0, rewardtotal = 0;

			//Store original price in an array. Calculated the discounted price and reward. Add up total reward.
			for (int i = 0; i < num_outstanding; i++)
			{
				inputfile >> pricelist[i];
				discount[i] = member.DiscountedPrice(pricelist[i]);
				rewardcalc[i] = member.reward(pricelist[i]);
				rewardtotal += rewardcalc[i];

			}

			//Get member's full name and id number
			member.setFullName(member.getLastName(), member.getFirstName());
			member.setID(idNumber);

			// Print out the results for each member
			cout << fixed << setprecision(2);
			cout << endl << "[ Member "<< count <<" - " << member.getFullName() << " ( ID # -> # " << member.getID() << " ) ]" << endl;
			cout << "_____________________________________________________________________________" << endl;
			cout << left << setw(10) << "    Original " << "   | " << right << setw(15) << "          Reward Cash Eared        " << " | " << right << setw(10) << " Total Amount " << " | " << endl;
			cout << left << setw(10) << "Undiscounted ($)" << "| " << right << setw(10) << "  For Each Item(After Discounted $)" << " | " << right << setw(10) << " of Rewards($)" << " | " << endl;
			cout << "-----------------------------------------------------------------------------" << endl;

			for (int k = 0; k < num_outstanding; k++)
			{
				cout << right << setw(10) << pricelist[k] << right << setw(28) << discount[k] << right << setw(27) << rewardcalc[k] << endl;
			}

			cout << "-----------------------------------------------------------------------------" << endl;
			cout << right << "Total Amount of Rewards: $ " << setw(38) << rewardtotal << endl;
			count++;

			// Store the current member info in the vector
			membervector.push_back(member);

			double pricelist[50];
			double discount[50];
			double rewardcalc[50];

		}

		else
		{
			cout << " Input file data invalid. Please check your file! " << endl;
			exit(1);
		}
	}
	
	inputfile.close();
	system("pause");
}

