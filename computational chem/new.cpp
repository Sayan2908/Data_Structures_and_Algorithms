#include <bits/stdc++.h>

using namespace std;

vector<double> cheb_n(int n)
{
    vector<double> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = cos(((2 * i + 1) * acos(-1)) / (2 * n));
    }
    return ans;
}

double cheb_T(int n, double x)
{
    return cos(n * acos(x));
}

vector<double> cheb_coff(int n)
{
    vector<double> nodes = cheb_n(n);
    vector<double> coff(n);

    for (int i = 0; i < n; i++)
    {
        coff[0] += sin(acos(-1) * nodes[i]) / n;
    }

    for (int j = 1; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            coff[j] += sin(acos(-1) * nodes[k]) * cos(j * acos(-1) * (2 * k + 1) / (2 * n));
        }
        coff[j] = 2 * coff[j] / n;
    }
    return coff;
}

double poly(int n, double x)
{
    vector<double> c = cheb_coff(n);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += c[i] * cheb_T(i, x);
    }
    return ans;
}

int main()
{
    cout << poly(3, 1);
    return 0;
}