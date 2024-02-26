#include<bits/stdc++.h>

using namespace std;
double PI = acos(-1);

vector<double> chebynodes(double n){
    vector<double> nodes(n);
    for (double i=0;i<n;i++)
    {
        nodes[i] = cos((2*i+1)*PI)/(2*n);
    }
    return nodes;
}

double Tx(double n,double x){
    return cos(n*acos(x));
}

vector<double> cheby_coeff(double n)
{
    vector<double> nodes = chebynodes(n);
    vector<double> coeff(n);

    for (double i=0;i<n;i++){
        coeff[0] += sin(PI*nodes[i]);
    }
    coeff[0] /= n;

    for (double j = 1; j < n; j++)
        {
            for (double k = 0; k < n; k++)
            {
                coeff[j] += sin(PI * nodes[k]) * cos(j * PI * (2 * k + 1) / (2 * n));
            }
            coeff[j] = 2 * coeff[j] / n;
        }
        return coeff;
}

double cheby_poly(double n,double x){
    vector<double> c = cheby_coeff(n);
    double ans = 0;
    for (double i = 0; i < n; i++)
    {
        ans += c[i] * Tx(i, x);
    }
    return ans;

}

signed main()
{
    cout<<cheby_poly(3,1);
    return 0;
}