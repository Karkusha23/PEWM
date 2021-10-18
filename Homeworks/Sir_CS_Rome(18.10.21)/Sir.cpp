#include <iostream>

int main()
{
	int n;
	do
	{
		std::cout << "Input positive integer n: ";
		std::cin >> n;
	} while (n < 1);
	int m = 0, cnt = 0;
	do
	{
		++cnt;
		if (n > m)
		{
			m = n;
		}
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = 3 * n + 1;
		}
	} while (n > 1);
	std::cout << "Number of steps: " << cnt << "\nMax: " << m << std::endl;
}