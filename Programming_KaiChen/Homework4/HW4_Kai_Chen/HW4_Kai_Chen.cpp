//============================================================================
// Name        : HW4_Kai_Chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 10/10/2017
// Description : Book List Program
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

/* Function Prototype */

int findEnd (int myList[]);
void printArray (int myList[]);
void insert (int myList[], int num_in_list, int new_element);
void insert_at (int myList[], int at_position, int new_element);
int find_linear (int myList[], int num_in_list, int element);
void delete_item_position (int myList[], int num_in_list, int position);
void sort_list_selection (int myList[], int num_in_list);
void swap (int myList[], int smaller, int pass);
void sort_list_bubble (int myList[], int num_in_list);
int find_binary (int myList[], int num_in_list, int element, bool sorted);

int myList[20] = {0}; // the list for book's ISBN
bool sorted = 0;      // test variable to check whether the list is sorted

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
	
	int listEnd = 0;             // the number of values in myList
	listEnd = findEnd (myList);

	/* Switch into different block in terms of the function that user chooses*/
	switch(choice)
	{
		case 1: // Add an element to the end of the list
		if (myList[19] != 0)
		{
			cout << "The list is full!" << endl;
			printArray (myList);
			break;
		}
		else
		{
			int listEnd = 0;
			listEnd = findEnd (myList);
			int new_element;
			cout << "Please type in the element: " << endl;
			cin >> new_element;
			insert (myList, listEnd, new_element);
			sorted = 0;
			printArray (myList);
			break;
		}

		case 2: // Add an element at a certain location
		if (myList[19] != 0)
		{
			cout << "The list is full!" << endl;
			printArray (myList);
			break;
		}
		else
		{
			int listEnd = 0;
			listEnd = findEnd (myList);
			int new_element;
			cout << "Please type in the element: " << endl;
			cin >> new_element;
			cout << "Please type in the position you want to put in: " << endl;
			int at_position;
			cin >> at_position;
			insert_at (myList, at_position, new_element);
			sorted = 0;
			printArray (myList);
			break;
		}

		case 3: // Find an element using linear search
		int num_in_list;
		num_in_list = findEnd (myList);
		cout << "Please enter the ISBN of the book that you want to search: " << endl;
		int element, position;
		cin >> element;
		position = find_linear (myList, num_in_list, element);
		if (position == -1)
			{cout << "The book is not on the list!" << endl;
			break;}
		else
			{cout << "The book that you are searching for is number: " << position << endl;
			break;}

		case 4: // Find an element by ISBN number (binary search) Need to be sorted first!!!
		num_in_list = findEnd (myList);
		cout << "Please enter the ISBN of the book that you want to search: " << endl;
		cin >> element;
		position = find_binary (myList, num_in_list, element, sorted);
		if (position == -1)
			{cout << "The book is not on the list!" << endl;
			break;}
		else if (position == -2)
			{cout << "The list is not sorted. Please sort it first!" << endl;
			break;}
		else
			{cout << "The book that you are searching for is number: " << position << endl;
			break;}

		case 5: // Delete an element from a certain position
		if (myList[0] == 0)
			{cout << "There is no element to delete!" << endl;
			break;}
		else
		{
		num_in_list = findEnd (myList);
		cout << "Please enter the position of the book that you want to delete from the list: " << endl;
		cin >> position;
		if (position > num_in_list)
			{cout << "There is no element at that position!" << endl;
			break;}
		else
			{
			delete_item_position (myList, num_in_list, position);
			cout << "Now your list is: " << endl;
			printArray (myList);
			break;
			}
		}

		case 6: // Delete an element by ISBN number (This can be done by using "delete_item_position" and "find_linear" functions)
		if (myList[0] == 0)
			{cout << "There is no element to delete!" << endl;
			break;}
		else
		{
		num_in_list = findEnd (myList);
		cout << "Please enter the ISBN of the book that you want to delete from the list: " << endl;
		int isbn;
		cin >> isbn;
		position = find_linear (myList, num_in_list, isbn);
		if (position == -1)
			{cout << "This book is not on the list!" << endl;
			break;}
		else
			{
			delete_item_position (myList, num_in_list, position);
			}
		cout << "Now your list is: " << endl;
		printArray (myList);
		break;
		}

		case 7: // Sort the list (using selection sort) 
		if (myList[0] == 0)
			{cout << "There is no element on the list!" << endl;
			break;}
		else
		{
			num_in_list = findEnd (myList);
			sort_list_selection (myList, num_in_list);
			printArray (myList);
			sorted = 1;
			break;
		}

		case 8: // Sort the list by the ISBN numbers (using bubble sort)
		if (myList[0] == 0)
			{cout << "There is no element on the list!" << endl;
			break;}
		else
		{
			num_in_list = findEnd (myList);
			sort_list_bubble (myList, num_in_list);
			printArray (myList);
			sorted = 1;
			break;
		}

		default:
		cout << "The program should never be here!" << endl;
		break;
	}
	return main();
}

