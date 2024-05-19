#include <bits/stdc++.h>
#include <fstream>

using namespace std;

const double dt = 0.0001;
const double dx = 0.01;
const double sigma = 0.1;
const double k = 20.0;
const double x0 = 5.0;
const double V = 0;
const double alpha = 20;
const int num_time_steps = 300;
const vector<int> plot_times = {0, 150, 300};

vector<complex<double>> psiMaker(const vector<double> &x)
{
    int n = x.size();
    vector<complex<double>> psi(n);
    for (int i = 0; i < n; i++)
    {
        psi[i] = pow(2 * alpha / M_PI, 0.25) * exp(-pow(x[i] - x0, 2) / (2 * sigma * sigma)) * exp(1i * k * x[i]);
    }
    return psi;
}

complex<double> f(const vector<complex<double>> &psi, int i, double dx)
{
    complex<double> dpsi_dx2 = (psi[(i + 1) % psi.size()] + psi[(i - 1 + psi.size()) % psi.size()] - 2.0 * psi[i]) / (dx * dx);
    return 1i * (1.0 / (2.0 * 1.0) * dpsi_dx2 - V * psi[i]);
}

int main()
{
    vector<double> x;
    for (double i = 0; i <= 10; i += 0.01)
    {
        x.push_back(i);
    }

    vector<complex<double>> psi = psiMaker(x);
    // vector<complex<double>> psi1(x.size()),psi2(x.size()),psi3(x.size());
    vector<complex<double>> slope1(x.size()), slope2(x.size()), slope3(x.size()), slope4(x.size());
    vector<vector<double>> psi_squared(plot_times.size(), vector<double>(x.size()));
    int idx = 0;

    for (int t = 0; t <= 300; t++)
    {
        // for (int i = 0; i < x.size(); i++) {
        //     vector<complex<double>> psi1(psi), psi2(psi), psi3(psi);
        //     slope1[i] = f(psi, i, 0.01);
        //     for(int j=0;j<x.size();j++) psi1[j]=psi[j]+0.5*dt*slope1[i];
        //     slope2[i] = f(psi1, i, 0.01);
        //     for(int j=0;j<x.size();j++) psi2[j]=psi[j]+0.5*dt*slope2[i];
        //     slope3[i] = f(psi2, i, 0.01);
        //     for(int j=0;j<x.size();j++) psi3[j]=psi[j]+dt*slope3[i];
        //     slope4[i] = f(psi3, i, 0.01);
        //     psi[i] += (slope1[i] + 2.0 * slope2[i] + 2.0 * slope3[i] + slope4[i]) * dt / 6.0;
        // }
        vector<complex<double>> psi1(psi), psi2(psi), psi3(psi);
        for (int i = 0; i < x.size(); i++)
        {
            slope1[i] = f(psi, i, dx);
        }
        for (int i = 0; i < x.size(); i++)
            psi1[i] = psi[i] + slope1[i] * dt * 0.5;
        for (int i = 0; i < x.size(); i++)
            slope2[i] = f(psi1, i, dx);
        for (int i = 0; i < x.size(); i++)
            psi2[i] = psi[i] + slope2[i] * dt * 0.5;
        for (int i = 0; i < x.size(); i++)
            slope3[i] = f(psi2, i, dx);
        for (int i = 0; i < x.size(); i++)
            psi3[i] = psi[i] + slope3[i] * dt;
        for (int i = 0; i < x.size(); i++)
            slope4[i] = f(psi3, i, dx);

        for (int i = 0; i < x.size(); i++)
            psi[i] += (slope1[i] + 2.0 * slope2[i] + 2.0 * slope3[i] + slope4[i]) * dt / 6.0;

        if (t == 0 || t == 150 || t == plot_times[2])
        {
            // for (int i = 0; i < x.size(); i++)cout<<pow(abs(psi[i]),2)<<endl;
            for (int i = 0; i < x.size(); i++)
            {
                psi_squared[idx][i] = pow(abs(psi[i]), 2);
            }
            idx++;
        }
    }

    ofstream out("out.txt");
    for (int i = 0; i < x.size(); i++)
    {
        out << x[i] << " " << psi_squared[0][i] << " " << psi_squared[1][i] << " " << psi_squared[2][i] << endl;
        // cout<<x[i]<<endl;
    }
    cout << "Hello";
    out.close();

    return 0;
}