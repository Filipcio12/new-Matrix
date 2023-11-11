#include "Matrix.h"

#include <iostream>

void testDefaultConstructor();
void testConstructor();
void testCopyConstructor();

int main()
{
	testDefaultConstructor();
	testConstructor();
	return 0;
}

void testDefaultConstructor()
{
	Matrix a;
	try {
		a(0, 0);
	}
	catch(Matrix::InvalidRangeException) {
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
	} catch(Matrix::InvalidRangeException) {
		std::cout << "Constructor: Failed" << std::endl;
		return;
	}

	std::cout << "Constructor: Passed" << std::endl;
}
