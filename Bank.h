//bank class definition
class Bank {
	//private member variables for the Bank class
private:
	double c_totalBalance;
	double c_interestAmount;
	double c_yearlyTotalInterest;
	double c_monthlyDeposit;
	int c_numberofYears;
	//public member functions for the Bank class
public:
	void setInitialBalance(double balance);
	void setInterestRate(double interest);
	void setMonthlyDeposit(double deposit);
	void setNumberOfYears(int years);
	double balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);
	double calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears);
	void printDetails(int year, double yearEndBalance, double interestEarned);
};