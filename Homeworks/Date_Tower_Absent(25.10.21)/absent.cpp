#include <iostream>
#include <time.h>

void full(int m[], int n);

int main()
{
    int n;
    do
    {
        std::cout << "Input n: ";
        std::cin >> n;
    } while (n < 2);
    int* m = new int[n];
    full(m, n);
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += m[i];
        std::cout << m[i] << ' ';
    }
    delete[] m;
    std::cout << std::endl << "Absent element: " << ((n * (n + 1)) / 2) - s << std::endl;
}

void full(int m[], int n)
{
    srand(time(NULL));
    bool* ind = new bool[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        ind[i] = true;
        if (i < n)
        {
            m[i] = -1;
        }
    }
    int x;
    for (int i = 0; i < n; ++i)
    {
        do
        {
            x = rand() % (n + 1);
            if (ind[x])
            {
                m[i] = x;
                ind[x] = false;
            }
        } while (m[i] == -1);
    }
    delete[] ind;
}