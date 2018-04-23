//============================================================================
// Name        : Main_KaiChen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 11/04/2017
// Description : Shape classes (inhirence practice)
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "point.h"
#include "circle.h"
#include "triangle.h"
#include "point3.h"
#include "sphere.h"
#include "tetrahedron.h"

#include "shape.cpp"
#include "TwoDimensionalShape.cpp"
#include "ThreeDimensionalShape.cpp"
#include "point.cpp"
#include "circle.cpp"
#include "triangle.cpp"
#include "point3.cpp"
#include "sphere.cpp"
#include "tetrahedron.cpp"

int main()
{
	int x = 0, y = 0, z = 0;
	double radius = 0.0, edge = 0.0;
	Circle circle;
	Triangle triangle;
	Sphere sphere;
	Tetrahedron tetrahedron;

	/* Menu */
	cout << "\n Welcome to the Book List Program. Please choose a shape or 0 to exit:";
	cout << "\n 	Choice 1: Circle";
	cout << "\n 	Choice 2: Triangle";
	cout << "\n 	Choice 3: Sphere";
	cout << "\n 	Choice 4: Regular Tetrahedron";
	cout << "\n 	Choice 0: exit";
	cout << "\n Please enter your choice: " << endl;
	int choice = 0;
	
	cin >> choice;

	if (choice == 0) // The program terminates only when user types in 0
	{
		return 0;
	}
	switch (choice)
	{
		case 1: // Circle
		cout << "You have chosen the circle." << endl;
		cout << "Please enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
		cin >> x >> y;
		cout << "Please enter the radius of the circle:" << endl;
		cin >> radius;
		circle.setX(x);
		circle.setY(y);
		circle.setRadius(radius);
		cout << circle.getName() << ": ";
		circle.print();
		break;

		case 2: // Triangle
		cout << "You have chosen the triangle." << endl;
		cout << "Please enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
		cin >> x >> y;
		cout << "Please enter the edge length of the triangle:" << endl;
		cin >> edge;
		triangle.setX(x);
		triangle.setY(y);
		triangle.setEdge(edge);
		cout << triangle.getName() << ": ";
		triangle.print();
		break;

		case 3: // Sphere
		cout << "You have chosen the sphere." << endl;
		cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate):" << endl;
		cin >> x >> y >> z;
		cout << "Please enter the radius of the sphere:" << endl;
		cin >> radius;
		sphere.setX(x);
		sphere.setY(y);
		sphere.setZ(z);
		sphere.setRadius(radius);
		cout << sphere.getName() << ": ";
		sphere.print();
		break;

		case 4: // Tetrahedron
		cout << "You have chosen the tetrahedron." << endl;
		cout << "Please enter the center of the tetrahedron (x-coordinate, y-coordinate, then z-coordinate):" << endl;
		cin >> x >> y >> z;
		cout << "Please enter the edge length of the tetrahedron:" << endl;
		cin >> edge;
		tetrahedron.setX(x);
		tetrahedron.setY(y);
		tetrahedron.setZ(z);
		tetrahedron.setEdge(edge);
		cout << tetrahedron.getName() << ": ";
		tetrahedron.print();
		break;

		default:
		cout << "The program should never be here!" << endl;
		break;
	}
	cout << "\n*****************************************************" << endl;
	return main();

}