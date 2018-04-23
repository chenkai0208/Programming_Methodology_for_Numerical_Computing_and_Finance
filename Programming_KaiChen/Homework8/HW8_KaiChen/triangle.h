// Triangle class contains x-y and edge

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle : public Point
{
public:
	Triangle(int = 0, int = 0, double = 0.0);

	void setEdge(double);
	double getEdge() const;

	virtual double getArea() const;
	double getCircumference() const;

	virtual string getName() const;
	virtual void print() const;

private:
	double edge;
}; // end class Triangle

#endif