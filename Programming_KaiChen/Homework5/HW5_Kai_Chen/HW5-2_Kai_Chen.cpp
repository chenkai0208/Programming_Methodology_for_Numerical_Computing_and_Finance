//===========================================================================================
// Name        : HW5-2_Kai_Chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 10/16/2017
// Description : Second program in HW5: recursive function practice (Puzzle Jump Game)
//===========================================================================================

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int puzzleJump (int puzzle[], int position, int iter);

int n;

int main()
{
	/* Initialize the data */
	int solution;
	cout << "Enter a series of positive integers for this game. The program will add a '0' at the end of your input." << endl;
	cout << "First tell me how many numbers you would like to have?" << endl;
	cin >> n;
	int puzzle[n+1];
	puzzle [n] = 0;
	cout << "Then please enter the numbers: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> puzzle[i];
	}

	cout << "The numbers for this game are: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << puzzle[i] << "  ";
	}
	cout << puzzle[n] << endl;

	cout << "Please enter the start position (1, ..., n): " << endl;
	int position;
	cin >> position;
	cout << "The game will start with number: " << puzzle[position-1] << ", at the position " << position << endl;

	/* Call the recursive function to generate paths */
	int iter = 0;
	for (int i = 0; i < 100; i++)   // generate 100 paths for test
	{
		solution = puzzleJump (puzzle, position, iter);
		if (solution == 1)
		{
			cout << "Find the solution!" << endl;
			return 0;
		}
	}

	cout << "The puzzle cannot be solved..." << endl;

	return 0;

}


int puzzleJump (int puzzle[], int position, int iter)
{
	while (iter != 100) // set up the maximum of iteration as 100 to avoid repeated looping
	{
		if (position + puzzle[position-1] == n + 1)  // find the solution
			return 1;
		else if ((position + puzzle[position-1] > n + 1) && (position - puzzle[position-1] < 1)) // cannot move neither left nor right
			return -1;
		else if ((position + puzzle[position-1] < n + 1) && (position - puzzle[position-1] < 1)) // can only move to the right
		{
			position = position + puzzle[position-1];
			iter++;
			return puzzleJump (puzzle, position, iter);
		}
		else if ((position + puzzle[position-1] > n + 1) && (position - puzzle[position-1] >= 1)) // can only move to the left
		{
			position = position - puzzle[position-1];
			iter++;
			return puzzleJump (puzzle, position, iter);
		}
		else if (rand() % 2 == 0)  // randomly choose to move to the left or right
		{
			position = position - puzzle[position-1];
			iter++;
			return puzzleJump (puzzle, position, iter);
		}
		else
		{
			position = position + puzzle[position-1];
			iter++;
			return puzzleJump (puzzle, position, iter);
		}
	}
	return -1;
}
