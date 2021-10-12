#include <iostream>
#include <iomanip>

unsigned long long pow(int x, int n);
bool dig(double a, double b, int n);
int mone(int n);

int main()
{
	double a = 4.0, b;
	int n = 0;
	unsigned long long cnt = 0, cnt2 = 0, r = 0, x, y;
	std::cout << "Input number of digits after point and radius of sircle:" << std::endl;
	std::cin >> n;
	std::cin >> r;
	do
	{
		b = a;
		++cnt;
		a += mone(cnt) * 4.0 / (2.0 * double(cnt) + 1.0);
	} while (dig(a, b, n));
	++cnt;
	std::cout << "Pi = " << std::setprecision(n + 1) << a << std::endl;
	std::cout << "Number of iterations: " << cnt << std::endl;
	for (unsigned long long i = 0; i < cnt; ++i)
	{
		x = rand() % (r + 1);
		y = rand() % (r + 1);
		if (x * x + y * y <= r * r)
		{
			++cnt2;
		}
	}
	std::cout << "Pi = " << std::setprecision(n + 1) << 4.0 * double(cnt2) / double(cnt) << std::endl;
	return 0;
}

unsigned long long pow(int x, int n)
{
	unsigned long long r = 1;
	for (int i = 0; i < n; ++i)
	{
		r *= x;
	}
	return r;
}

bool dig(double a, double b, int n)
{
	if (unsigned long long(a * pow(10, n)) == unsigned long long(b * pow(10, n)))
	{
		return false;
	}
	else
	{
		return true;
	}
}

int mone(int n)
{
	if (n % 2 == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}