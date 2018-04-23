// Shape class definition
#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using std::string;

class Shape
{
public:
	virtual string getName() const = 0;
};

#endif