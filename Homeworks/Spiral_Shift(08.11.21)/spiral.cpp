#include <iostream>

void spiral(int**, int, int);
void printarray(int**, int, int);

int maxarray(int**, int, int);
int nodigits(int);

int main()
{
    int n;
    do
    {
        std::cout << "Input number of rows: ";
        std::cin >> n;
    } while (n < 1);
    int m;
    do
    {
        std::cout << "Input number of columns: ";
        std::cin >> m;
    } while (m < 1);
    int** M = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        M[i] = new int[m];
    }
    spiral(M, n, m);
    printarray(M, n, m);
    for (int i = 0; i < n; ++i)
    {
        delete[] M[i];
    }
    delete[] M;
}

void spiral(int** M, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            M[i][j] = 0;
        }
    }
    int i = 0, j = 0, dir = 1;
    bool col = true;
    for (int k = 1; k <= n * m; ++k)
    {
        M[i][j] = k;
        if (col)
        {
            if (j + dir > m - 1 || M[i][j + dir] != 0)
            {
                col = false;
                i += dir;
            }
            else
            {
                j += dir;
            }
        }
        else
        {
            if (i + dir > n - 1 || M[i + dir][j] != 0)
            {
                dir *= -1;
                col = true;
                j += dir;
            }
            else
            {
                i += dir;
            }
        }
    }
}

void printarray(int** M, int n, int m)
{
    int h = nodigits(maxarray(M, n, m)) + 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << M[i][j];
            for (int k = h - nodigits(M[i][j]); k > 0; --k)
            {
                std::cout.put(' ');
            }
        }
        std::cout << std::endl;
    }
}

int maxarray(int** M, int n, int m)
{
    int h = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            h = M[i][j] > h ? M[i][j] : h;
        }
    }
    return h;
}

int nodigits(int n)
{
    int k = 0;
    while (n)
    {
        n /= 10;
        ++k;
    }
    return k;
}