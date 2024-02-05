#include <bits/stdc++.h>
using namespace std;

double lagrangeInterpolation(double x, vector<double> &xValues, vector<double> &yValues)
{
    double result = 0.0;

    for (int i = 0; i < xValues.size(); i++)
    {
        double term = yValues[i];
        for (int j = 0; j < xValues.size(); j++)
        {
            if (j != i)
            {
                term = term * (x - xValues[j]) / (xValues[i] - xValues[j]);
            }
        }
        result += term;
    }

    return result;
}

int main()
{
    // Data points
    vector<double> xValues = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> yValues = {1.0, 1.414, 1.732, 2, 2.236};

    // for (auto& x : xValues) {
    //     yValues.push_back(log(x));  // log function for y values
    // }

    // Calculate sqrt(log(2.5)) using Lagrange interpolation
    double xToInterpolate = 2.5;
    double result = lagrangeInterpolation(xToInterpolate, xValues, yValues);

    cout << "sqrt(log(2.5)) is approximately: " << result/log10(10) << endl;

    return 0;
}
