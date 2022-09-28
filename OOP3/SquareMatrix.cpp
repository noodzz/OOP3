#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>

using namespace std;

SquareMatrix::SquareMatrix() : Matrix()
{
	cout << "SquareMatrix()" << endl;
}
SquareMatrix::SquareMatrix(int n) : Matrix(n, n)
{
	cout << "SquareMatrix(int n)" << endl;
}
SquareMatrix::SquareMatrix(const SquareMatrix& sm)
{

	rows = sm.rows;
	cols = sm.rows;
	memory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			vals[i][j] = sm.vals[i][j];
	cout << "SquareMatrix(const Matrix& sm)" << endl;
}
SquareMatrix::~SquareMatrix()
{
	cout << "~SquareMatrix()" << endl;
}
void SquareMatrix::print()
{
	cout << "This is a square matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << vals[i][j] << " ";
		cout << endl;
	}
}
float SquareMatrix::determinant()
{
	float det = 0;
	if (rows == 1) det = vals[0][0];
	else if (rows == 2)
		det = vals[0][0] * vals[1][1] - vals[0][1] * vals[1][0];
	else
	{
		for (int i = 0; i < rows; i++)
			det += vals[0][i] * AlgCompl(1, i + 1);
	}
	return det;
}
SquareMatrix SquareMatrix::minor(int r, int c)
{
	if (r <= rows && c <= cols)
	{
		int _rows = 0, _cols = 0;
		SquareMatrix tmp(rows - 1);
		for (int i = 0; i < rows; i++)
		{
			if (i == r - 1) continue;
			else {
				for (int j = 0; j < rows; j++)
				{
					if (j == c - 1) continue;
					else
					{
						tmp.vals[_rows][_cols] = vals[i][j];
						_cols++;
					}
				}
			}
			_rows++;
			_cols = 0;
		}
		return tmp;
	}
}
SquareMatrix SquareMatrix::randSquareMatrix()
{
	srand(time(NULL));
	SquareMatrix tmp(1 + rand() % 5);
	tmp.random_fill();
	return tmp;
}