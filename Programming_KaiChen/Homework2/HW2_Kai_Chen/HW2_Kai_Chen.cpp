//============================================================================
// Name        : HW2_Kai_Chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 9/23/2017
// Description : Monte Carlo Assignment (Automatically stop the iterations 
//               by comparing the estimate to the known value)
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

// function main begins program execution
int main(){
	unsigned int iteration = 0;
	long rand1, rand2;
	float x, y;
	double circle;
	double simulatePi;
	double inside = 0, outside = 0;
	int position;
	double error = 1;


	srand(time(0)); // generate different sets of random numbers
	

	while (error >= 0.0001)
	{
		// generate the coordinates for random points
		iteration++;
		rand1 = 1 + rand() % 1000; // random number from 0 to 1
		rand2 = 1 + rand() % 1000;

		x = rand1 / 1000.0;
		y = rand2 / 1000.0;

		// write the data into a txt file
		ofstream file;
		file.open("HW2_Kai_Chen.txt", ios::app);
		file << x << "," << y << "\n";

		// determine the random point is inside or outside the circle
		circle = x * x + y * y;

		position = (circle <= 1); // equals 1 when point is inside, 0 outside
		
		switch (position)
		{
			case 1:
				inside++;
				break;
			case 0:
				outside++;
				break;
			default:         // invalid value
				cout << "Program should never get here";
		}

		// calculate the error between simulation and known value
		simulatePi = 4.0 * (inside / (outside + inside));
		error = abs(simulatePi - 3.1415);
	}

	cout << "The estimated value of pi is: " << simulatePi << endl;
	cout << "(This program used " << iteration << " iterations to make the error less than 0.0001.)" << endl;

	return 0;
}