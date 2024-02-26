#include <bits/stdc++.h>
using namespace std;

double newton(double x, vector<double> &xValues, vector<double> &yValues)
{
    int n = xValues.size();
    vector<vector<double>> a(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++)
    {
        a[i][0] = yValues[i];
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            a[i][j] = (a[i + 1][j - 1] - a[i][j - 1]) / (xValues[i + j] - xValues[i]);
        }
    }
    double result = a[0][0];
    double term = 1.0;

    for (int j = 1; j < n; j++)
    {
        term *= (x - xValues[j - 1]);
        result += term * a[0][j];
    }

    return result;
}

int main()
{
    vector<double> xValues;
    for (double i = 0; i <= 8; i += 0.4)
    {
        xValues.push_back(i);
    }
    vector<double> yValues;
    double y;
    for (auto x : xValues)
    {
        y = 0.17448 * pow((1 - exp(-1.0218 * (x - 1.4))), 2);
        yValues.push_back(y);
    }
    double xToInterpolate = 4.5;
    double res = newton(xToInterpolate, xValues, yValues);
    double res2 = newton(6.5, xValues, yValues);
    cout << res << endl;
    cout << res2 << endl;
    return 0;
}