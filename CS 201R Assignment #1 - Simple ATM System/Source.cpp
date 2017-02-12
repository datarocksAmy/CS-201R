// CS 201R Assignment#1 - Simple ATM ( Deposit / Withdraw / Loan based on Credit Scores )

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// #1. Withdraw funtion 
void withdraw(int initial_bank_amount)
{
	bool reenter = false;
	char answer;
	double remain, wamount;

	while (!reenter)
	{
		// Prompt user for the amount to withdraw
		cout << "\n" << "How much money do you want to WITHDRAW from the account? " << "\n" << "( Current Amount in the Account -- $ " << initial_bank_amount << ") : ";
		cin >> wamount;


		if (cin.fail())
		{
			cout << "\n" << "Invalid Input. Please enter a number." << "\n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			reenter = false;
		}

		else if (wamount < 0)
		{
			cout << "Invalid Input. Please enter an amount greater than 0." << "\n" << endl;
			reenter = false;
		}

		else if (wamount > 0 && wamount > initial_bank_amount)
		{
			cout << "You don't have enough money to withdraw in your account." << "\n" << "Please Enter another amount." << endl;
			reenter = false;
		}

		else
		{
			// Calculate the remaining amount after withdrawing, print out the result and reconfirm the transaction with user
			remain = initial_bank_amount - wamount;

			cout << fixed << setprecision(3);
			cout << "\n" << "<<< WITHDRAW TRANSACTION >>>" << endl;
			cout << "===============================================================================" << "\n";
			cout << "The amount you are withdrawing is: $ " << wamount << "\n" << "The balance in your account after the withdraw is: $ " << remain << endl;
			cout << "===============================================================================" << endl;
			cout << "\n" << "--> Is this the correct amount you are withdrawing today? (Y/y/N/n): ";

			cin >> answer;

			bool check_answer = false;

			while (!check_answer)
			{
				if (answer == 'Y' || answer == 'y')
				{
					check_answer = true;
					reenter = true;
				}

				else if (answer == 'N' || answer == 'n')
				{
					check_answer = true;
					reenter = false;
				}

				else
				{
					cout << "Invalid input. Please enter Y/y/N/n: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					check_answer = false;
					cin >> answer;
				}
			}
		}
	}
	return;
}

//#2. Deposit Function
void deposit(int initial_bank_amount)
{
	bool reenter = false;
	char answer;
	double new_balance, damount;

	while (!reenter)
	{	// Prompt user for the amount to deposit
		cout << "\n" << "How much money do you want to DEPOSIT in the account?" << "\n" << "( Current Amount in the Account--$ " << initial_bank_amount << ") : ";
		cin >> damount;

		if (cin.fail())
		{
			cout << "\n" << "Invalid Input. Please enter a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			reenter = false;
		}

		else if (damount < 0)
		{
			cout << "\n" << "Invalid Input. Please enter an amount greater than 0." << endl;
			reenter = false;
		}

		else
		{	// Calculate the new balance after depositing, print out the result and reconfirm the transaction with user
			new_balance = initial_bank_amount + damount;

			cout << fixed << setprecision(3);
			cout << "\n" << "<<< DEPOSIT TRANSACTION >>>" << endl;
			cout << "===============================================================================" << "\n";
			cout << "The amount you are depositing is: $ " << damount << "\n" << "The new balance in your account after depositing is: $ " << new_balance << endl;
			cout << "===============================================================================" << endl;
			cout << "\n" << "--> Is this the correct amount you are depositing in today? (Y/y/N/n): ";

			cin >> answer;

			bool check_ans = false;
			while (!check_ans)
			{
				if (answer == 'Y' || answer == 'y')
				{
					check_ans = true;
					reenter = true;
				}

				else if (answer == 'N' || answer == 'n')
				{
					check_ans = true;
					reenter = false;
				}

				else
				{
					cout << "Invalid input. Please enter Y/y/N/n. ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					check_ans = false;
					cin >> answer;
				}

			}
		}
	}
	return;
}

