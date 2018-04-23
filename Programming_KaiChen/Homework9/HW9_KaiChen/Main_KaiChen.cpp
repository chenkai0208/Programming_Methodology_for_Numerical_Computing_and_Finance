//============================================================================
// Name        : Main_KaiChen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 11/11/2017
// Description : Package Inheritance Hierarchy
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

#include "package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

/* These codes are needed for my compilier */
/*
#include "package.cpp"
#include "TwoDayPackage.cpp"
#include "OvernightPackage.cpp"
*/

int main()
{
	double totalCost = 0.0; // track the total cost

	/* Menu */
	cout << "Package delivery services program" << endl;
	cout << "Cost per ounce for a package:  $.50/ounce" << endl;
	cout << "Additional cost for two day delivery:  $2.00/ounce" << endl;
	cout << "Additional cost for overnight delivery: $5.00/ounce" << endl;
	cout << endl;

	/* Use vector to save the pointers for new objects */
	vector<Package *> packagePt;
	Package* package1 = NULL;
	TwoDayPackage* package2 = NULL;
	OvernightPackage* package3 = NULL;
	package1 = new Package("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854", "Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854", 10.0, 0.5);
	totalCost += package1->calculateCost();
	package2 = new TwoDayPackage("Mary Smith", "1 Davidson Road", "Piscataway", "NJ", "08854", "Jennifer Smith", "2 Davidson Road", "Piscataway", "NJ", "08854", 5.0, 0.5, 2.0);
	totalCost += package2->calculateCost();
	package3 = new OvernightPackage("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854", "Mary Smith", "2 Davidson Road", "Piscataway", "NJ", "08854", 2.0, 0.5, 5.0);
	totalCost += package3->calculateCost();

	packagePt.push_back(package1);
	packagePt.push_back(package2);
	packagePt.push_back(package3);

	/* Print the result */
	cout << "Package1: " << endl;
	packagePt.at(0)->print();
	cout << endl << "Package2: " << endl;
	packagePt.at(1)->print();
	cout << endl << "Package3: " << endl;
	packagePt.at(2)->print();

	cout << endl << "Total cost: $" << totalCost << endl;

	/* delete the objects */
    for (vector<Package*>::iterator pObj = packagePt.begin();
         pObj != packagePt.end(); ++pObj) {
       delete *pObj; 
    }

    packagePt.clear();
	
	return 0;
}