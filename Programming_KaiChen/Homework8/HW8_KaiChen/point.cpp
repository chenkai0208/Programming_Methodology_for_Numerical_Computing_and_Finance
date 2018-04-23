// Point class member-function definitions
#include <iostream>

using namespace std;

#include "point.h"   // Point class definition

/* Constructior */
Point::Point(int xValue, int yValue)
	: x(xValue), y(yValue)
{

}  // end Point constructor

/* set function and get function */
void Point::setX(int xValue)
{
	x = xValue;
}

int Point::getX() const
{
	return x;
}

void Point::setY(int yValue)
{
	y = yValue;
}

int Point::getY() const
{
	return y;
}

string Point::getName() const
{
	return "Point in two dimentional";
}


/* output */
void Point::print() const
{
	cout << "[" << x << ", " << y << "]";
}