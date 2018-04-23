// Point class definition represents an x-y coordinate pair
#ifndef POINT_H
#define POINT_H

#include "TwoDimensionalShape.h"

class Point : public TwoDimensionalShape
{
public:
	Point(int = 0, int = 0); // default constructor

	void setX(int);          // set x in coordinate pair
	int getX() const;        // return x from coordinate pair

	void setY(int);          // set Y
	int getY() const;              // return Y

	virtual string getName() const;
	virtual void print() const;      // output Point object

private:
	int x;
	int y;
};

#endif