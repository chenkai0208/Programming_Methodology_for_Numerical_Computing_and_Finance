// member functions for LinkedList class

#include <iostream>

using namespace std;

#include "linkedlist.h"

LinkedList::LinkedList()
	: myHead(0), myTail(0), mySize(0)
	{

	}

void LinkedList::addToStart(Node *newItem)
{
	Node *newPtr = newItem;
	newPtr->next = myHead;
	myHead = newPtr;
	mySize++;
	myTail = myHead + mySize;
	myTail->next = NULL;
}

void LinkedList::addToEnd(Node *newItem)
{
	Node *newPtr = newItem;
	myTail->next = newPtr;
	myTail = newPtr;
	mySize++;
	myTail = myHead + mySize;
	myTail->next = NULL;
}

void LinkedList::printList()
{
	Node *currentPtr = myHead;
	while(currentPtr != 0)
	{
		cout << currentPtr->itemNo << "          " << currentPtr->itemName << endl;
		currentPtr = currentPtr->next;
	}
}

bool LinkedList::removeFromStart()
{
	if(mySize == 0)
		return false;
	else
	{
		Node *tempPtr = myHead;
		myHead = myHead->next;
		mySize--;
		return true;
	}
}

bool LinkedList::removeFromEnd()
{
	if(mySize == 0)
		return false;
	else
	{
		mySize--;
		myTail = myHead + mySize;
		myTail->next = NULL;
		return true;
	}
}

void LinkedList::removeNodeFromList(int no)
{
	bool test = 0;    // set test=1 when finding the node
	// first check the head and tail of the list
	if(myHead->itemNo == no)
	{
		LinkedList::removeFromStart();
		test = 1;
	}
	if(myTail->itemNo == no)
	{
		LinkedList::removeFromEnd();
		test = 1;
	}
	// then check the rest of the nodes
	Node *currentPtr = myHead;
	
	while(currentPtr != myTail)
	{
		if(currentPtr->next->itemNo == no)
		{
			currentPtr->next = currentPtr->next->next;
			test = 1;
		}
		currentPtr = currentPtr->next;
	}

	if(test == 0)
		cout << "Item Not Found" << endl;
	else
		mySize--;
}

void LinkedList::removeNodeFromList(string name)
{
	bool test = 0;    // set test=1 when finding the node
	// first check the head and tail of the list
	if(myHead->itemName == name)
	{
		LinkedList::removeFromStart();
		test = 1;
	}
	
	if(myTail->itemName == name)
	{
		LinkedList::removeFromEnd();
		test = 1;
	}
	
	// then check the rest of the nodes
	Node *currentPtr = myHead;

	while(currentPtr != myTail)
	{
		if(currentPtr->next->itemName == name)
		{
			currentPtr->next = currentPtr->next->next;
			test = 1;
		}
		currentPtr = currentPtr->next;
	}
	if(test == 0)
		cout << "Item Not Found" << endl;
	else
		mySize--;
}
