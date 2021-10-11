#include <iostream>

int main()
{
	unsigned long long n = 0, r = 0, x, y, cnt = 0;
	do
	{
		std::cout << "Input number of iterations and accuracy multiplier: " << std::endl;
		std::cin >> n;
		std::cin >> r;
	} while (n < 1);
	for (unsigned long long i = 0; i < n; ++i)
	{
		x = rand() % (r + 1);
		y = rand() % (r + 1);
		if (x * x + y * y <= r * r)
		{
			++cnt;
		}
	}
	std::cout << "Pi = " << 4.0 * double(cnt) / double(n) << std::endl;
	return 0;
}