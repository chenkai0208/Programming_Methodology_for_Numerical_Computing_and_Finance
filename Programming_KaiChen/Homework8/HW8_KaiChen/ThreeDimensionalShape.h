// ThreeDimensionalShape class definition
#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include <string>

#include "shape.h"

using std::string;

class ThreeDimensionalShape : public Shape
{
public:
	virtual double getArea() const = 0;
	virtual double getVolume() const = 0;

	virtual void print() const = 0;
};

#endif