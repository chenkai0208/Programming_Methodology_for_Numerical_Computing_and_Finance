// class TwoDayPackage

#include "package.h"

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(string, string, string, string, string, string, string, string, string, string, double, double, double);  // constructor
	virtual double calculateCost();  // determine the cost for two day shipping
	virtual void print();            // print the two day shipping package information

	virtual void setFlatFee(double);
	virtual double getFlatFee();


private:
	double flatFee;
};

#endif