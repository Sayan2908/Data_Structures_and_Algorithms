#include <bits/stdc++.h>
using namespace std;

vector<double> nodes(int n)
{
    int b = 5, a = -5;
    vector<double> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = cos((2 * i + 1) * acos(-1) / (2 * n)) * ((b - a) + (b + a)) / 2;
    }
    return ans;
}

double transform(double x, double a, double b)
{
    return (2 * x - (a + b)) / (b - a);
}

double cheb_T(int n, double x)
{
    return cos(n * acos(x));
}

double func(double x)
{
    return 1 / (1 + 16 * x * x);
}

vector<double> cheby_coff(int n)
{
    vector<double> chebnodes = nodes(n);
    vector<double> coff(n);
    for (int i = 0; i < n; i++)
    {
        coff[0] += func(chebnodes[i]) / n;
    }
    cout << coff[0] << endl;
    for (int j = 1; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            coff[j] += func(chebnodes[k]) * cos(j * acos(-1) * (2 * k + 1) / (2 * n));
        }
        coff[j] = 2 * coff[j] / n;
    }
    return coff;
}

double poly(int n, double x)
{
    vector<double> c = cheby_coff(n);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += c[i] * cheb_T(i, transform(x, -5, 5));
    }
    return ans;
}

int main()
{
    cout << poly(20, 1.2);
    return 0;
}