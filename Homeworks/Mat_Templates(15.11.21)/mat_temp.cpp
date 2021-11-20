#include <iostream>
#include "matrix.h"

int main()
{
	int n;
	do
	{
		std::cout << "Input size of square matrix: ";
		std::cin >> n;
	} while (n < 1);
	double** M = inputmatrix<double>(n, n);
	std::cout << "Determinant = " << determinant(M, n) << std::endl;
	try
	{
		double** A = inversematrix(M, n);
		std::cout << "Inverse matrix:" << std::endl;
		printmatrix(A, n, n);
		deletematrix(A, n);
	}
	catch (const char c[])
	{
		std::cout << "Error: " << c << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}
	deletematrix(M, n);
}
