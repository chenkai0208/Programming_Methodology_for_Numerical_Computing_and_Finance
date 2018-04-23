// class OvernightPackage

#include "package.h"

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

class OvernightPackage : public Package
{
public:
	OvernightPackage(string, string, string, string, string, string, string, string, string, string, double, double, double);  // constructor
	virtual double calculateCost();  // determine the cost for overnight shipping
	virtual void print();            // print the overnight shipping package information

	virtual void setOvernightFee(double);
	virtual double getOvernightFee();


private:
	double overnightFee;
};

#endif