#include "Matrix.h"

#include <iostream>

void testConstructor();

int main()
{
	testConstructor();
	return 0;
}

void testConstructor()
{
	// Default constructor
	Matrix a;
	std::cout << a << std::endl;

	// Size constructor
	Matrix b(5, 5);
	std::cout << b << std::endl;

	// Copy constructor
	Matrix c = b;
	std::cout << c << std::endl; 
}
