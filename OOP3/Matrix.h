#pragma once
#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>

class Matrix
{
protected:
	int rows, cols;
	float** vals;
	void memory()
	{
		vals = new float* [rows]; 
		for (int i = 0; i < rows; i++)
			vals[i] = new float[cols];
	}
public:
	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& m);
	~Matrix();
	void fill();
	virtual void print();
	void random_fill();
	Matrix transpose();
	virtual float determinant() { return 0; };
	virtual int type() { return 1; };
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
};


#endif

