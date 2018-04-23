// class LinkedList

#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
public:
	LinkedList();
	void addToStart(Node *);
	void addToEnd(Node *);
	void printList();
	bool removeFromStart();
	bool removeFromEnd();
	void removeNodeFromList(int);
	void removeNodeFromList(string);

private:
	Node *myHead;
	Node *myTail;
	int mySize;
}; // end of class definition

#endif