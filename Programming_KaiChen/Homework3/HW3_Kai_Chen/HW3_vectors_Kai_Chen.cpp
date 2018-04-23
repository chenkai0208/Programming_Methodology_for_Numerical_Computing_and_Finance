//============================================================================
// Name        : HW3_vectors_Kai_Chen.cpp
// Author      : Kai Chen
// RUID        : 183001550
// Date        : 10/09/2017
// Description : Homework3_Vectors Operation
//============================================================================

#include<iostream>
#include<vector>
#include <iomanip>

using namespace std;

void inputArray(int row, int column, vector<vector<float> > array);
void printArray(vector<vector<float> > array);
void matrixAddition(vector<vector<float> > m1, vector<vector<float> > m2);
void matrixSubtraction(vector<vector<float> > m1, vector<vector<float> > m2);
void matrixMultiplication(vector<vector<float> > m1, vector<vector<float> > m2);
void matrixTranspose(vector<vector<float> > m1);
float matrixDeterminant(vector<vector<float> > m1);
void matrixInverse(vector<vector<float> > m1);

int main() {

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

	int row1, row2, column1, column2;
	cout << "# Now input the first matrix #" << endl;
	cout << "Please enter the number of row: ";
	cin >> row1;
	cout << "Please enter the number of colume: ";
	cin >> column1;
	cout << "\nPlease enter the values of elements in the first matrix: " << endl;

	/* Input matrix m1 */
	vector<vector<float> > m1(row1);
	for(int i=0;i<row1;i++) 
    {
        m1[i].resize(column1);
    }
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < column1; j++)
			{cin >> m1[i][j];}
	}
	cout << "Your first matrix is: " << endl;
	printArray(m1);


	cout << "# Now input the second matrix #" << endl;
	cout << "Please enter the number of row: ";
	cin >> row2;
	cout << "Please enter the number of colume: ";
	cin >> column2;
	cout << "\nPlease enter the values of elements in the second matrix: " << endl;

	/* Input matrix m2 */
	vector<vector<float> > m2(row2);
	for(int i=0;i<row2;i++) 
    {
        m2[i].resize(column2);
    }
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < column2; j++)
			{cin >> m2[i][j];}
	}
	cout << "Your second matrix is: " << endl;
	printArray (m2);

	switch(choice)
	{
		case 1: // addition
		if ((row1 != row2) || (column1 != column2))
		{
			cout << "This operation is not supported! (error 1: adding two matrices of different dimensions)";
			break;}
		else
			{
			cout << "The addition of m1 and m2 is: " << endl;
			matrixAddition(m1, m2);
			break;}

		case 2: // subtraction
		if ((row1 != row2) || (column1 != column2))
		{
			cout << "This operation is not supported! (error 2: subtraction two matrices of different dimensions)";
			break;}
		else
			{
			cout << "The subtraction of m1 and m2 is: " << endl;
			matrixSubtraction(m1, m2);
			break;}

		case 3: // multiplication
		if (column1 != row2)
		{
			cout << "This operation is not supported! (error 3: these two matrices cannot be multiplied)";
			break;}
		else
			{
			cout << "The multiplication of m1 and m2 is: " << endl;
			matrixMultiplication(m1, m2);
			break;}

		case 4: // transpose
			cout << "The transpose of m1 is: " << endl;
			matrixTranspose(m1);
			break;

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
			cout << "The inverse of m1 is: " << endl;
			matrixInverse(m1);
			break;}

		default:
		cout << "The program should never be here!" << endl;
		break;
	}

    return main();
} 



/* The function for print a matrix on the screen */
void printArray(vector<vector<float> > array)
{
	cout << endl;
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[0].size(); j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

/* Add two matrices m1 and m2. Store the results in m1. */
void matrixAddition(vector<vector<float> > m1, vector<vector<float> > m2)
{
	for (int i = 0; i < m1.size(); i++)
	{
		for (int j = 0; j < m1[0].size(); j++)
		{
			m1[i][j] = m1[i][j] + m2[i][j];
		}
	}
	printArray(m1);
}

/* Subtract two matrices m1 and m2. Store the results in m1. */
void matrixSubtraction(vector<vector<float> > m1, vector<vector<float> > m2)
{
	for (int i = 0; i < m1.size(); i++)
	{
		for (int j = 0; j < m1[0].size(); j++)
		{
			m1[i][j] = m1[i][j] - m2[i][j];
		}
	}
	printArray(m1);
}


/* Multiply two matrices m1 and m2. Store the results in m3. */
void matrixMultiplication(vector<vector<float> > m1, vector<vector<float> > m2)
{
	vector<vector<float> > m3(m1.size());
	for(int i=0;i<m1.size();i++) 
    {
        m3[i].resize(m2[0].size());
    }
	for (int i = 0; i < m1.size(); i++)
	{
		for (int j = 0; j < m2[0].size(); j++)
		{
			for (int k = 0; k < m1[0].size(); k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	printArray(m3);
}

/* Transpose m1 and save the results in m1. */
void matrixTranspose(vector<vector<float> > m1)
{
	vector<vector<float> > trans(m1[0].size());
	for(int i=0;i<m1[0].size();i++) 
    {
        trans[i].resize(m1.size());
    }
	for (int i = 0; i < m1.size(); i++)
	{
		for (int j = 0; j < m1[0].size(); j++)
		{
			trans[j][i] = m1[i][j];
		}
	}
	printArray(trans);
}

/* Calculate the determinant of m1 */
float matrixDeterminant(vector<vector<float> > m1)
{
	float det;
	det = (m1[0][0] * m1[1][1] * m1[2][2] + m1[0][1] * m1[1][2] * m1[2][0] +m1[0][2] * m1[2][1] * m1[1][0]
		  - m1[0][2] * m1[1][1] * m1[2][0] - m1[0][0] * m1[1][2] * m1[2][1] - m1[1][0] * m1[0][1] * m1[2][2]);
	return det;
}

/* Inverse m1 and save the results in mInverse */
void matrixInverse(vector<vector<float> > m1)
{
	float det;
	det = matrixDeterminant(m1);
	vector<vector<float> > mInverse(m1.size());
	for(int i=0;i<m1.size();i++) 
    {
        mInverse[i].resize(m1[0].size());
    }
	mInverse[0][0] = (m1[1][1]*m1[2][2]-m1[1][2]*m1[2][1])/det;
	mInverse[0][1] = (m1[0][2]*m1[2][1]-m1[0][1]*m1[2][2])/det;
	mInverse[0][2] = (m1[0][1]*m1[1][2]-m1[0][2]*m1[1][1])/det;
	mInverse[1][0] = (m1[1][2]*m1[2][0]-m1[1][0]*m1[2][2])/det;
	mInverse[1][1] = (m1[0][0]*m1[2][2]-m1[0][2]*m1[2][0])/det;
	mInverse[1][2] = (m1[0][2]*m1[1][0]-m1[0][0]*m1[1][2])/det;
	mInverse[2][0] = (m1[1][0]*m1[2][1]-m1[1][1]*m1[2][0])/det;
	mInverse[2][1] = (m1[0][1]*m1[2][0]-m1[0][0]*m1[2][1])/det;
	mInverse[2][2] = (m1[0][0]*m1[1][1]-m1[0][1]*m1[1][0])/det;
	printArray(mInverse);
}
