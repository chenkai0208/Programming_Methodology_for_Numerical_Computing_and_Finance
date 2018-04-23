// class StockAccount
// Author: Kai Chen
#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H

class StockAccount : public Account
{
public:
	StockAccount();                          // constructor
 
	void push(StockNode *);                  // add one node at the beginning of the list
	StockNode *findTail();                   // find the last node in the list
	void sortList();
	void swapNode(StockNode *, StockNode *); // swap the data in two nodes
	void print();                            // print the infromation for stock account

	StockNode *findStock(string);                  // find the stock node with specific symbol
	void deleteNode(StockNode *);             // delete the node from stock account

	double stockValue();                      // calculate the total value of portfolio

	void saveStockAccount();                  // save current stock account in a txt file
private:
	StockNode *myHead;
	StockNode *myTail;

}; // end of class definition

#endif