//===========================================================================================
// Name        : HW5-1_Kai_Chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 10/14/2017
// Description : First program in HW5: recursive function practice
//               print the squares of the odd integers in descending order first 
//               and then following with the squares of the even integers in ascending order
//===========================================================================================

#include <iostream>
using namespace std;

int oddEvenPrint (int n, int odd, int even);

int main()
{
	int n, p;
	cout << "Please enter the parameter n = " << endl;
	cin >> n;

	p = oddEvenPrint (n, n, 2);

	return 0;
}

int oddEvenPrint (int n, int odd, int even)
{
	while (even > n || odd < 0)
		{return 1;}
	int test = odd % 2;
	while (odd != 0)
	{
		if (test == 1)
		{
			cout << odd * odd << ", ";
			odd--;
			return oddEvenPrint (n, odd, even);
		}
		else 
		{
			odd--;
			return oddEvenPrint (n, odd, even);
		}
	}
	while (even <= n - 2)
	{
		cout << even * even << ", ";
		even += 2;
		return oddEvenPrint (n, 0, even);
	}

	cout << even * even << endl;
	return 1;
}
