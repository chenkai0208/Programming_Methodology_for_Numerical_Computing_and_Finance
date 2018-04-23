// Declaration of class Booklist_chen.
// Member functions are defined in Booklist_chen.cpp

// prevent multiple inclusions of header file
#ifndef BOOKLIST_CHEN_H
#define BOOKLIST_CHEN_H

// Booklist_chen data type definition
class Booklist_chen {

public:
	Booklist_chen ();                   // constructor
	void printArray ();
	int findEnd ();
	void insert (int);                  // Add an element to the end of the list
	void insert_at (int, int);          // Add an element at a certain location
	void find_linear (int);             // Find an element by ISBN number (linear search)
	void find_binary (int);             // Find an element by ISBN number (binary search)
	void delete_item_position (int);    // Delete an element from a certain position
	void delete_item_isbn (int);        // Delete an element by ISBN number
	void sort_list_selection ();        // Sort the list (using selection sort)
	void swap (int, int);               // Swap the value of two variables
	void sort_list_bubble ();           // Sort the list (using bubble sort)

private:
	int myList[20];
	int num_in_list;
	int new_element;
	int position;
	int listEnd;

}; // end class Booklist_chen

#endif