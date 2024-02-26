#include <bits/stdc++.h>
using namespace std;

double newton(double x, const vector<double> &xValues, const vector<double> &yValues)
{
    int n = xValues.size();
    vector<vector<double>> a(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i)
        a[i][0] = yValues[i];

    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < n - j; ++i)
        {
            a[i][j] = (a[i + 1][j - 1] - a[i][j - 1]) / (xValues[i + j] - xValues[i]);
        }
    }

    double result = a[0][0];
    double term = 1.0;

    for (int j = 1; j < n; ++j)
    {
        term *= (x - xValues[j - 1]);
        result += term * a[0][j];
    }

    return result;
}

double v(double x)
{
    double d = (7.61 * pow(10, (-19))) / 4.35974434e-18;
    double beta = 0.0193 / (1.88973e-2);
    double xo = 74.1 * (1.88973e-2);

    double ans = d * (1 - exp((-1) * beta * (x - xo))) * (1 - exp((-1) * beta * (x - xo)));
    return ans;
}

int main()
{
    double start = 0;
    double end = 8;

    vector<double> xValues(20);
    vector<double> yValues(20);

    double dx = (end - start) / 20;
    for (int i = 0; i < 20; i++)
    {
        double temp = start + i * dx;
        xValues[i] = temp;
        yValues[i] = v(temp);
    }
    double ans1 = newton(4.5, xValues, yValues);
    double ans2 = newton(6.5, xValues, yValues);

    cout << ans1 << endl;
    cout << ans2 << endl;
}