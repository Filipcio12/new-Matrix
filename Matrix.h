#pragma once
#include <iostream>
#include <cstdlib>

class Matrix {
	struct rcMatrix;
	rcMatrix* data;
	
	public:
		class InvalidRange {};
		class InvalidAddition {};
		Matrix();
		Matrix(size_t rows, size_t cols);
		Matrix(const Matrix& m);
		~Matrix();

		Matrix& operator=(const Matrix& m);
		
		double operator()(size_t row, size_t col) const;
		double& operator()(size_t row, size_t col);
		
		friend std::ostream& operator<<(std::ostream& os, const Matrix& m); 
};
