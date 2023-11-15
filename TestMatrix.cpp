#include "Matrix.h"

#include <iostream>
#include <fstream>

void testDefaultConstructor();
void testConstructor();
void testCopyConstructor();
void testAssignment();
void testInputFile();
void testAddition();

int main()
{
	//testDefaultConstructor();
	//testConstructor();
	testCopyConstructor();
	//testAssignment();
	//testInputFile();
	return 0;
}

void testAddition()
{
	Matrix a, b;
}

void testInputFile()
{
	std::fstream testFile;
	testFile.open("testFile.txt", std::ios::in);

	Matrix a;
	testFile >> a;
	testFile.close();

	size_t value = 1;
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			try {
				if (a(i, j) != value) {
					std::cout << "Input file stream: Failed" << std::endl;
					return;
				}
			} catch(Matrix::InvalidRange) {
				std::cout << "Input file stream: Failed" << std::endl;
				return;
			}
			value++;
		}
	}

	std::cout << "Input file stream: Passed" << std::endl;
}

void testAssignment()
{
	Matrix a(2, 2);
	Matrix b;
	b = a;
	try {
		for (size_t i = 0; i < 2; i++) {
			for (size_t j = 0; j < 2; ++j) {
				if (b(i, j) != 0) {
					std::cout << "Assignment operator: Failed" << std::endl;
					return;
				}
			}
		}
	} catch(Matrix::InvalidRange) {
		std::cout << "Assignment operator: Failed" << std::endl;
		return;
	}

	std::cout << "Assignment operator: Passed" << std::endl;
}

void testCopyConstructor()
{
	Matrix a(2, 2);
	Matrix b = a;
	try {
		for (size_t i = 0; i < 2; i++) {
			for (size_t j = 0; j < 2; ++j) {
				if (b(i, j) != 0) {
					std::cout << "Copy constructor: Failed" << std::endl;
					return;
				}
			}
		}
	} catch(Matrix::InvalidRange) {
		std::cout << "Copy constructor: Failed" << std::endl;
		return;
	}

	std::cout << "Copy constructor: Passed" << std::endl;
}

void testDefaultConstructor()
{
	Matrix a;
	try {
		a(0, 0);
	}
	catch(Matrix::InvalidRange) {
		std::cout << "Default constructor: Passed" << std::endl;
		return;
	}
	std::cout << "Default constructor: Passed" << std::endl;
}

void testConstructor()
{
	Matrix a(2, 2);

	try {
		for (size_t i = 0; i < 2; i++) {
			for (size_t j = 0; j < 2; ++j) {
				if (a(i, j) != 0) {
					std::cout << "Constructor: Failed" << std::endl;
					return;
				}
			}
		}
	} catch(Matrix::InvalidRange) {
		std::cout << "Constructor: Failed" << std::endl;
		return;
	}

	std::cout << "Constructor: Passed" << std::endl;
}
