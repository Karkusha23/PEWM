#include <iostream>

int main()
{
	int day, month, year;
	do
	{
		std::cout << "Input date, month and current year:" << std::endl;
		std::cin >> day;
		std::cin >> month;
		std::cin >> year;
	} while (day < 1 || day > 31 || month < 1 || month > 12 || year < 1970);
	int a = (14 - month) / 12;
	int m = month + 12 * a - 2;
	int y = year - a;
	int d = 0;
	do
	{
		++y;
		d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
	} while (d != 5);
	std::cout << y + a << std::endl;
}