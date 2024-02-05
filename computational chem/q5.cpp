#include <bits/stdc++.h>
using namespace std;

double newtonInterpolation(double x, const vector<double>& xValues, const vector<double>& yValues) {
    int n = xValues.size();
    vector<vector<double>> dividedDifferences(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        dividedDifferences[i][0] = yValues[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            dividedDifferences[i][j] = (dividedDifferences[i + 1][j - 1] - dividedDifferences[i][j - 1]) / (xValues[i + j] - xValues[i]);
        }
    }

    double result = dividedDifferences[0][0];
    double term = 1.0;

    for (int j = 1; j < n; ++j) {
        term *= (x - xValues[j - 1]);
        result += term * dividedDifferences[0][j];
    }

    return result;
}

int main() {
    vector<double> xValues = {2.0, 3.0};
    vector<double> yValues;

    for (const auto& x : xValues) {
        yValues.push_back(log(x));
    }

    double xToInterpolate = 2.5;
    double result = newtonInterpolation(xToInterpolate, xValues, yValues);                                                                                                                                                                         
                                                                                                                                                                                                                                                    // result = log(2.5)/log(10);
    // Display the result
    cout << "log(2.5) is approximately: " << result << endl;

    return 0;
}
