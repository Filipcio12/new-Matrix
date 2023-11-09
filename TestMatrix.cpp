#include "Matrix.h"

#include <iostream>

int main()
{
	Matrix a(2, 2);
	a(0, 0) = 1;
	a(0, 1) = 1;

	Matrix b = a;
	
	a(1, 0) = 1;
	a(1, 1) = 1;

	std::cout << a << std::endl <<  b << std::endl;

	return 0;
}
