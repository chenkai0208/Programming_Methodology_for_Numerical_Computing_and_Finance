// TwoDayPackage class member functions

#include <iostream>

using namespace std;

#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(string senderName, string senderAddress, string senderCity, string senderState, string senderZipcode, 
	             			 string recipientName, string recipientAddress, string recipientCity, string recipientState, string recipientZipcode,
	             			 double weightValue, double unitCostValue, double flatFee)
						: Package(senderName, senderAddress, senderCity, senderState, senderZipcode, 
							      recipientName, recipientAddress, recipientCity, recipientState, recipientZipcode, weightValue, unitCostValue) // call base-class constructor
{
	setFlatFee(flatFee);
} // end constructor

void TwoDayPackage::setFlatFee(double flatFeeValue)
{
	flatFee = (flatFeeValue < 0.0 ? 0.0 : flatFeeValue);
}

double TwoDayPackage::getFlatFee()
{
	return flatFee;
}

double TwoDayPackage::calculateCost()
{
	return getWeight() * (getUnitCost() + getFlatFee());
}

void TwoDayPackage::print()
{
	cout << "****** Package basic information ******" << endl;
	cout << "Sender: " << endl << getSenderName() << endl << getSenderAddress() << endl << getSenderCity() << ", " << getSenderState() << " " << getSenderZipcode() << endl;
	cout << endl << "Recipient: " << endl << getRecipientName() << endl << getRecipientAddress() << endl << getRecipientCity() << ", " << getRecipientState() << " " << getRecipientZipcode() << endl;

	cout << endl << "Weight of package: " << getWeight() << " (ounce)" << endl;
	cout << "Typle of delivery: Two Day Delivery" << endl;
	cout << "Cost of Package: " << "$" << calculateCost() << endl;
}