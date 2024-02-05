#include <bits/stdc++.h>

using namespace std;
int fac(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fac(n - 1);
}

double j(int p, double x)
{
    if (x <= 0.2)
        return pow(x, p) / fac(p);
    else if (p == 0)
    {
        double temp = sin(x) / x;
        return temp;
    }
    else if (p == 1)
    {
        double temp = (sin(x) / pow(x, 2)) - cos(x) / x;
        return temp;
    }
    else
    {
        double temp = (2 * p - 1) * j(p - 1, x) / x - j(p - 2, x);
        return temp;
    }
}

double n(int p, double x)
{
    if (p == 0)
    {
        double temp = -cos(x) / x;
        return temp;
    }
    else if (p == 1)
    {
        double temp = (-cos(x) / pow(x, 2)) - sin(x) / x;
        return temp;
    }
    else
    {
        double temp = (2 * p - 1) * n(p - 1, x) / x - n(p - 2, x);
        return temp;
    }
}

double h(int p, double x)
{
    return j(p, x) + n(p, x);
}

int main()
{
    double st = 0.01, end = 15, grid = 100.0;
    ofstream fout("cheat.dat");
    for (int i = 0; i < grid; i++)
    {
        double x = st + (end - st) * i / (grid - 1);
        fout << x << " " << j(4, x) << endl;
    }
    fout << endl
         << endl;
    for (int i = 0; i < grid; i++)
    {
        double x = st + (end - st) * i / (grid - 1);
        fout << x << " " << n(4, x) << endl;
    }
    fout.close();
    return 0;
}