// class Node

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
	friend class LinkedList;
public:
	Node(string, int);
	void print();
private:
	string itemName;
	int itemNo;
	Node *next;
}; // end of class definition

#endif