// #3. Credit Score Function
void creditScore(int initial_bank_amount)
{
	bool reenter = false;
	int creditscore;
	double loan_amount, user_payment, remain_debt, payoff_months, interest;

	while (!reenter)
	{
		cout << "\n" << "What is your current Credit Score?" << "\n" << "Please enter a number from 0 - 1000." << "\n" << "[If you have score above 1000, please enter 1000]: ";
		cin >> creditscore;
		// Normal range of credit score is from 300(bad) to 1000 (Excellent), anything in between are possible & will definitely have some lower than 300 and more than 850.
		// Thus, I set the credit score range at a cap of 1000 and a floor of 0.

		if (cin.fail())
		{
			cout << "Invalid Input. Please enter a number between 0 and 1000." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			reenter = false;
		}

		else if (creditscore <= 0)
		{
			cout << "Invalid Input. Please enter your credit score as positive number." << endl;
			reenter = false;
		}

		else if (creditscore > 1000)
		{
			cout << "Off the chart input! Please enter a credit score less than 1000. " << endl;
			reenter = false;
		}
		else
		{
			reenter = true;
		}
	}

	// Determine the interest rate based on credit score.
	if (creditscore <= 500)
	{
		interest = 0.05;
	}
	else if (creditscore >= 501 && creditscore <= 700)
	{
		interest = 0.02;
	}
	else
	{
		interest = 0.01;
	}


	//Prompt user for the amount of loan that he/she is borrowing
	bool valid = false;
	while (!valid)
	{
		cout << "\n" << "How much loan do you want to take? $ ";
		cin >> loan_amount;

		if (cin.fail())
		{
			cout << "Invalid Input. Please enter a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			valid = false;
		}

		else if (loan_amount < 0)
		{
			cout << "Invalid Input. Please enter your loan as a positive number." << endl;
			valid = false;
		}

		else { valid = true; }
	}

	//Prompt user for number of months that he/she wishes to pay off
	bool test = false;
	while (!test)
	{
		cout << "\n" << "How many months do you wish to pay off the loan? ";
		cin >> payoff_months;

		if (cin.fail())
		{
			cout << "Invalid Input. Please enter a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			test = false;
		}
		else if (payoff_months < 0)
		{
			cout << "Invalid Input. Please enter your month as a positive number." << endl;
			test = false;
		}

		else { test = true; }
	}


	//Calculate how much the user has to pay back the loan per month
	user_payment = (loan_amount * (pow((1 + interest), (payoff_months / 12.0)))) / payoff_months;


	//Output result of monthly payment, balance of loan and remaining debt
	int fieldLength = 15;

	cout << fixed << setprecision(2);
	cout << "\n" << "<<< LOAN PAYMENT DETAILS UNDER CREDIT SCORE --> " << creditscore << " >>>"
		<< "\n" << "[ Monthly Payment: $ " << user_payment << " | Time Period: " << payoff_months << " months | Interest Rate: " << interest << "]" << endl;
	cout << "===============================================================================" << endl;
	cout << setw(7) << "Month" << setw(fieldLength + 5)
		<< "Loan Balance" << setw(fieldLength + 6)
		<< "Payment" << setw(fieldLength + 10)
		<< "Remain Debt" << endl;
	cout << "===============================================================================" << endl;


	for (int month_count = 1; month_count <= payoff_months; month_count++)
	{
		remain_debt = loan_amount - user_payment;

		if (remain_debt < 0)
		{
			user_payment = loan_amount;
			remain_debt = 0.00;
		}

		cout << fixed << setprecision(2);
		cout << setw(5) << right << month_count << setw(fieldLength - 2) << right
			<< " $ " << loan_amount << left << setw(fieldLength + 2) << right
			<< " $ " << user_payment << left << setw(fieldLength + 2) << right
			<< "($ " << left << remain_debt << ")"
			<< endl;

		loan_amount = remain_debt;

		// I'm setting this condition for buffer purpose. The user will be paying off loan earlier than he/she wishes based on this formula if the payoff months exceeds certain number.
		// The table will stop printing at the month the user pays off the debt.
		if (remain_debt == 0)
		{
			break;
		}

	}
	return;
}


//============================================================================== Main Program Starts here =======================================================================================================================================

int choice, initial_bank_amount = 10000;
char promptother;

int main()
{
	bool run = false;
	while (!run)
	{// Prompt user on what transaction to do

		bool flag = false;
		while (!flag)
		{
			cout << "\n What transaction do you want to do today? \n 1. Withdraw \n 2. Deposit \n 3. Credit Score \n Please Enter One Number: ";
			cin >> choice;

			if (cin.fail())
			{
				cout << "Invalid Input. Please enter a number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				flag = false;


			}
			else if (choice != 1 && choice != 2 && choice != 3)
			{
				cout << "Invalid Input." << "\n" << "Please enter your choice again ( 1, 2 or 3 ): ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> choice;
				flag = false;
			}

			else
			{
				switch (choice)
				{
				case 1:
					withdraw(initial_bank_amount);
					break;

				case 2:
					deposit(initial_bank_amount);
					break;

				case 3:
					creditScore(initial_bank_amount);
					break;
				}
				break;
			}
		}


		//Prompt user again if he/she wants to do another transaction; if not, exit the program

		cout << "\n" << "--> Do you want to perform another transaction? (Y/y/N/n): ";
		cin >> promptother;

		bool flag2 = false;
		while (!flag2)
		{
			if (promptother == 'Y' || promptother == 'y')
			{
				flag2 = true;
				run = false;
			}
			else if (promptother == 'N' || promptother == 'n')
			{
				cout << "\n" << "Thank you for chooing us today. Please visit again next time! " << endl;
				flag2 = true;
				run = true;

			}
			else
			{
				cout << "Invalid input. Please enter Y/y/N/n : ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> promptother;
				flag2 = false;

			}
		}
	}

	system("pause");
}
