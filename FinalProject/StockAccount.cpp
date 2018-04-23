// member functions for StockAccount class
// Author: Kai Chen

#include <iostream>
#include <string>

using namespace std;

#include "StockNode.h"
#include "StockAccount.h"

StockAccount::StockAccount()  // constructor
	: myHead(0), myTail(0)
{

}

/* add a new node at the beginning of the doubly linked list */
void StockAccount::push(StockNode *newItem)
{
	StockNode *newNode = newItem;
	newNode->prev = NULL;
	newNode->next = myHead;
	if (myHead != NULL)
		myHead->prev = newNode;
	myHead = newNode;
}

/* print out current stock positions */
void StockAccount::print()
{
	StockNode *currentPtr;
	currentPtr = myHead;
	cout << "Company-Symbol     Number     Price-per-share     Total value" << endl;
	while(currentPtr != 0)
	{
		cout << currentPtr->stockTicker << "   " << currentPtr->shares << "   " << currentPtr->price << "   " << currentPtr->shares * currentPtr->price << endl;
		currentPtr = currentPtr->next;
	}
}

/* find myTail in the doubly linked list */
StockNode *StockAccount::findTail()
{
	StockNode *root = myHead;
	while (root && root->next)
		root = root->next;
	return root;
}

/* swap the information of two nodes */
void StockAccount::swapNode(StockNode *n1, StockNode *n2)
{
	string tempTicker;
	double tempShares;
	double tempPrice;
	tempTicker = n1->getTicker();
	tempShares = n1->getShares();
	tempPrice = n1->getPrice();
	n1->setTicker(n2->getTicker());
	n1->setShares(n2->getShares());
	n1->setPrice(n2->getPrice());
	n2->setTicker(tempTicker);
	n2->setShares(tempShares);
	n2->setPrice(tempPrice);
}

/* sort the doubly linked list */
void StockAccount::sortList()
{
	StockNode *i = myHead;
	myTail = StockAccount::findTail();
	while (i != myTail)
	{
		StockNode *j = myHead;
		StockNode *end = myTail;
		while (j != end)
		{
			if ((j->getShares() * j->price) < ((j->next->getShares()) * j->next->price))
				StockAccount::swapNode(j, j->next);
			j = j->next;
		}
		end = end->prev;
		i = i->next;
	}
}

/* find the stock's node in current stock account */
StockNode *StockAccount::findStock(string symbol)
{
	StockNode *currentPtr = myHead;
	while(currentPtr != 0)
	{
		if (currentPtr->getTicker() == symbol)
		{
			return currentPtr;
		}
		currentPtr = currentPtr->next;
	}
	return NULL;
}

/* delete one node from the doubly linked list */
void StockAccount::deleteNode(StockNode *myPosition)
{
	// if the node is head
	if (myHead == myPosition)
		myHead = myPosition->next;
	// change the next and prev
	if (myPosition->next != NULL)
		myPosition->next->prev = myPosition->prev;

	if (myPosition->prev != NULL)
		myPosition->prev->next = myPosition->next;
}

/* get the total value of stocks */
double StockAccount::stockValue()
{
	value = 0;
	StockNode *currentPtr;
	currentPtr = myHead;
	while(currentPtr != 0)
	{
		value += currentPtr->shares * currentPtr->price;
		currentPtr = currentPtr->next;
	}
	return value;
}

/* save current stock account information into a txt file */
void StockAccount::saveStockAccount()
{
	ofstream file;
	file.open("/Users/chenkai/Desktop/Rutgers_University/study/Programming_Methodology_for_Finance/FinalProject/stock_account.txt", ios::trunc);
	StockNode *currentPtr;
	currentPtr = myHead;
	while(currentPtr != 0)
	{
		file << currentPtr->stockTicker << "\t" << currentPtr->shares << "\t" << currentPtr->price << endl;
		currentPtr = currentPtr->next;
	}
}



