// BankAccount class definition 
// BankAccount informaton is connected to StockAccount through cash balance
// Author: Kai Chen


#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount : public Account
{
public:
	BankAccount();         // constructor
	void setValue(double);       
	double getValue();
	void saveBankAccount();

};

/* class functions */
BankAccount::BankAccount()  // constructor
{
	value = 10000;
}

void BankAccount::setValue(double v)
{
	value = v;
}

double BankAccount::getValue()
{
	return value;
}

/* save current bank account information into a txt file */
void BankAccount::saveBankAccount()
{
	ofstream file;
	file.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/bank_account.txt", ios::trunc);
	file << value;
}


#endif