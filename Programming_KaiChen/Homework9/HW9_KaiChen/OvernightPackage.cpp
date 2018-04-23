// OvernightPackage class member functions

#include <iostream>

using namespace std;

#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(string senderName, string senderAddress, string senderCity, string senderState, string senderZipcode, 
	             			 string recipientName, string recipientAddress, string recipientCity, string recipientState, string recipientZipcode,
	             			 double weightValue, double unitCostValue, double overnightFeeValue)
						: Package(senderName, senderAddress, senderCity, senderState, senderZipcode, 
							      recipientName, recipientAddress, recipientCity, recipientState, recipientZipcode, weightValue, unitCostValue) // call base-class constructor
{
	setOvernightFee(overnightFeeValue);
} // end constructor

void OvernightPackage::setOvernightFee(double overnightFeeValue)
{
	overnightFee = (overnightFeeValue < 0.0 ? 0.0 : overnightFeeValue);
}

double OvernightPackage::getOvernightFee()
{
	return overnightFee;
}

double OvernightPackage::calculateCost()
{
	return getWeight() * (getUnitCost() + getOvernightFee());
}

void OvernightPackage::print()
{
	cout << "****** Package basic information ******" << endl;
	cout << "Sender: " << endl << getSenderName() << endl << getSenderAddress() << endl << getSenderCity() << ", " << getSenderState() << " " << getSenderZipcode() << endl;
	cout << endl << "Recipient: " << endl << getRecipientName() << endl << getRecipientAddress() << endl << getRecipientCity() << ", " << getRecipientState() << " " << getRecipientZipcode() << endl;

	cout << endl << "Weight of package: " << getWeight() << " (ounce)" << endl;
	cout << "Typle of delivery: Overnight Delivery" << endl;
	cout << "Cost of Package: " << "$" << calculateCost() << endl;
}