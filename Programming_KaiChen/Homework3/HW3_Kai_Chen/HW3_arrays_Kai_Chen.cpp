//============================================================================
// Name        : HW3_arrays_Kai_Chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 10/09/2017
// Description : Homework3_Matrices Operation
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

/* Function Prototype */
void printArray (int row, int column, float a[][10]);
void inputArray (int row, int column, float a[][10]);
void matrixAddition (int row, int column, float m1[][10], float m2[][10]);
void matrixSubtraction (int row, int column, float m1[][10], float m2[][10]);
void matrixMultiplication (int m, int n, int p, float m1[][10], float m2[][10], float m3[][10]);
void matrixTranspose(int row, int column, float m1[][10], float trans[][10]);
float matrixDeterminant (float m1[][10]);
void matrixInverse(float m1[][10], float mInverse[3][10]);

int main()
{
	cout << "\n Menu";
	cout << "\n Choice 1: Addition";
	cout << "\n Choice 2: Substraction";
	cout << "\n Choice 3: Multiplication";
	cout << "\n Choice 4: Transpose";
	cout << "\n Choice 5: Determinant";
	cout << "\n Choice 6: Inverse";
	cout << "\n Choice 7: Quit";
	cout << "\n Please enter your choice: " << endl;
	int choice = 0;
	cin >> choice;

	if (choice == 7) // The program terminates only when user types in 7
	{
		return 0;
	}

	/* Input matrices. Store them in m1 and m2. Print them out. */
	int row1, row2, column1, column2;
	cout << "# Now input the first matrix #" << endl;
	cout << "Please enter the number of row: ";
	cin >> row1;
	cout << "Please enter the number of colume: ";
	cin >> column1;
	cout << "\nPlease enter the values of elements in the first matrix: " << endl;
	float m1[10][10] = {0};
	float m2[10][10] = {0};
	inputArray (row1, column1, m1);
	cout << "Your first matrix is: " << endl;
	printArray (row1, column1, m1);

	/* Only need to define the second matrix when use enter Choice 1, 2, or 3. */
	while ((choice == 1) || (choice == 2) || (choice == 3))
	{
	cout << "# Now input the second matrix #" << endl;
	cout << "Please enter the number of row: ";
	cin >> row2;
	cout << "Please enter the number of colume: ";
	cin >> column2;
	cout << "\nPlease enter the values of elements in the second matrix: " << endl;
	inputArray (row2, column2, m2);
	cout << "Your second matrix is: " << endl;
	printArray (row2, column2, m2);
	break;
	}

	switch(choice)
	{
		case 1: // addition
		if ((row1 != row2) || (column1 != column2))
		{
			cout << "This operation is not supported! (error 1: adding two matrices of different dimensions)";
			break;}
		else
			{matrixAddition(row1, column1, m1, m2);
			cout << "The addition of m1 and m2 is: " << endl;
			printArray(row1,column1,m1);
			break;}

		case 2: // subtraction
		if ((row1 != row2) || (column1 != column2))
		{
			cout << "This operation is not supported! (error 2: subtracting two matrices of different dimensions)";
			break;}
		else
			{matrixSubtraction(row1, column1, m1, m2);
			cout << "The subtraction of m1 and m2 is: " << endl;
			printArray(row1,column1,m1);
			break;}

		case 3: // multiplication
		if (column1 != row2)
		{
			cout << "This operation is not supported! (error 3: these two matrices cannot be multiplied)";
			break;}
		else
			{float m3[10][10] = {0};
			matrixMultiplication(row1, column1, column2, m1, m2, m3);
			cout << "The multiplication of m1 and m2 is: " << endl;
			printArray(row1,column2,m3);
			break;}

		case 4: // transpose
			{float trans[10][10] = {0};
			matrixTranspose(row1, column1, m1, trans);
			cout << "The transpose of m1 is: " << endl;
			printArray(column1, row1, trans);
			break;}


		case 5: // determinant
		if ((row1 != 3) || (column1 != 3))
		{
			cout << "This operation is not supported! (error 4: this function can only calculate the determinant of 3X3 matrix)";
			break;}
		else{
			float det;
			det = matrixDeterminant(m1);
			cout << "The determinant of m1 is: " << endl << det << endl;
			break;}

		case 6: // inverse
		if ((row1 != 3) || (column1 != 3))
		{
			cout << "This operation is not supported! (error 4: this function can only calculate the inverse of 3X3 matrix)";
			break;}
		else{
			float mInverse[3][10] = {0};
			matrixInverse(m1, mInverse);
			cout << "The inverse of m1 is: " << endl;
			printArray(3, 3, mInverse);
			break;}

		default:
		cout << "The program should never be here!" << endl;
		break;
	}
	return main();
}


/* The function for input a matrix */
void inputArray(int row, int column, float a[][10])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			{cin >> a[i][j];}
	}
}



/* The function for print a matrix on the screen */
void printArray(int row, int column, float a[][10])
{
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

/* Add two matrices m1 and m2. Store the results in m1. */
void matrixAddition(int row, int column, float m1[][10], float m2[][10])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			m1[i][j] = m1[i][j] + m2[i][j];
		}
		cout << endl;
	}
}

/* Subtract two matrices m1 and m2. Store the results in m1. */
void matrixSubtraction(int row, int column, float m1[][10], float m2[][10])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			m1[i][j] = m1[i][j] - m2[i][j];
		}
		cout << endl;
	}
}

/* Multiply two matrices m1 and m2. Store the results in m3. */
void matrixMultiplication(int m, int n, int p, float m1[][10], float m2[][10], float m3[][10])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < p; j++)
		{
			for (int k = 0; k < n; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}


/* Transpose m1 and save the results in trans. */
void matrixTranspose(int row, int column, float m1[][10], float trans[][10])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			trans[j][i] = m1[i][j];
		}
	}
}

/* Calculate the determinant of m1 */
float matrixDeterminant(float m1[][10])
{
	float det;
	det = (m1[0][0] * m1[1][1] * m1[2][2] + m1[0][1] * m1[1][2] * m1[2][0] +m1[0][2] * m1[2][1] * m1[1][0]
		  - m1[0][2] * m1[1][1] * m1[2][0] - m1[0][0] * m1[1][2] * m1[2][1] - m1[1][0] * m1[0][1] * m1[2][2]);
	return det;
}

/* Inverse m1 and save the results in mInverse */
void matrixInverse(float m1[][10], float mInverse[3][10])
{
	float det;
	det = matrixDeterminant(m1);
	mInverse[0][0] = (m1[1][1]*m1[2][2]-m1[1][2]*m1[2][1])/det;
	mInverse[0][1] = (m1[0][2]*m1[2][1]-m1[0][1]*m1[2][2])/det;
	mInverse[0][2] = (m1[0][1]*m1[1][2]-m1[0][2]*m1[1][1])/det;
	mInverse[1][0] = (m1[1][2]*m1[2][0]-m1[1][0]*m1[2][2])/det;
	mInverse[1][1] = (m1[0][0]*m1[2][2]-m1[0][2]*m1[2][0])/det;
	mInverse[1][2] = (m1[0][2]*m1[1][0]-m1[0][0]*m1[1][2])/det;
	mInverse[2][0] = (m1[1][0]*m1[2][1]-m1[1][1]*m1[2][0])/det;
	mInverse[2][1] = (m1[0][1]*m1[2][0]-m1[0][0]*m1[2][1])/det;
	mInverse[2][2] = (m1[0][0]*m1[1][1]-m1[0][1]*m1[1][0])/det;
}