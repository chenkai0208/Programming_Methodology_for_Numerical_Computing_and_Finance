//============================================================================
// Name        : HW1_Kai Chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 9/15/2017
// Description : First Assignment for Programming Methodology for Finance
//============================================================================

#include <iostream>
using namespace std;

// function main begins program execution
int main() {
	int a[5];
	int i, j, m;
	cout << "Please enter five numbers: \n" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << "Number " << i + 1 << " = " << endl;
		cin >> a[i];
	}

	// use bubble sort algorithm
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < (5-i); j++)
		{
			if (a[j] > a[j+1])
			{
				m = a[j];
				a[j] = a[j+1];
				a[j+1] = m;
			}
		}
	}

	// print out the results
	cout << "The maximum number is: " << a[5] << endl;
	cout << "The minimum number is: " << a[0] << endl;

	return 0; // indicate that program ended successfully
}
