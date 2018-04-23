// Member function definitions for class Polynomial_KaiChen
#include <iostream>
#include <iomanip>

#include "Polynomial_KaiChen.h"

using namespace std;

Polynomial_KaiChen::Polynomial_KaiChen()
{
	for (int i = 0; i < 13; i++)
		term[i] = 0;
} // end Polynomial_KaiChen constructor

/* This program only used array. Do not need to write a special destruction function. */

void Polynomial_KaiChen::setPolynomial(float coef, int expo)
{
	term[expo] = coef;
} // end function setPolynomial

float *Polynomial_KaiChen::getPolynomial()
{
	return &term[0];
}

int Polynomial_KaiChen::findMaxExpo()
{
	for (int i = 12; i >= 0; i--)
		if (term[i] != 0)
			return i;
	return 0;
}

void Polynomial_KaiChen::printPolynomial()
{
	maxExpo = Polynomial_KaiChen::findMaxExpo();
	if (term[0] != 0)
		cout << term[0] << " + ";
	for (int i = 1; i < maxExpo; i++)
	{
		if (term[i] != 0)
			cout << term[i] << "x^" << i << " + ";
	}
	cout << term[maxExpo] << "x^" << maxExpo << endl;
}

ostream &operator<<(ostream &output, Polynomial_KaiChen &poly)
{
	poly.printPolynomial();
	return output;
}


/* Overload assignment += */
Polynomial_KaiChen & Polynomial_KaiChen::operator+=(const Polynomial_KaiChen & poly2) 
{
	for (int i = 0; i < 13; i++)
		term[i] += poly2.term[i];
    return *this;
}

/* Overload assignment -= */
Polynomial_KaiChen & Polynomial_KaiChen::operator-=(const Polynomial_KaiChen & poly2) 
{
	for (int i = 0; i < 13; i++)
		term[i] -= poly2.term[i];
    return *this;
}

/* Overload assignment *= */
Polynomial_KaiChen & Polynomial_KaiChen::operator*=(const Polynomial_KaiChen & poly2) {
	Polynomial_KaiChen poly3;
    for (int i = 0; i < 13; i++) 
    {
        if (poly2.term[i] != 0)
        	for (int j = 0; j < 13; j++)
        		if (term[j] != 0)
        			poly3.term[i+j] = poly2.term[i] * term[j];

    }
    for (int k = 0; k < 13; k++)
    	term[k] = poly3.term[k];
    return *this;
}

/* Overload + */
Polynomial_KaiChen &operator+(Polynomial_KaiChen &poly1, Polynomial_KaiChen &poly2)
{
	Polynomial_KaiChen poly3;
	poly3 = poly1;
	poly3 += poly2;
	return poly3;
}

/* Overload - */
Polynomial_KaiChen &operator-(Polynomial_KaiChen &poly1, Polynomial_KaiChen &poly2)
{
	Polynomial_KaiChen poly3;
	poly3 = poly1;
	poly3 -= poly2;
	return poly3;
}

/* Overload * */
Polynomial_KaiChen &operator*(Polynomial_KaiChen &poly1, Polynomial_KaiChen &poly2)
{
	Polynomial_KaiChen poly3;
	poly3 = poly1;
	poly3 *= poly2;
	return poly3;
}
