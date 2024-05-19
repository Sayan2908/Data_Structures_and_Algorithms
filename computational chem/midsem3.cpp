#include <bits/stdc++.h>
using namespace std;

class TunnellingProblem
{
public:
    double dx = 0.01;
    double hbar = 1;
    double m = 1;

    double V(double x)
    {
        if (x <= 4.5)
        {
            return 9 * exp(-pow((x - 4.5) / 0.6, 2));
        }
        else
        {
            return 5 * exp(-pow((x - 4.5) / 0.6, 2)) + 4;
        }
    }

    vector<complex<double>> solve_schrodinger(double E)
    {
        int N = static_cast<int>(10 / dx) + 1;
        vector<complex<double>> psi(N, complex<double>(0, 0));
        double k = sqrt(2 * m * (E - V(0)) / pow(hbar, 2));
        psi[0] = complex<double>(1, 0);
        psi[1] = exp(complex<double>(0, -k * dx));

        for (int j = 1; j < N - 1; ++j)
        {
            psi[j + 1] = (2 - 2 * m * (E - V(j * dx)) * pow(dx, 2) / pow(hbar, 2)) * psi[j] - psi[j - 1];
        }

        return psi;
    }

    double cal_trans_probability(double E)
    {
        vector<complex<double>> psi = solve_schrodinger(E);
        double maxi = INT32_MIN;
        double mini = INT32_MAX;
        for (int j = 601; j < psi.size(); j++)
        {
            maxi = max(maxi, abs(psi[j]));
            mini = min(mini, abs(psi[j]));
        }
        double pavg = (maxi * maxi + mini * mini) / 2;
        return 2 / (1 + pavg);
    }

    double classical_trans(double E)
    {
        if (E > 9)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};