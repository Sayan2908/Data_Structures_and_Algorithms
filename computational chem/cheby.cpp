#include <bits/stdc++.h>
using namespace std;

class Interpolation
{
public:
    double Newtonian(double x, const vector<double> &xVal, const vector<double> &yVal)
    {
        int n = xVal.size();
        vector<vector<double>> a(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; ++i)
        {
            a[i][0] = yVal[i];
        }

        for (int j = 1; j < n; ++j)
        {
            for (int i = 0; i < n - j; ++i)
            {
                a[i][j] = (a[i + 1][j - 1] - a[i][j - 1]) / (xVal[i + j] - xVal[i]);
            }
        }

        double res = a[0][0];
        double t = 1.0;

        for (int j = 1; j < n; ++j)
        {
            t *= (x - xVal[j - 1]);
            res += t * a[0][j];
        }

        return res;
    }
};

int main()
{

    vector<double> xVal;

    for (double i = 0; i <= 8; i += 0.4)
    {
        xVal.push_back(i);
    }

    vector<double> yVal;
    double y;
    for (auto x : xVal)
    {
        y = 0.17448 * pow((1 - exp(-1.0218 * (x - 1.4))), 2);
        yVal.push_back(y);
    }

    Interpolation obj2;
    double xToInterpolate = 4.5;
    double res = obj2.Newtonian(xToInterpolate, xVal, yVal);
    double res2 = obj2.Newtonian(6.5, xVal, yVal);

    cout << "Value for 4.5 is approximately: " << res << endl;
    cout << "Value for 6.5 is approximately: " << res2 << endl;
    return 0;
}