//============================================================================
// Name        : Main_KaiChen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 12/11/2017
// Description : Final Project
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <time.h>
using namespace std;

#include "Account.h"
#include "StockNode.h"
#include "StockAccount.h"
#include "BankAccount.h"

#include "StockAccount.cpp"   // THIS IS NEEDED FOR MY COMPILER!!!

double findPrice(string symbol);

struct Result    // data structure to save data read from txt files
{
	string ticker[49];
	double price[49];
};
Result result1;
Result result2;
static StockAccount myStock;
static BankAccount myBank;
int main()
{
	/* read current stock positions from txt files */
	string line;
	ifstream stockFile ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/stock_account.txt");
	if (stockFile.is_open())
	{
		while ( getline (stockFile,line) )
		{
			myStock.push(new StockNode (line.substr(0,line.find_first_of('\t')), stod(line.substr(line.find_first_of('\t'),line.find_last_of('\t'))), stod(line.substr(line.find_last_of('\t'), line.find_first_of('\n')))));
		}
	stockFile.close();
	}

	/* read current bank account from txt files */
	ifstream bankFile ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/bank_account.txt");
	if (bankFile.is_open())
	{
		while ( getline (bankFile,line) )
		{
			myBank.setValue(stod(line));
		}
	bankFile.close();
	}

	/* some variables declaration */
	string symbol;
	double number;
	double unitPrice;
	StockNode *myPosition;

	time_t seconds;
	seconds = time(NULL);
	tm *timeinfo;
	timeinfo = localtime(&seconds);

	/* read data from Result_1.txt and save data into result1 */
	string file1[49];
	ifstream myfile ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/Result_1.txt");
	if (myfile.is_open())
	{
		int i=0;
		while ( getline (myfile,line) )
		{
			for (int i = 0; i < 11; i++) // remove date informaton
			{
				line.pop_back();
			}
			file1[i] = line;
			i++;
		}
	myfile.close();
	}
	else cout << "Unable to open file"; 

	for (int i=0; i<49; i++)
	{
		result1.ticker[i] = file1[i].substr(0, file1[i].find_first_of('\t'));
		result1.price[i] = stod(file1[i].substr(file1[i].find_first_of('\t'), file1[i].find_first_of('\n')));
	}

	/* read data from Result_2.txt and save data into result2 */
	string file2[49];
	ifstream myFile2 ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/Result_2.txt");
	if (myFile2.is_open())
	{
		int i=0;
		while ( getline (myFile2,line) )
		{
			for (int i = 0; i < 11; i++) // remove date informaton
			{
				line.pop_back();
			}
			file2[i] = line;
			i++;
		}
	myFile2.close();
	}
	else cout << "Unable to open file"; 

	for (int i=0; i<49; i++)
	{
		result2.ticker[i] = file2[i].substr(0, file2[i].find_first_of('\t'));
		result2.price[i] = stod(file2[i].substr(file2[i].find_first_of('\t'), file2[i].find_first_of('\n')));
	}

	/* Menu for Account */
	int accountChoice = 0;
	while(accountChoice != 3)
	{
		cout << "Welcome to the Account Management System" << endl;
		cout << "Please select an account to access:" << endl;
		cout << "1. Stock Portfolio Account" << endl;
		cout << "2. Bank Account" << endl;
		cout << "3. Exit" << endl;

		cin >> accountChoice;
		switch (accountChoice)
		{
			case 1: // stock account
			{
			/* Menu for StockAccount */
			int stockChoice = 0;

			while(stockChoice != 7)
			{
				cout << "Stock Portfolio Account" << endl;
				cout << "Please select an option:" << endl;
				cout << "1. Display the price for a stock symbol" << endl;
				cout <<	"2. Display the current portfolio" << endl;
				cout <<	"3. Buy shares" << endl;
				cout << "4. Sell shares" << endl;
				cout << "5. View a graph for the portfolio value" << endl;
				cout <<	"6. View transaction history" << endl;
				cout << "7. Return to previous menu" << endl;

				cin >> stockChoice;

				switch (stockChoice)
				{
					case 1: // display the price of a stock
					{
						/* 1. Display the price of a stock */
						cout << "Please enter the stock symbol: ";
						cin >> symbol;
						unitPrice = findPrice(symbol);
						if (unitPrice != -1)
						{
							cout << "Company-Symbol\tPrice-per-share" << endl;
							cout << symbol << "\t $" << unitPrice << endl;
							break;
						}
						else
						{
							cout << "Stock not found!" << endl;
						}
						break;
					}

					case 2: // display the current portfolio
					{
						/* 2. Display the current portfolio */
						myStock.print();
						break;
					}

					case 3: // Buy Shares
					{
						/* 3. Buy shares */
						cout << "Please enter the stock symbol you wish to purchase: ";
						cin >> symbol;
						cout << "Please enter the number of shares: ";
						cin >> number;
						cout << "Please enter the maximum amount you are willing to pay per share: ";
						double maxAmount = 0;
						cin >> maxAmount;
						unitPrice = findPrice(symbol);
						if (unitPrice*number > myBank.getValue())
						{
							cout << "Transaction Failed: you don't have enough money in bank to do this trade!" << endl;
						}
						else if (unitPrice != -1)
							if (unitPrice < maxAmount)
							{
								myPosition = myStock.findStock(symbol);
								if (myPosition == NULL)
									myStock.push(new StockNode (symbol, number, unitPrice));  // if not in the current portfolio
								else
									myPosition->setShares(myPosition->getShares() + number);  // if in the current portfolio
								cout << "You have purchased " << number << " shares of " << symbol << " at $" << unitPrice << " each for a total of $" << number * unitPrice << endl;
								myBank.setValue(myBank.getValue() - number * unitPrice);  // money is spent
								// write the transaction into txt files
								ofstream file;
								file.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/stock_transaction_history.txt", ios::app);
								file << "Buy\t" << symbol << "\t" << number << "\t" << unitPrice << "\t" << number*unitPrice << "\t" << asctime(timeinfo) << "\n";
								ofstream file1;
								file1.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/bank_transaction_history.txt", ios::app);
								file1 << "Buy_Stock\t" << number << "\t" << asctime(timeinfo) << "\t" << myBank.getValue() << "\n";
								ofstream file2;
								file2.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/portfolio_history.txt", ios::app);
								file2 << myStock.stockValue() + myBank.getValue() << "\n";
							}
							else
								cout << "Transaction Failed: stock price is higher than expectation!" << endl;
						else
							cout << "Transaction Failed: the stock is not available!" << endl;
						myStock.sortList();
						break;
					}

					case 4: // sell shares
					{
						/* 4. Sell shares */
						cout << "Please enter the stock symbol you wish to sell: ";
						cin >> symbol;
						cout << "Please enter the number shares you wish to sell: ";
						cin >> number;
						cout << "Please enter the minimum amount you are willing to sell per share: ";
						double minAmount = 0;
						cin >> minAmount;
						myPosition = myStock.findStock(symbol);
						if (myPosition != NULL)
						{
							unitPrice = findPrice(symbol);
							if (unitPrice > minAmount) // sell
							{
								myBank.setValue(myBank.getValue() + number * unitPrice);  // money is obtained by selling
								ofstream file1;
								file1.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/bank_transaction_history.txt", ios::app);
								file1 << "Sell_Stock\t" << number << "\t" << asctime(timeinfo) << "\t" << myBank.getValue() << "\n";
								ofstream file2;
								file2.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/portfolio_history.txt", ios::app);
								file2 << myStock.stockValue() + myBank.getValue() - number * unitPrice << "\n";
								// write the transaction into stock_transaction_history.txt
								ofstream file;
								file.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/stock_transaction_history.txt", ios::app);
								file << "Sell\t" << symbol << "\t" << number << "\t" << unitPrice << "\t" << number*unitPrice << "\t" << asctime(timeinfo) << "\n";
								if (number == myPosition->getShares()) // delete the node
								{
									myStock.deleteNode(myPosition);
								}
								else if (number < myPosition->getShares()) // change the position
								{
									myPosition->setShares(myPosition->getShares() - number);
								}
								else
								{
									cout << "Transaction Failed: you do not have that many shares in your portfolio!" << endl;
								}
							}
							else
								cout << "Transaction Failed: the market price is too low!" << endl;
						}
						else
							cout << "Transaction Failed: this stock cannot be found in your portfolio!" << endl;
						myStock.sortList();
						break;
					}

					case 5: // view a graph for the portfolio value
					{
						system ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/port_draw");
						break;
					}

					case 6: // view transaction history
					{
						/* 6. View transaction history */
						ifstream myFile3 ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/stock_transaction_history.txt");
						if (myFile3.is_open())
						{
							while ( getline (myFile3,line) )
							{
								cout << line << endl;
							}
						myFile3.close();
						}
						break;
					}

					default:
					{
						cout << "The program should never be here!" << endl;
						break;
					}
				} // end stockChoice
			}
			break;
			} // end stock menu

			case 2: // bank account
			{
				/* Menu for bank account */
				int bankChoice = 0;
				while (bankChoice != 5)
				{
				cout << "Bank Account" << endl;
				cout << "1. View account balance" << endl;
				cout << "2. Deposit money" << endl;
				cout << "3. Withdraw" << endl;
				cout << "4. Print out history" << endl;
				cout << "5. Return to previous menu" << endl;

				cin >> bankChoice;

				switch (bankChoice)
				{
					case 1:
					{
						cout << "You have $" << myBank.getValue() << " in your bank account" << endl;
						break;
					}
					case 2: // deposit money
					{
						cout << "Please select the amount you wish to deposit: ";
						cin >> number;
						myBank.setValue(myBank.getValue()+number);
						ofstream file;
						file.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/bank_transaction_history.txt", ios::app);
						file << "Deposit\t" << number << "\t" << asctime(timeinfo) << "\t" << myBank.getValue() << "\n";
						ofstream file2;
						file2.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/portfolio_history.txt", ios::app);
						file2 << myStock.stockValue() + myBank.getValue() << "\n";
						break;
					}
					case 3: // withdraw money
					{
						cout << "Please select the amount you wish to withdraw: ";
						cin >> number;
						myBank.setValue(myBank.getValue()-number);
						ofstream file2;
						file2.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/portfolio_history.txt", ios::app);
						file2 << myStock.stockValue() + myBank.getValue() << "\n";
						ofstream file;
						file.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/bank_transaction_history.txt", ios::app);
						file << "Withdraw\t" << number << "\t" << asctime(timeinfo) << "\t" << myBank.getValue() << "\n";
						break;
					}
					case 4: // print out history
					{
						ifstream myFile4 ("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/bank_transaction_history.txt");
						if (myFile4.is_open())
						{
							while ( getline (myFile4,line) )
							{
								cout << line << endl;
							}
						myFile4.close();
						}
						break;
					}
				}
				}
			} // end bank menu
		}
	}
	myBank.saveBankAccount();    // save current bank balance
	myStock.saveStockAccount();  // save current stock position
	return 0;
}


/* randomly select stock price from result1 and result2 */
double findPrice(string symbol)
{
	int rand1;
	srand(time(0)); // generate different sets of random numbers
	rand1 = time(0) % 2;
	bool test = 0;
	if (rand1 == 0) // pick up the price from result1
	{
		for (int i = 0; i < 49; i++)
		{
			if (result1.ticker[i] == symbol)
			{
				test = 1;
				return result1.price[i];
			}
		}
		if (test == 0)
		{
			return -1; // not found
		}
	}
	else if (rand1 == 1)           // pick up the price from result2
	{
		for (int i = 0; i < 49; i++)
		{
			if (result2.ticker[i] == symbol)
			{
				test = 1;
				return result2.price[i];
			}

		}
		if (test == 0)
		{
			return -1;  // not found
		}
	}
	else
		return -1;
}
