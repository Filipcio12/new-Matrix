#pragma once
#include <iostream>
#include <cstdlib>

class Matrix {
	struct rcMatrix;
	rcMatrix* data;

	public:
	// Exceptions
		class InvalidRange {};
		class InvalidAddition {};
		class InvalidRead {};

	// Constructors and destructor
		Matrix();
		Matrix(size_t rows, size_t cols);
		Matrix(const Matrix& m);
		~Matrix();
	
	// Assignment operator
		Matrix& operator=(const Matrix& m);
		
	// Access operators
		double operator()(size_t row, size_t col) const;
		double& operator()(size_t row, size_t col);
	
	// Display operator
		friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
	
	// Arithmetic operators
		Matrix operator+(const Matrix& m) const;

	// Reading from input file stream
		friend std::istream& operator>>(std::istream& is, Matrix& m);
};

std::string* readText(std::istream& is, size_t& size);
void incrementSize(std::string* text, size_t& size);
size_t countTokens(std::string line, const char delim[]);