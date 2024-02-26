#include <bits/stdc++.h>

using namespace std;

double Interpolation(double x, vector<double> xval, vector<double> yval)
{
    int n = xval.size();
    vector<vector<double>> a(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
    {
        a[i][0] = yval[i];
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n-j; i++)
        {
            a[i][j] = (a[i + 1][j - 1] - a[i][j - 1]) / (xval[j+i] - xval[i]);
        }
    }

    double result = a[0][0];
    double term = 1.0;

    for (int j = 1; j < n; ++j)
    {
        term *= (x - xval[j - 1]);
        result += term * a[0][j];
    }

    return result;
}

int main()
{
    vector<double> xValues = {1, 2.0, 3.0, 4, 5, 6, 7};
    vector<double> yValues;

    for (const auto &x : xValues)
    {
        yValues.push_back(log(x));
    }

    double xToInterpolate = 2.5;
    double result = Interpolation(xToInterpolate, xValues, yValues);

    cout << "log(2.5) is approximately: " << result / log(10) << endl;
    return 0;
}