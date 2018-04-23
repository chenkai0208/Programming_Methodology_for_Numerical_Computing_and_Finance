// Tetrahedron class mumber-function definitions

#include <iostream>
#include <cmath>

using namespace std;

#include "tetrahedron.h"

Tetrahedron::Tetrahedron(int xValue, int yValue, int zValue, double edgeValue)
	: Point3(xValue, yValue, zValue) // call base-class constructor
{
	setEdge(edgeValue);
} // end constructor

/* set and get functions */
void Tetrahedron::setEdge(double edgeValue)
{
	edge = (edgeValue < 0.0 ? 0.0 : edgeValue);
}

double Tetrahedron::getEdge() const
{
	return edge;
}

double Tetrahedron::getArea() const
{
	return sqrt(3.0) * getEdge() * getEdge();
}

double Tetrahedron::getVolume() const
{
	return getEdge() * getEdge() * getEdge() / 6.0 / sqrt(2.0);
}

string Tetrahedron::getName() const
{
	return "Tetrahedron";
}

/* output the information of a Tetrahedron object */
void Tetrahedron::print() const
{
	cout << "Center = ";
	Point3::print();
	cout << "; Edge = " << getEdge();
	cout << "; Surface Area = " << getArea();
	cout << "; Volume = " << getVolume();
}