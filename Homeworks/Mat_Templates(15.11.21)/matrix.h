#pragma once

template <typename T>
T** creatematrix(int n, int m)
{
	T** M = new T * [n];
	for (int i = 0; i < n; ++i)
	{
		M[i] = new T[m];
	}
	return M;
}

template <typename T>
T** inputmatrix(int n, int m)
{
	T** M = creatematrix<T>(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << '(' << i + 1 << ", " << j + 1 << "): ";
			std::cin >> M[i][j];
		}
	}
	return M;
}

template <typename T>
void printmatrix(T** M, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << M[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

template <typename T>
void deletematrix(T** M, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] M[i];
	}
	delete[] M;
}

template <typename T>
double** copymatrix_double(T** M, int n, int m)
{
	double** A = creatematrix<double>(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			A[i][j] = double(M[i][j]);
		}
	}
	return A;
}

template <typename T>
void swapcolumns(T** M, int n, int c1, int c2)
{
	for (int i = 0; i < n; ++i)
	{
		std::swap(M[i][c1], M[i][c2]);
	}
}

template <typename T>
T determinant(T** M, int n)
{
	double** A = copymatrix_double(M, n, n);
	double a;
	int k1, sign = 1;
	bool b;
	for (int k = 0; k < n - 1; ++k)
	{
		if (A[k][k] == 0)
		{
			b = true;
			for (int j = k + 1; j < n; ++j)
			{
				if (A[k][j] != 0)
				{
					b = false;
					k1 = j;
					break;
				}
			}
			if (b)
			{
				return 0;
			}
			swapcolumns(A, n, k, k1);
			sign *= -1;
		}
		for (int i = k + 1; i < n; ++i)
		{
			a = A[i][k] / A[k][k];
			for (int j = k; j < n; ++j)
			{
				A[i][j] -= A[k][j] * a;
			}
		}
	}
	double res = 1;
	for (int i = 0; i < n; ++i)
	{
		res *= A[i][i];
	}
	deletematrix(A, n);
	return T(0.1) == 0 ? T(round(res * sign)) : (res * sign); // T(res) при int может выводить неправильный ответ
}

template <typename T>
T** matrixminor(T** M, int n, int a, int b)
{
	T** A = creatematrix<T>(n - 1, n - 1);
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			A[i][j] = M[i][j];
		}
		for (int j = b + 1; j < n; ++j)
		{
			A[i][j - 1] = M[i][j];
		}
	}
	for (int i = a + 1; i < n; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			A[i - 1][j] = M[i][j];
		}
		for (int j = b + 1; j < n; ++j)
		{
			A[i - 1][j - 1] = M[i][j];
		}
	}
	return A;
}

template <typename T>
double** inversematrix(T** M, int n)
{
	double** A = creatematrix<double>(n, n);
	double det = determinant(M, n), det1;
	if (det == 0)
	{
		throw "Determinant is equal to zero";
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			T** B = matrixminor(M, n, j, i);
			A[i][j] = double(determinant(B, n - 1)) / det;
			deletematrix(B, n - 1);
			if ((i + j) % 2)
			{
				A[i][j] *= -1;
			}
			A[i][j] = A[i][j] == 0 ? 0 : A[i][j]; // Так как появляется -0
		}
	}
	return A;
}