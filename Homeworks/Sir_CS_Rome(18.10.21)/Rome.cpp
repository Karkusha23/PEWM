#include <iostream>

char p(int n);

int main()
{
    int n;
    do
    {
        std::cout << "Input integer n in range [1; 3999]: ";
        std::cin >> n;
    } while (n < 1 || n > 3999);
    int a = n / 1000;
    int d[3] = {(n % 1000) / 100, (n % 100) / 10, n % 10};
    for (int i = 0; i < a; ++i)
    {
        std::cout.put('M');
    }
    char x, y, z;
    for (int i = 0; i < 3; ++i)
    {
        if (d[i] == 0)
        {
            continue;
        }
        x = p((i + 1) * 2 + 1);
        y = p((i + 1) * 2);
        z = p((i + 1) * 2 - 1);
        if (d[i] > 0 && d[i] < 4)
        {
            for (int j = 0; j < d[i]; ++j)
            {
                std::cout.put(x);
            }
        }
        else if (d[i] == 4)
        {
            std::cout.put(x); 
            std::cout.put(y);
        }
        else if (d[i] == 5)
        {
            std::cout.put(y);
        }
        else if (d[i] == 6)
        {
            std::cout.put(y);
            std::cout.put(x);
        }
        else
        {
            for (int j = 0; j < 10 - d[i]; ++j)
            {
                std::cout.put(x);
            }
            std::cout.put(z);
        }
    }

}

char p(int n)
{
    switch (n)
    {
    case 1:
        return 'M';
    case 2:
        return 'D';
    case 3:
        return 'C';
    case 4:
        return 'L';
    case 5:
        return 'X';
    case 6:
        return 'V';
    case 7:
        return 'I';
    }
}