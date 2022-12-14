#include "Matrix.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Matrix::Matrix()
{
	rows = 1;
	cols = 1;
	memory();
	vals[0][0] = 0;
}
Matrix::Matrix(int r, int c)
	: rows(r), cols(c)
{
	memory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			vals[i][j] = 0;
}
Matrix::Matrix(const Matrix& m)
{
	rows = m.rows;
	cols = m.cols;
	memory();
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			vals[i][j] = m.vals[i][j];

}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] vals[i];
	delete[] vals;
}
void Matrix::fill()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> vals[i][j];
}
void Matrix::print()
{
	cout << "This is a rectangular matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << vals[i][j] << " ";
		cout << endl;
	}
}
void Matrix::random_fill()
{
	srand(time(0));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			vals[i][j] = 1 + rand() % 100;
}
Matrix Matrix::transpose()
{
	Matrix res(cols, rows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			res.vals[j][i] = vals[i][j];
	return res;
}
ostream& operator <<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
			os << m.vals[i][j] << " ";
		os << endl;
	}
	return os;
}
void Matrix::set(int _r, int _c)
{
	if (rows == 0 && cols == 0)
	{
		rows = _r;
		cols = _c;
	}
	else return;
}
