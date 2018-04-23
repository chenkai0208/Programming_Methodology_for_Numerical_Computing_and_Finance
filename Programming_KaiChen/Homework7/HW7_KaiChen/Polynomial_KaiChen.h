// Declaration of class Polynomial_KaiChen.
// Member functions are defined in Polynomial_KaiChen.cpp

// prevent multiple inclusions of header file
#ifndef POLYNOMIAL_KAICHEN_H
#define POLYNOMIAL_KAICHEN_H

// Booklist_chen data type definition
class Polynomial_KaiChen {
	friend ostream &operator<<(ostream &, Polynomial_KaiChen &);
public:
	Polynomial_KaiChen ();                   // constructor
	void setPolynomial(float, int);
	float *getPolynomial();
	int findMaxExpo();
	void printPolynomial();

	Polynomial_KaiChen & operator+=(const Polynomial_KaiChen & poly2);
	Polynomial_KaiChen & operator-=(const Polynomial_KaiChen & poly2);
	Polynomial_KaiChen & operator*=(const Polynomial_KaiChen & poly2);




private:
	float term[13];     // coefficient is saved in the array and the index if the exponent
	int maxExpo;
}; // end class Booklist_chen
Polynomial_KaiChen &operator+(Polynomial_KaiChen &poly1, Polynomial_KaiChen &poly2);
Polynomial_KaiChen &operator-(Polynomial_KaiChen &poly1, Polynomial_KaiChen &poly2);
Polynomial_KaiChen &operator*(Polynomial_KaiChen &poly1, Polynomial_KaiChen &poly2);
#endif