#include <iostream>
#include <cmath>
#include <algorithm>
#include<fstream>

using namespace std;

double besselJ(int l,double x)
{
    if (l==0)
    return sin(x)/x;
    else
    return sin(x)/(x*x) - cos(x)/x;
}

double besselI(int l,double x)
{
    if(l==0)
    return -cos(x)/x;
    else
    return -cos(x)/x -sin(x)/x;
}

int main()
{
    double st=0.01,end=15,grid=100.0;
    ofstream fout("bessel.dat");
    for (int i=0;i<grid;i++)
    {
        double x = st + (end-st)*i /(grid-1);
        fout<<x<<" "<<besselJ(0,2 * x)<<" "<<besselJ(1,2*x)<<" "<<besselI(0,2*x)<<" "<<besselI(1,2*x)<<endl;
    }
    fout.close();
}