/***************************************/
/* Definition of functions starts here */
/***************************************/

/* Print the list on the screen. */
void printArray (int myList[])
{
	if (myList[19] != 0)
	{
		for (int i = 0; i < 20; i++)
			cout << i+1 << ". " << myList[i] << endl;
	}
	else
	{
		int listEnd;
		listEnd = findEnd (myList);
		for (int i = 0; i < listEnd; i++)
			cout << i+1 << ". " << myList[i] << endl;
	}
}

/* Find the end of the list */
int findEnd (int myList[])
{
	for (int i = 0; i < 20; i++)
	{
		if (myList[i] == 0)
		{
			return i;
		}
	}
	return 19;   // if the list is full, return 19 as the end position
}

/* Add an element to the end of the list */
void insert (int myList[], int num_in_list, int new_element)
{
	myList[num_in_list] = new_element;
}

/* Add an element at a certain position. */
/* If there is no element after that position, just add the element at the end of the list */
void insert_at (int myList[], int at_position, int new_element)
{
	if (myList[at_position-1-1] == 0)
		myList[findEnd(myList)] = new_element;
	else
	{
	for (int i = 18; i >= at_position-1; i--)
		{myList[i+1] = myList[i];}
	myList[at_position-1] = new_element;
	}
}

/* Find an element by ISBN number (binary search) */
int find_binary (int myList[], int num_in_list, int element, bool sorted)
{
	if (sorted == 0)
	{
		return -2;  // need to be sorted first
	}
	else
	{
	int middle, low = 0, high = num_in_list-1;
	while (low <= high)
	{
	middle = (low + high) / 2;

	if (element == myList[middle]) //match
		return middle+1;
	else
		if (element < myList[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1; // element not found
	}
}

/* Find an element using linear search. */
int find_linear (int myList[], int num_in_list, int element)
{
	for (int i = 0; i < num_in_list; i++)
		if (myList[i] == element)
			return i+1;
	return -1;
}

/* Delete an element that is at a certain position */
void delete_item_position (int myList[], int num_in_list, int position)
{
	for (int i = position; i < num_in_list; i++)
		myList[i-1] = myList[i];
	myList[num_in_list-1] = 0;
}

/* Sort the list (using selection sort) */
void sort_list_selection (int myList[], int num_in_list)
{
	int *myPointer;
	myPointer = &myList[0];
	int smallest, sm_index;
	for (int i = 0; i < num_in_list - 1; i++)
	{
		smallest = *(myPointer + i);
		sm_index = i;
			for (int j = i + 1; j < num_in_list; j++)
				if (*(myPointer + j) < smallest)
				{
					smallest = *(myPointer + j);
					sm_index = j;
				}
		swap (myList, sm_index, i);
	}
}

/* Swap the value of two variables */
void swap (int myList[], int smaller, int pass)
{
	int temp;
	temp = myList[pass];
	myList[pass] = myList[smaller];
	myList[smaller] = temp;
}

/* Sort the list by the ISBN numbers (using bubble sort) */
void sort_list_bubble (int myList[], int num_in_list)
{
	int *myPointer;
	myPointer = &myList[0];
	for (int i = 0; i < num_in_list-1; i++)
		for (int j = 0; j < num_in_list-1-i; j++)
			if (*(myPointer+j) > *(myPointer+j+1))
				swap (myList, j, j+1);
}
