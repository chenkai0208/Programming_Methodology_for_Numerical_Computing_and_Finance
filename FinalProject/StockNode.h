// node for double-linked list StockAccount
// Author: Kai Chen

#ifndef STOCKNODE_H
#define STOCKNODE_H

#include <iostream>
#include <string>

using namespace std;

class StockNode
{
	friend class StockAccount;
public:
	StockNode(string, double, double);

	void print();
	string getTicker();
	double getShares();
	double getPrice();

	void setTicker(string);
	void setShares(double);
	void setPrice(double);

private:
	string stockTicker;
	double shares;
	double price;
	StockNode *next;
	StockNode *prev;
}; // end class StockNode

/* class functions */
StockNode::StockNode(string ticker, double num, double unitPrice)
	:stockTicker(ticker), shares(num), price(unitPrice)
{
	this->next = NULL;
	this->prev = NULL;
}

void StockNode::print()
{
	cout << stockTicker << " " << shares << endl;
}

string StockNode::getTicker()
{
	return stockTicker;
}

double StockNode::getShares()
{
	return shares;
}

double StockNode::getPrice()
{
	return price;
}

void StockNode::setTicker(string ticker)
{
	stockTicker = ticker;
}

void StockNode::setShares(double num)
{
	shares = num;
}

void StockNode::setPrice(double unitPrice)
{
	price = unitPrice;
}

#endif