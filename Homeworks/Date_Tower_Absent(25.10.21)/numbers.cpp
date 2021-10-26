#include <iostream>
#include <clocale>

int p(int n);

inline void prt_eng(int d[3][3]);
inline void prt_eng_ran(int n);
inline void prt_eng_ten(int n);
inline void prt_eng_dec(int n);
inline void prt_eng_dig(int n);

inline void prt_rus(int d[3][3]);
inline void prt_rus_ran(int n);
inline void prt_rus_hun(int n);
inline void prt_rus_dec(int n);
inline void prt_rus_ten(int n);
inline void prt_rus_dig(int n);

int main()
{
    int n, lan;
    do
    {
        std::cout << "Select language (1.Eng 2.Rus) and input number:" << std::endl;
        std::cin >> lan;
        std::cin >> n;
    } while (n < 1 || n > p(9) || lan < 1 || lan > 2);
    if (n == p(9))
    {
        if (lan == 1)
        {
            std::cout << "one billion" << std::endl;
        }
        else
        {
            setlocale(LC_CTYPE, "rus");
            std::cout << "один миллиард" << std::endl;
        }
        return 0;
    }
    int d[3][3] = { {(n % p(9)) / p(8), (n % p(8)) / p(7), (n % p(7)) / p(6)}, {(n % p(6)) / p(5), (n % p(5)) / p(4), (n % p(4)) / p(3)}, {(n % p(3)) / p(2), (n % p(2)) / p(1), n % 10} };
    if (lan == 1)
    {
        prt_eng(d);
    }
    else
    {
        setlocale(LC_CTYPE, "rus");
        prt_rus(d);
    }
}

int p(int n)
{
    int res = 1;
    for (int i = 0; i < n; ++i)
    {
        res *= 10;
    }
    return res;
}

inline void prt_eng(int d[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        if (d[i][0] + d[i][1] + d[i][2] == 0)
        {
            continue;
        }
        if (d[i][0] > 0)
        {
            prt_eng_dig(d[i][0]);
            std::cout << " hundred ";
            if (d[i][1] + d[i][2] > 0)
            {
                std::cout << "and ";
            }
        }
        if (d[i][1] > 1)
        {
            prt_eng_dec(d[i][1]);
            if (d[i][2] > 0)
            {
                std::cout << '-';
                prt_eng_dig(d[i][2]);
            }
        }
        else if (d[i][1] == 1)
        {
            prt_eng_ten(d[i][2]);
        }
        else
        {
            prt_eng_dig(d[i][2]);
        }
        prt_eng_ran(i);
    }
}

inline void prt_eng_ran(int n)
{
    switch (n)
    {
    case 0:
        std::cout << " million "; break;
    case 1:
        std::cout << " thousand "; break;
    }
}

inline void prt_eng_ten(int n)
{
    switch (n)
    {
    case 0:
        std::cout << "ten"; break;
    case 1:
        std::cout << "eleven"; break;
    case 2:
        std::cout << "twelve"; break;
    case 3:
        std::cout << "thirteen"; break;
    case 4:
        std::cout << "fourteen"; break;
    case 5:
        std::cout << "fifteen"; break;
    case 6:
        std::cout << "sixteen"; break;
    case 7:
        std::cout << "seventeen"; break;
    case 8:
        std::cout << "eighteen"; break;
    case 9:
        std::cout << "nineteen"; break;
    }
}

inline void prt_eng_dec(int n)
{
    switch (n)
    {
    case 2:
        std::cout << "twenty"; break;
    case 3:
        std::cout << "thirty"; break;
    case 4:
        std::cout << "fourty"; break;
    case 5:
        std::cout << "fifty"; break;
    case 6:
        std::cout << "sixty"; break;
    case 7:
        std::cout << "seventy"; break;
    case 8:
        std::cout << "eighty"; break;
    case 9:
        std::cout << "ninety"; break;
    }
}

