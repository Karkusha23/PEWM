#include <iostream>

int main()
{
    int a, m, y, d, cnt = 0;
    for (int i = 1901; i < 2001; ++i)
    {
        for (int j = 1; j < 13; ++j)
        {
            a = (14 - j) / 12;
            m = j + (12 * a) - 2;
            y = i - a;
            d = (13 + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
            if (d == 5)
            {
                ++cnt;
            }
        }
    }
    std::cout << "Probability: " << double(cnt) / 12.0 << "%" << std::endl;
    std::cout << "Number of Fridays, 13th: " << cnt << std::endl;
}
