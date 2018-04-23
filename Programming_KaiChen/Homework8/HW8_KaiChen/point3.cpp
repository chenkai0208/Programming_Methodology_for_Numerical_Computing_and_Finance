// Point3 class member-function definitions
#include <iostream>

using namespace std;

#include "point3.h"   // Point class definition

/* Constructior */
Point3::Point3(int xValue, int yValue, int zValue)
	: x(xValue), y(yValue), z(zValue)
{

}  // end Point3 constructor

/* set function and get function */
void Point3::setX(int xValue)
{
	x = xValue;
}

int Point3::getX() const
{
	return x;
}

void Point3::setY(int yValue)
{
	y = yValue;
}

int Point3::getY() const
{
	return y;
}

void Point3::setZ(int zValue)
{
	z = zValue;
}

int Point3::getZ() const
{
	return z;
}

string Point3::getName() const
{
	return "Point in three dimentional";
}

/* output */
void Point3::print() const
{
	cout << "[" << x << ", " << y << ", " << z << "]";
}