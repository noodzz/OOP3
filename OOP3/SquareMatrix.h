#pragma once
#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include "Matrix.h"

class SquareMatrix : public Matrix {
private:
	SquareMatrix minor(int r, int c);
	float AlgCompl(int r, int c)
	{
		int sign;
		if ((r + c) % 2 == 0) sign = 1;
		else sign = -1;
		return sign * minor(r, c).determinant();
	}
public:
	SquareMatrix();
	SquareMatrix(int n);
	SquareMatrix(const SquareMatrix& sm);
	~SquareMatrix();
	void print() override;
	float determinant();
	SquareMatrix randSquareMatrix();
};

#endif // !SQUAREMATRIX_H

