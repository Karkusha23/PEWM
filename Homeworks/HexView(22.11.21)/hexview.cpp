#include <iostream>
#include <fstream>

void makezero(int[16]);
void writefullrow(std::ofstream&, int[16], int);
void writedigit(std::ofstream&, int);
void writeindent(std::ofstream&, int);
void writetable(std::ofstream&, int[16]);
void writerow(std::ofstream&, int[16]);

int main()
{
	const char* ifname = "input.txt";
	const char* ofname = "output.txt";
	std::ifstream infile(ifname, std::ios_base::binary);
	if (!infile)
	{
		std::cout << "Can not open file to read" << std::endl;
		return 1;
	}
	std::ofstream outfile(ofname, std::ios_base::binary);
	if (!outfile)
	{
		infile.close();
		std::cout << "Can not open file to write" << std::endl;
		return 2;
	}
	int a[16];
	makezero(a);
	int ch, i = -1, cnt = -1;
	while ((ch = infile.get()) != EOF)
	{
		++i;
		a[i] = ch;
		if (i == 15)
		{
			++cnt;
			i = -1;
			writefullrow(outfile, a, cnt);
			makezero(a);
		}
	}
	++cnt;
	writefullrow(outfile, a, cnt);
	std::cout << "Done." << std::endl;
	infile.close();
	outfile.close();
	return 0;
}

void makezero(int a[16])
{
	for (int i = 0; i < 16; ++i)
	{
		a[i] = -2;
	}
}

void writefullrow(std::ofstream& of, int a[16], int cnt)
{
	writeindent(of, cnt);
	of << ":  ";
	writetable(of, a);
	of << "  ";
	writerow(of, a);
	of << std::endl;
}

void writedigit(std::ofstream& of, int n)
{
	if (n < 10)
	{
		of.put('0' + n);
	}
	else
	{
		of.put('A' + n - 10);
	}
}

void writeindent(std::ofstream& of, int n)
{
	int x = n, k = 0;
	while (x)
	{
		++k;
		x >>= 4;
	}
	k = k > 0 ? k - 1 : 0;
	for (int i = 0; i < 8 - k; ++i)
	{
		of.put('0');
	}
	k = 1 << (4 * k);
	x = n;
	int d;
	while (k)
	{
		d = x / k;
		writedigit(of, d);
		x %= k;
		k >>= 4;
	}
	of.put('0');
}

void writetable(std::ofstream& of, int a[16])
{
	for (int i = 0; i < 8; ++i)
	{
		if (a[i] == -2)
		{
			of << "   ";
		}
		else
		{
			writedigit(of, a[i] >> 4);
			writedigit(of, a[i] % 16);
			of.put(' ');
		}
	}
	of << " |  ";
	if (a[8] != -2)
	{
		for (int i = 8; i < 16; ++i)
		{
			if (a[i] == -2)
			{
				of << "   ";
			}
			else
			{
				writedigit(of, a[i] >> 4);
				writedigit(of, a[i] % 16);
				of.put(' ');
			}
		}
	}
}

void writerow(std::ofstream& of, int a[16])
{
	for (int i = 0; i < 16; ++i)
	{
		if (a[i] == -2)
		{
			return;
		}
		if (a[i] < 32)
		{
			of.put(' ');
		}
		else
		{
			of.put(a[i]);
		}
	}
}