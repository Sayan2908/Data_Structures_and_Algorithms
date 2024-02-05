#include <bits/stdc++.h>
using namespace std;

class Chebyshev
{
public:
    double PI = acos(-1);

    void func()
    {
    }

    vector<double> chebyshev_nodes(double n)
    {
        vector<double> cheb_nodes(n);
        for (int i = 0; i < n; i++)
        {
            cheb_nodes[i] = cos((2 * i + 1) * PI / (2 * n));
        }
        return cheb_nodes;
    }

    double cheb_Ts(double n, double x)
    {
        return cos(n * acos(x));
    }

    vector<double> cheb_coeff(double n)
    {
        vector<double> cheb_coff(n);
        vector<double> cheb_node = chebyshev_nodes(n);
        for (int i = 0; i < n; i++)
        {
            cheb_coff[0] += sin(PI * cheb_node[i]); // or whatever func
        }
        cheb_coff[0] /= n;

        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cheb_coff[j] += exp(cheb_node[k]) * cos(j * PI * (2 * k + 1) / (2 * n));
            }
            cheb_coff[j] = 2 * cheb_coff[j] / n;
        }
        return cheb_coff;
    }

    double cheb_poly(double n, double x)
    {
        vector<double> c = cheb_coeff(n);
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += c[i] * cheb_Ts(i, x);
        }
        return ans;
    }
};

class NewtonInterpolation
{
public:
    double newtonInterpolation(double x, const vector<double> &xValues, const vector<double> &yValues)
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
};

signed main()
{
    Chebyshev Obj;
    cout << Obj.cheb_poly(3, 1) << endl;
    Obj.func();
    vector<double> xValues = {1,2.0, 3.0,4,5,6,7};
    vector<double> yValues;

    for (const auto& x : xValues) {
        yValues.push_back(log(x));
    }

    NewtonInterpolation onj2;
    double xToInterpolate = 2.5;
    double result = onj2.newtonInterpolation(xToInterpolate, xValues, yValues);   
                                                                                                                                
    cout << "log(2.5) is approximately: " << result/log(10) << endl;
    return 0;
}