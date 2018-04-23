// Package class member functions

#include <iostream>
#include <iomanip>

using namespace std;

#include "package.h"

Package::Package(string senderName, string senderAddress, string senderCity, string senderState, string senderZipcode, 
	             string recipientName, string recipientAddress, string recipientCity, string recipientState, string recipientZipcode,
	             double weightValue, double unitCostValue)
			: senderName(senderName), senderAddress(senderAddress),senderCity(senderCity) ,senderState(senderState), senderZipcode(senderZipcode),
			  recipientName(recipientName), recipientAddress(recipientAddress), recipientCity(recipientCity), recipientState(recipientState), recipientZipcode(recipientZipcode), 
			  weight(weightValue), unitCost(unitCostValue)
{

} // end Package constructor

/* get weight and cost */
double Package::getWeight()
{
	return weight;
}

double Package::getUnitCost()
{
	return unitCost;
}

/* get sender's information */
string Package::getSenderName()
{
	return senderName;
}

string Package::getSenderAddress()
{
	return senderAddress;
}

string Package::getSenderCity()
{
	return senderCity;
}

string Package::getSenderState()
{
	return senderState;
}

string Package::getSenderZipcode()
{
	return senderZipcode;
}

/* get recipient's information */
string Package::getRecipientName()
{
	return recipientName;
}

string Package::getRecipientAddress()
{
	return recipientAddress;
}

string Package::getRecipientCity()
{
	return recipientCity;
}

string Package::getRecipientState()
{
	return recipientState;
}

string Package::getRecipientZipcode()
{
	return recipientZipcode;
}

double Package::calculateCost()
{
	return getWeight() * getUnitCost();
}

void Package::print()
{
	cout << "****** Package basic information ******" << endl;
	cout << "Sender: " << endl << getSenderName() << endl << getSenderAddress() << endl << getSenderCity() << ", " << getSenderState() << " " << getSenderZipcode() << endl;
	cout << endl << "Recipient: " << endl << getRecipientName() << endl << getRecipientAddress() << endl << getRecipientCity() << ", " << getRecipientState() << " " << getRecipientZipcode() << endl;
	
	cout << endl << "Weight of package: " << getWeight() << " (ounce)" << endl;
	cout << "Typle of delivery: Regular Delivery" << endl;
	cout << "Cost of Package: " << "$" << calculateCost() << endl;
}