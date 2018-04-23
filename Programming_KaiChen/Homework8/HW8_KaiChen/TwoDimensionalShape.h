// TwoDimensionalShape class definition
#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H

#include <string>

#include "shape.h"

using std::string;

class TwoDimensionalShape : public Shape
{
public:
	virtual double getArea() const = 0;

	virtual void print() const = 0;
};

#endif