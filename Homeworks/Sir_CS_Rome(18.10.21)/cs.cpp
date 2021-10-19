#include <iostream>

void cs(unsigned int a, unsigned int n);
void cs2(unsigned int a, unsigned int n);
void pd(int d);

int main()
{
    int a, n;
    do
    {
        std::cout << "Input integer number and number system:" << std::endl;
        std::cin >> a;
        std::cin >> n;
    } while (a < 0 || n < 2 || n > 16);
    cs(a, n);
}

void cs(unsigned int a, unsigned int n)
{
    if (n == 2)
    {
        cs2(a, 1);
    }
    else if (n == 4)
    {
        cs2(a, 2);
    }
    else if (n == 8)
    {
        cs2(a, 3);
    }
    else if (n == 16)
    {
        cs2(a, 4);
    }
    else
    {
        int x = a, m = 0;
        while (x)
        {
            ++m;
            x /= n;
        }
        int* d = new int[m];
        x = a;
        for (int i = 0; i < m; ++i)
        {
            d[i] = x % n;
            x /= n;
        }
        for (int i = m - 1; i > -1; --i)
        {
            pd(d[i]);
        }
        delete[] d;
    }
}

void cs2(unsigned int a, unsigned int n)
{
    unsigned int x = a, m = 0;
    while (x)
    {
        ++m;
        x >>= n;
    }
    m = m > 0 ? m - 1 : 0;
    m = 1 << (m * n);
    x = a;
    while (m)
    {
        int d = x / m;
        pd(d);
        x %= m;
        m >>= n;
    }
}

void pd(int d)
{
    if (d < 10)
    {
        std::cout << d;
    }
    else
    {
        std::cout << char('A' + d - 10);
    }
}
