//============================================================================
// Name        : Main_chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 10/30/2017
// Description : Polynomial Operations
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "Polynomial_KaiChen.h"
#include "Polynomial_KaiChen.cpp"


int main()
{
	Polynomial_KaiChen poly1;
	Polynomial_KaiChen poly2;
	Polynomial_KaiChen poly3;

	int coef, expo;
	int num_poly1, num_poly2;

	cout << "Please enter the number of polynomial terms for poly1: " << endl;
	cin >> num_poly1;
	for (int i = 0; i < num_poly1; i++)
	{
		cout << "Please enter the coefficient and exponent: " << endl;
		cin >> coef;
		cin >> expo;
		poly1.setPolynomial(coef,expo);
	}

	cout << "Please enter the number of polynomial terms for poly2: " << endl;
	cin >> num_poly2;
	for (int i = 0; i < num_poly2; i++)
	{
		cout << "Please enter the coefficient and exponent: " << endl;
		cin >> coef;
		cin >> expo;
		poly2.setPolynomial(coef,expo);
	}

	cout << "First polynomial is: " << poly1 << endl;
	cout << "Second polynomial is: " << poly2 << endl;

	poly3 = poly1 + poly2;
	cout << "Adding yields: " << poly3 << endl;
	poly3 = poly1;
	cout << "+= yields: " << (poly3 += poly2) << endl;

	poly3 = poly1 - poly2;
	cout << "Substracting yields: " << poly3 << endl;
	poly3 = poly1;
	cout << "-= yields: " << (poly3 -= poly2) << endl;

	poly3 = poly1 * poly2;
	cout << "Multiplying yields: " << poly3 << endl;
	poly3 = poly1;
	cout << "*= yields: " << (poly3 *= poly2) << endl;


	return 0;
}