inline void prt_eng_dig(int n)
{
    switch (n)
    {
    case 1:
        std::cout << "one"; break;
    case 2:
        std::cout << "two"; break;
    case 3:
        std::cout << "three"; break;
    case 4:
        std::cout << "four"; break;
    case 5:
        std::cout << "five"; break;
    case 6:
        std::cout << "six"; break;
    case 7:
        std::cout << "seven"; break;
    case 8:
        std::cout << "eight"; break;
    case 9:
        std::cout << "nine"; break;
    }
}

inline void prt_rus(int d[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        if (d[i][0] + d[i][1] + d[i][2] == 0)
        {
            continue;
        }
        prt_rus_hun(d[i][0]);
        if (d[i][1] == 1)
        {
            prt_rus_ten(d[i][2]);
        }
        else
        {
            prt_rus_dec(d[i][1]);
            if (i == 1 && d[i][2] < 3)
            {
                prt_rus_dig(d[i][2] + 10);
            }
            else
            {
                prt_rus_dig(d[i][2]);
            }
        }
        if (d[i][1] == 1 || d[i][2] > 4 || d[i][2] == 0)
        {
            prt_rus_ran(i);
        }
        else if (d[i][2] == 1)
        {
            prt_rus_ran(i + 3);
        }
        else
        {
            prt_rus_ran(i + 6);
        }
    }
}

inline void prt_rus_ran(int n)
{
    switch (n)
    {
    case 0:
        std::cout << "миллионов "; break;
    case 1:
        std::cout << "тысяч "; break;
    case 3:
        std::cout << "миллион "; break;
    case 4:
        std::cout << "тысяча "; break;
    case 6:
        std::cout << "миллиона "; break;
    case 7:
        std::cout << "тысячи "; break;
    }
}

inline void prt_rus_hun(int n)
{
    switch (n)
    {
    case 1:
        std::cout << "сто "; break;
    case 2:
        std::cout << "двести "; break;
    case 3:
        std::cout << "триста "; break;
    case 4:
        std::cout << "четыреста "; break;
    case 5:
        std::cout << "пятьсот "; break;
    case 6:
        std::cout << "шестьсот "; break;
    case 7:
        std::cout << "семьсот "; break;
    case 8:
        std::cout << "восемьсот "; break;
    case 9:
        std::cout << "девятьсот "; break;
    }
}

inline void prt_rus_dec(int n)
{
    switch (n)
    {
    case 2:
        std::cout << "двадцать "; break;
    case 3:
        std::cout << "тридцать "; break;
    case 4:
        std::cout << "сорок "; break;
    case 5:
        std::cout << "пятьдесят "; break;
    case 6:
        std::cout << "шестьдесят "; break;
    case 7:
        std::cout << "семьдесят "; break;
    case 8:
        std::cout << "восемьдесят "; break;
    case 9:
        std::cout << "девяносто "; break;
    }
}

inline void prt_rus_ten(int n)
{
    switch (n)
    {
    case 0:
        std::cout << "десять"; break;
    case 1:
        std::cout << "одиннадцать "; break;
    case 2:
        std::cout << "двенадцать "; break;
    case 3:
        std::cout << "тринадцать "; break;
    case 4:
        std::cout << "четырнадцать "; break;
    case 5:
        std::cout << "пятнадцать "; break;
    case 6:
        std::cout << "шестнадцать "; break;
    case 7:
        std::cout << "семнадцать "; break;
    case 8:
        std::cout << "восемнадцать "; break;
    case 9:
        std::cout << "девятнадцать "; break;
    }
}

inline void prt_rus_dig(int n)
{
    switch (n)
    {
    case 1:
        std::cout << "один "; break;
    case 2:
        std::cout << "два "; break;
    case 3:
        std::cout << "три "; break;
    case 4:
        std::cout << "четыре "; break;
    case 5:
        std::cout << "пять "; break;
    case 6:
        std::cout << "шесть "; break;
    case 7:
        std::cout << "семь "; break;
    case 8:
        std::cout << "восемь "; break;
    case 9:
        std::cout << "девять "; break;
    case 11:
        std::cout << "одна "; break;
    case 12:
        std::cout << "две "; break;
    }
}