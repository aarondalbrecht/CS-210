// Aaron Albrecht		June 6, 2026

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Bank.h"

using namespace std;

//intiallization of the bank class object and global variables
Bank myBank;
int years;
double initialInvestment;
double monthlyDeposit;
double interestRate;
char userChoice = ' ';
void menu();
int validInt();
double validDouble();

//main function to run the program
int main() {
	while (userChoice != 'q' && userChoice != 'Q') {
		system("cls");
		menu();
		system("PAUSE");
		myBank.calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, years);
		cout << endl;
		myBank.balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, years);
		cout << endl;
		cout << "Press 'Q' to quit or any other key to process another report: ";
		cin >> userChoice;
	}

	return 0;
}

//function to display the menu and get user input
void menu() {
	try {
		cout << string(34, '*') << endl;
		cout << string(10, '*') << "  Data Input  " << string(10, '*') << endl;

		cout << "Initial Investment Amount:  $";
		initialInvestment = validDouble();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid input.");
		}
		myBank.setInitialBalance(initialInvestment);

		cout << "Monthly Deposit:  $";
		monthlyDeposit = validDouble();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid input.");
		}
		myBank.setMonthlyDeposit(monthlyDeposit);

		cout << "Annual Interest:  %";
		interestRate = validDouble();
		if (interestRate < 0) {
			throw runtime_error("Invalid input.");
		}
		myBank.setInterestRate(interestRate);

		cin.clear();

		cout << "Number of years:  ";
		years = validInt();
		if (years < 0) {
			throw runtime_error("Invalid input.");
		}
		myBank.setNumberOfYears(years);
	}
	//catch block to handle invalid input and prompt the user to try again
	catch(runtime_error& excpt) {
		cerr << "Error: Invalid input. Please try again." << endl;
		system("PAUSE");
		system("cls");
		menu();
	}
}

//function to validate integer input
int validInt() {
	int value;
	while (true) {
		if (cin >> value) {
			return value;
		}
		else {
			cout << "Invalid input. Please enter an integer: ";
			cin.clear();
			while (cin.get() != '\n'); // Clear the input buffer)
		}
	}
}

//function to validate double input
double validDouble() {
	double value;
	while (true) {
		if (cin >> value) {
			return value;
		}
		else {
			cout << "Invalid input. Please enter a number: ";
			cin.clear();
			while (cin.get() != '\n'); // Clear the input buffer)
		}
	}
}