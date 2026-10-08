#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

//accessors and mutators for the Bank class
void Bank::setInitialBalance(double balance) {
	c_totalBalance = balance;
}

void Bank::setInterestRate(double interest) {
	c_interestAmount = interest;
}

void Bank::setMonthlyDeposit(double deposit) {
	c_monthlyDeposit = deposit;
}

void Bank::setNumberOfYears(int years) {
	c_numberofYears = years;
}

void Bank::printDetails(int year, double yearEndBalance, double interestEarned) {
    cout << fixed << setprecision(2) << year << "\t\t$" << yearEndBalance << "\t\t$" << interestEarned << endl;
}

double Bank::calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) {
	//prints the header for the balance without monthly deposits
    cout << "     Balance and Interest Without Additional Monthly Deposits    " << endl;
	cout << string(66, '=') << endl;
	cout << "Year\t\tYear End Balance\t\tYear End Earned Interest" << endl;
    cout << string(66, '=') << endl;

	// Calculates the balance and interest for each year without monthly deposits
    double balance = t_initialInvestment;
    double monthlyInterestRate = (t_interestRate / 100) / 12;
    double interestEarned = 0.0;
    for (int i = 1; i <= t_numberOfYears; ++i) {
        double interestEarnedThisYear = 0.0;
        for (int j = 0; j < 12; ++j) {
            interestEarned = balance * monthlyInterestRate;
            balance += interestEarned;
            interestEarnedThisYear += interestEarned;
        }
        printDetails(i, balance, interestEarnedThisYear);
    }
    return balance;
}

double Bank::balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears) {
	//prints the header for the balance with monthly deposits
    cout << "      Balance and Interest With Additional Monthly Deposits      " << endl;
    cout << string(66, '=') << endl;
    cout << "Year\t\tYear End Balance\t\tYear End Earned Interest" << endl;
    cout << string(66, '=') << endl;
    
    //calculates the balance and interest for each year with  monthly deposits
    double balance = t_initialInvestment;
    double monthlyInterestRate = (t_interestRate / 100) / 12;
    double interestEarned = 0.0;
    for (int i = 1; i <= t_numberOfYears; ++i) {
        double interestEarnedThisYear = 0.0;
        for (int j = 0; j < 12; ++j) {
            interestEarned = balance * monthlyInterestRate;
            balance = balance + interestEarned + t_monthlyDeposit;
            interestEarnedThisYear += interestEarned;
        }
        printDetails(i, balance, interestEarnedThisYear);
    }
    return balance;
}