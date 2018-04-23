// Member function definitions for class Booklist_chen
#include <iostream>
#include <iomanip>

#include "Booklist_chen.h"

using namespace std;

Booklist_chen::Booklist_chen()
{
	position = num_in_list = 0;
	for (int i = 0; i < 20; i++)
		myList[i] = 0;
} // end Booklist_chen constructor

/* Find the end of the list. Return the index of last element */
int Booklist_chen::findEnd ()
{
	for (int i = 0; i < 20; i++)
	{
		if (myList[i] == 0)
		{
			return i;
		}
	}
	return 20;   // if the list is full, return 19 as the end position
} // end function findEnd

/* Print the list on the screen. */
void Booklist_chen::printArray ()
{
	if (myList[19] != 0)
	{
		for (int i = 0; i < 20; i++)
			cout << i+1 << ". " << myList[i] << endl;
	}
	else
	{
		listEnd = Booklist_chen::findEnd();
		for (int i = 0; i < listEnd; i++)
			cout << i+1 << ". " << myList[i] << endl;
	}
}

/* Add an element to the end of the list */
void Booklist_chen::insert (int element)
{
	listEnd = Booklist_chen::findEnd();
	if (myList[19] != 0) // full
		cout << "The list is full!" << endl;
	else
		myList[listEnd] = element;
	/* if the new element is the same as an existing one, delete the old one */
	for (int i = 0; i < listEnd; i++)
	{
		if (myList[i] == myList[listEnd])
			Booklist_chen::delete_item_position (i+1);
	}
}


/* Add an element to the end of the list */
void Booklist_chen::insert_at (int element, int at_position)
{
	listEnd = Booklist_chen::findEnd();

	/* if the new element is the same as an existing one, delete the old one */
	for (int i = 0; i < listEnd; i++)
	{
		if (myList[i] == element)
			Booklist_chen::delete_item_position (i+1);
	}

	if (myList[19] != 0)
		cout << "The list if full!" << endl;
	else if (myList[at_position-1-1] == 0)
		myList[listEnd] = element;
	else
	{
	for (int i = 18; i >= at_position-1; i--)
		{myList[i+1] = myList[i];}
	myList[at_position-1] = element;
	}
}

/* Find an element using linear search. */
void Booklist_chen::find_linear (int element)
{
	bool test = 0; // indicate whether the book is found
	listEnd = Booklist_chen::findEnd();
	for (int i = 0; i < listEnd; i++)
		if (myList[i] == element)
			{cout << "The book that you are searching for is number: " << i+1 << endl;
			test = 1;}
	if (test != 1)
		cout << "The book is not on the list!" << endl;
}


/* Find an element by ISBN number (binary search) */
void Booklist_chen::find_binary (int element)
{
	bool test = 0; // shows whether find the element or not
	num_in_list = Booklist_chen::findEnd ();
	int middle, low = 0, high = num_in_list-1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (element == myList[middle]) //match
			{cout << "Find the book at position: " << middle+1 << endl;
			test = 1;
			break;}
		else if (element < myList[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	if (test != 1)
		cout << "The book is not on the list!" << endl; // element not found
}

/* Delete an element that is at a certain position */
void Booklist_chen::delete_item_position (int at_position)
{
	listEnd = Booklist_chen::findEnd();
	if (at_position > listEnd || at_position < 1)
		cout << "Out of boundary!" << endl;
	else
	{
		for (int i = at_position; i < listEnd; i++)
			myList[i-1] = myList[i];
		myList[listEnd-1] = 0;
	}
}

/* Delete an element by its isbn number */
void Booklist_chen::delete_item_isbn (int element)
{
	bool test = 0;
	if (myList[0] == 0)
		cout << "There is no element to delete!" << endl;
	else
	{
		listEnd = Booklist_chen::findEnd();
		for (int i = 0; i < listEnd; i++)
			if (myList[i] == element)
				{Booklist_chen::delete_item_position (i+1);
				test = 1;}
	}
	if (test != 1)
		cout << "This book is not on the list!" << endl;
}

/* Sort the list (using selection sort) */
void Booklist_chen::sort_list_selection ()
{
	if (myList[0] == 0)
		cout << "There is no element on the list!" << endl;
	else
	{
		num_in_list = Booklist_chen::findEnd ();
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
			Booklist_chen::swap (sm_index, i);
		}
	}
}

void Booklist_chen::swap (int smaller, int pass)
{
	int temp;
	temp = myList[pass];
	myList[pass] = myList[smaller];
	myList[smaller] = temp;
}

/* Sort the list by the ISBN numbers (using bubble sort) */
void Booklist_chen::sort_list_bubble ()
{
	if (myList[0] == 0)
		cout << "There is no element on the list!" << endl;
	else
	{
		num_in_list = Booklist_chen::findEnd ();
		int *myPointer;
		myPointer = &myList[0];
		for (int i = 0; i < num_in_list-1; i++)
			for (int j = 0; j < num_in_list-1-i; j++)
				if (*(myPointer+j) > *(myPointer+j+1))
					Booklist_chen::swap (j, j+1);
	}
}


