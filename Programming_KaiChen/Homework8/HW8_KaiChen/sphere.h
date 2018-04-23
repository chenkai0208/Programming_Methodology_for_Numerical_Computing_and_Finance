// Sphere class contains x-y-z and radius

#ifndef SPHERE_H
#define SPHERE_H

#include "point3.h"

class Sphere : public Point3
{
public:
	Sphere(int = 0, int = 0, int = 0, double = 0.0);

	void setRadius(double);
	double getRadius() const;

	virtual double getArea() const;
	virtual double getVolume() const;

	virtual string getName() const;
	virtual void print() const;

private:
	double radius;
}; // end class Sphere

#endif