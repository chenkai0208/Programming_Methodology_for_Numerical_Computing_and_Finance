// Circle class mumber-function definitions

#include <iostream>

using namespace std;

#include "sphere.h"

Sphere::Sphere(int xValue, int yValue, int zValue, double radiusValue)
	: Point3(xValue, yValue, zValue) // call base-class constructor
{
	setRadius(radiusValue);
} // end constructor

/* set and get functions */
void Sphere::setRadius(double radiusValue)
{
	radius = (radiusValue < 0.0 ? 0.0 : radiusValue);
}

double Sphere::getRadius() const
{
	return radius;
}

double Sphere::getArea() const
{
	return 4.0 * 3.14159 * getRadius() * getRadius();
}

double Sphere::getVolume() const
{
	return (4.0 / 3.0) * 3.14159 * getRadius() * getRadius() * getRadius();
}

string Sphere::getName() const
{
	return "Sphere";
}

/* output the information of a Sphere object */
void Sphere::print() const
{
	cout << "Center = ";
	Point3::print();
	cout << "; Radius = " << getRadius();
	cout << "; Surface Area = " << getArea();
	cout << "; Volume = " << getVolume();
}