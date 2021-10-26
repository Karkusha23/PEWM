#include <iostream>

int main()
{
	int n;
	do
	{
		std::cout << "Input room number: ";
		std::cin >> n;
	} while (n < 1);
	int k = 1, s = 0;
	do
	{
		s += k * k;
		++k;
	} while (s < n);
	--k;
	s -= k * k;
	int fl = (k * (k - 1)) / 2, rm = 0;
	bool m = false;
	for (int i = 1; i <= k; ++i)
	{
		++fl;
		for (int j = 1; j <= k; ++j)
		{
			++s;
			if (s == n)
			{
				rm = j;
				m = true;
				break;
			}
		}
		if (m)
		{
			break;
		}
	}
	std::cout << "Floor: " << fl << std::endl;
	std::cout << "Room: " << rm << std::endl;
}
