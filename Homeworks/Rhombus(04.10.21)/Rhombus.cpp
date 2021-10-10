#include <iostream>

void draw(int m, int n, int i);

int main()
{
	int m = 0, n = 0;
	do
	{
		std::cout << "Input width and high in range [1; 11]:" << std::endl;
		std::cin >> m;
		std::cin >> n;
	} while (n > 11 || n < 1 || m > 11 || m < 1);
	for (int i = 1; i <= n; ++i)
	{
		draw(m, n, i);
	}
	for (int i = n - 1; i >= 1; --i)
	{
		draw(m, n, i);
	}
	system("pause");
	return 0;
}

void draw(int m, int n, int i)
{
	for (int j = 1; j <= m; ++j)
	{
		for (int k = 1; k <= n - i; ++k)
		{
			std::cout << ' ';
		}
		for (int k = 1; k <= 2 * i - 1; ++k)
		{
			std::cout << '*';
		}
		for (int k = 1; k <= n - i; ++k)
		{
			std::cout << ' ';
		}
	}
	std::cout << std::endl;
}