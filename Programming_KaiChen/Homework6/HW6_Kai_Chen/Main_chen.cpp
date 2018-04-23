//============================================================================
// Name        : Main_chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 10/22/2017
// Description : Book List Program (using classes)
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "Booklist_chen.h"
#include "Booklist_chen.cpp"

Booklist_chen book_list;
bool sorted = 0; // shows whether the list has been sorted or not

int main()
{
	/* Menu */
	cout << "\n Welcome to the Book List Program";
	cout << "\n 	Choice 1: Add an element to the end of the list";
	cout << "\n 	Choice 2: Add an element at a certain location";
	cout << "\n 	Choice 3: Find an element by ISBN number (linear search)";
	cout << "\n 	Choice 4: Find an element by ISBN number (binary search)";
	cout << "\n 	Choice 5: Delete an element from a certain position";
	cout << "\n 	Choice 6: Delete an element by ISBN number";
	cout << "\n 	Choice 7: Sort the list (using selection sort)";
	cout << "\n 	Choice 8: Sort the list (using bubble sort)";
	cout << "\n 	Choice 9: Print the list";
	cout << "\n 	Choice 0: exit";
	cout << "\n Please enter your choice: " << endl;
	int choice = 0;
	
	cin >> choice;

	if (choice == 0) // The program terminates only when user types in 0
	{
		return 0;
	}
	int new_element;
	int at_position;
	switch (choice)
	{
		case 1: // Add an element to the end of the list
		cout << "Please enter the element: " << endl;
		cin >> new_element;
		book_list.insert (new_element);
		sorted = 0;
		break;

		case 2: // Add an element at a certain location
		cout << "Please enter the element: " << endl;
		cin >> new_element;
		cout << "Please enter the position you want to add in: " << endl;
		cin >> at_position;
		book_list.insert_at (new_element, at_position);
		sorted = 0;
		break;

		case 3: // Find an element using linear search
		cout << "Please enter the ISBN of the book that you want to search: " << endl;
		cin >> new_element;
		book_list.find_linear (new_element);
		break;

		case 4: // Find an element by ISBN number (binary search) Need to be sorted first!!!
		if (sorted == 0)
			cout << "The list is not sorted. Please sort it first!!!" << endl;
		else
		{
			cout << "Please enter the ISBN of the book that you want to search: " << endl;
			cin >> new_element;
			book_list.find_binary (new_element);
		}
		break;

		case 5: // Delete an element from a certain position
		cout << "Please enter the position of the book that you want to delete from the list: " << endl;
		cin >> at_position;
		book_list.delete_item_position (at_position);
		break;

		case 6: // Delete an element by ISBN number
		cout << "Please enter the ISBN of the book that you want to delete: " << endl;
		cin >> new_element;
		book_list.delete_item_isbn (new_element);
		break;

		case 7: // Sort the list (using selection sort)
		book_list.sort_list_selection ();
		sorted = 1; // indicate that the list has been sorted
		break;

		case 8: // Sort the list (using bubble sort)
		book_list.sort_list_bubble ();
		sorted = 1; // indicate that the list has been sorted
		break;

		case 9: // Print the list
		cout << "Number of books on the list: " << book_list.findEnd() << endl;
		book_list.printArray();
		break;

		default:
		cout << "The program should never be here!" << endl;
		break;
	}

	/* Print out the current list after each operation */
	cout << "***************************" << endl <<
			"Current number of books: " << book_list.findEnd() << endl << "Now your list is: " << endl;
	book_list.printArray();
	cout << "***************************" << endl;

	return main();
}