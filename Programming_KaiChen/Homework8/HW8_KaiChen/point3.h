// Point class definition represents an x-y-z coordinate pair
#ifndef POINT3_H
#define POINT3_H

#include "ThreeDimensionalShape.h"

class Point3 : public ThreeDimensionalShape
{
public:
	Point3(int = 0, int = 0, int = 0); // default constructor

	void setX(int);          // set x in coordinate pair
	int getX() const;        // return x from coordinate pair

	void setY(int);          // set Y
	int getY() const;              // return Y

	void setZ(int);          // set z in coordinate pair
	int getZ() const;        // return z from coordinate pair

	virtual string getName() const;
	virtual void print() const;      // output Point object

private:
	int x;
	int y;
	int z;
};

#endif