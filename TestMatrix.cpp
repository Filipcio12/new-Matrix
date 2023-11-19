#include "Matrix.h"

#include <iostream>
#include <fstream>

void testProcessArray();
void testDefaultConstructor();
void testConstructor();
void testCopyConstructor();
void testAssignment();
void testInputFile();
void testAddition();

int main()
{
	testProcessArray();
	testDefaultConstructor();
	testConstructor();
	testCopyConstructor();
	testAssignment();
	testInputFile();
	//testAddition();
	return 0;
}

void testProcessArray()
{
	std::cout << "Function processArray():" << std::endl;
	double arr[2][2] = {
		{1.2, 2.7},
		{-2, 1.3}
	};
	Matrix a = processArray(arr);
	std::cout << a << std::endl;
}

void testDefaultConstructor()
{
	std::cout << "Default constructor:" << std::endl;
	Matrix a;
	std::cout << a << std::endl;
}

void testConstructor()
{
	std::cout << "Size constructor:" << std::endl;
	Matrix a(2, 2);
	std::cout << a << std::endl;
}

void testCopyConstructor()
{
	std::cout << "Copy constructor:" << std::endl;
	Matrix a(2, 2);
	Matrix b(a);
	std::cout << b << std::endl;
}

void testAssignment()
{
	std::cout << "Assignment:" << std::endl;
	Matrix a(2, 2);
	Matrix b(3, 1);
	b = a;
	std::cout << b << std::endl;
}

void testInputFile()
{
	std::cout << "Input file:" << std::endl;
	std::fstream testFile;
	testFile.open("testFile.txt", std::ios::in);
	Matrix a;
	testFile >> a;
	testFile.close();
	std::cout << a << std::endl;
}

void testAddition()
{
	double a[2][2] = {
		{1, 2},
		{2, 1}
	};
	double b[2][2] = {
		{1, 0},
		{0, 1}
	};
	Matrix matA = processArray(a);
	Matrix matB = processArray(b);
	std::cout << matA - matB << std::endl;
	matA += matB;
	std::cout << matA;
}