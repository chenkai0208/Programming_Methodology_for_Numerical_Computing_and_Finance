// base class Package

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;

class Package
{
public:
	Package(string, string, string, string, string, string, string, string, string, string, double, double); // default constructor

	virtual double getWeight();
	virtual double getUnitCost();

	virtual string getSenderName();
	virtual string getSenderAddress();
	virtual string getSenderCity();
	virtual string getSenderState();
	virtual string getSenderZipcode();

	virtual string getRecipientName();
	virtual string getRecipientAddress();
	virtual string getRecipientCity();
	virtual string getRecipientState();
	virtual string getRecipientZipcode();

	virtual double calculateCost();  // determine the cost by multiplying the weight by the cost per ounce
	virtual void print();            // print the package information

private:
	string senderName;
	string senderAddress;
	string senderCity;
	string senderState;
	string senderZipcode;

	string recipientName;
	string recipientAddress;
	string recipientCity;
	string recipientState;
	string recipientZipcode;

	double weight;            // should be positive value
	double unitCost;          // should be positive value
};

#endif