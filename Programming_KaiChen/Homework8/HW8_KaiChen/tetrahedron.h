// Tetrahedron class contains x-y-z and edge

#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "point3.h"

class Tetrahedron : public Point3
{
public:
	Tetrahedron(int = 0, int = 0, int = 0, double = 0.0);

	void setEdge(double);
	double getEdge() const;

	virtual double getArea() const;
	virtual double getVolume() const;

	virtual string getName() const;
	virtual void print() const;

private:
	double edge;
}; // end class Tetrahedron

#endif