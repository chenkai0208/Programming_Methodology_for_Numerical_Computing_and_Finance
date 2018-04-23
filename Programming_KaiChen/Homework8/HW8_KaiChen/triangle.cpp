// Triangle class mumber-function definitions

#include <iostream>
#include <cmath>

using namespace std;

#include "triangle.h"

Triangle::Triangle(int xValue, int yValue, double edgeValue)
	: Point(xValue, yValue) // call base-class constructor
{
	setEdge(edgeValue);
} // end constructor

void Triangle::setEdge(double edgeValue)
{
	edge = (edgeValue < 0.0 ? 0.0 : edgeValue);
}

double Triangle::getEdge() const
{
	return edge;
}

double Triangle::getCircumference() const
{
	return 3.0 * getEdge();
}

double Triangle::getArea() const
{
	return 0.5 * getEdge() * getEdge() * sin(45);
}


string Triangle::getName() const
{
	return "Triangle";
}

/* output the information of a Triangle object */
void Triangle::print() const
{
	cout << "Center = ";
	Point::print();
	cout << "; Edge = " << getEdge() <<"; Area = " << getArea();
}