#pragma once
#ifndef MATRIX_H
#define MATRIX_H

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
	Matrix(Matrix& m);
	~Matrix();
	void fill();
	virtual void print();
	void random_fill();
	Matrix transpose();
	Matrix randMatrix();
};

#endif

