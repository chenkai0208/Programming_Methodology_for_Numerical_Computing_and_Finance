//============================================================================
// Name        : Main_KaiChen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 11/20/2017
// Description : LinkedList
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "node.h"
#include "linkedlist.h"

//#include "node.cpp"
//#include "linkedlist.cpp"
LinkedList myList;
int main()
{
	// static LinkedList myList;
	int no;
	string name;
	/* Menu */
	cout << "\n Welcome to the Shopping List Program";
	cout << "\n 	Choice 1: Add a new node at the beginning";
	cout << "\n 	Choice 2: Add a new node at the end";
	cout << "\n 	Choice 3: Remove the beginning node";
	cout << "\n 	Choice 4: Remove the end node";
	cout << "\n 	Choice 5: Remove a node from the list by entering an item number";
	cout << "\n 	Choice 6: Remove a node from the list by entering an item name";
	cout << "\n 	Choice 7: Print out the list";
	cout << "\n 	Choice 8: Quit the program";
	cout << "\n Please enter your choice: " << endl;

	int choice = 0;
	cin >> choice;

	if (choice == 8) // The program terminates only when user types in 8
	{
		return 0;
	}

	switch(choice)
	{

		{case 1: // Add a new node at the beginning
		int no1;
		string name1;
		cout << "Please enter product number to insert at beginning" << endl;
		cin >> no1;
		cout << "Please enter the name for the producti" << endl;
		cin >> name1;
		Node newItem1(name1, no1);
		myList.addToStart(&newItem1);
		break;}


		{case 2: // Add a new node at the end
		int no2;
		string name2;
		cout << "Please enter product number to insert at end" << endl;
		cin >> no2;
		cout << "Please enter the name for the product" << endl;
		cin >> name2;
		Node newItem2(name2, no2);
		myList.addToEnd(&newItem2);
		break;}

		{case 3: // Remove the beginning node
		myList.removeFromStart();
		break;}

		{case 4: // Remove the end node
		myList.removeFromEnd();
		break;}

		{case 5: // Remove a node from the list by entering an item number
		cout << "Please enter the product number to remove" << endl;
		cin >> no;
		myList.removeNodeFromList(no);
		break;}

		{case 6: // Remove a node from the list by entering an item name
		cout << "Please enter the product name to remove" << endl;
		cin >> name;
		myList.removeNodeFromList(name);
		break;}

		{case 7: // Print out the list
		myList.printList();
		break;}

		{default:
		cout << "The program should never be here!" << endl;
		break;}
	}
	/* Print the list after each operation */
	cout << "**********************" << endl;
	cout << "Item No      Item Name" << endl;
	myList.printList();
	cout << "**********************" << endl;

	return main();
}