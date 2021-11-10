#include <iostream>

void shiftarray(int*, int, int);

int main()
{
    int n;
    do
    {
        std::cout << "Input size of array: ";
        std::cin >> n;
    } while (n < 1);
    int* M = new int[n];
    std::cout << "Input array: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> M[i];
    }
    int k;
    do
    {
        std::cout << "Input size of shift: ";
        std::cin >> k;
    } while (k < 1);
    shiftarray(M, n, k);
    std::cout << "After the shift: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << M[i] << ' ';
    }
    delete[] M;
}

void shiftarray(int* M, int n, int k)
{
    int* A = new int[n];
    for (int i = 0; i < n; ++i)
    {
        A[i] = M[(i + k) % n];
    }
    for (int i = 0; i < n; ++i)
    {
        M[i] = A[i];
    }
    delete[] A;
}