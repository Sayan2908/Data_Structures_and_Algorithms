#include <bits/stdc++.h>
using namespace std;

double simp_mult(vector<double> &x, vector<double> &y)
{
    double ans = 0;
    for (int i = 0; i < x.size(); i++)
    {
        ans += x[i] * y[i];
    }
    return ans;
}

double sum_mul(vector<double> &x, vector<double> &y)
{
    int n = x.size();
    double ans_x=0, ans_y=0;
    for (int i = 0; i < n; i++)
    {
        ans_x += x[i];
        ans_y += y[i];
    }
    return ans_x * ans_y;
}

double sq_sum(vector<double> &x)
{
    
    double ans=0;
    for (int i = 0; i < x.size(); i++)
    {
        ans += x[i] * x[i];
    }
    return ans;
}
double sum_sq(vector<double> &x)
{
    
    double ans=0;
    for (double i = 0; i < x.size(); i++)
    {
        ans += x[i];
    }
    return ans * ans;
}

double slope(int n, vector<double> &x, vector<double> &y)
{
    return ((n * simp_mult(x, y)) - sum_mul(x, y)) / ((n * sq_sum(x)) - sum_sq(x));
}

double simp_const(int n, vector<double> &x, vector<double> &y)
{
    return (sqrt(sum_sq(y)) - slope(n, x, y) * sqrt(sum_sq(x))) / n;
}

double mean(vector<double> y)
{
    
    double ans=0;
    for (int i = 0; i < y.size(); i++)
    {

        ans += y[i];
    }
    return ans / y.size();
}

double s_t(vector<double> y)
{
    double n = y.size();
    double ans=0;
    for(double i=0;i<n;i++){
        ans += (y[i]-mean(y))*(y[i]-mean(y));
    }
    return ans;
}

double s_r(int n, vector<double> &x, vector<double> &y){
    double ans=0;
    for(int i=0;i<n;i++){
        ans += (y[i]-simp_const(n,x,y) - slope(n,x,y)*x[i])*(y[i]-simp_const(n,x,y) - slope(n,x,y)*x[i]);
    }
    return ans;
}

double fitness(int n, vector<double> &x, vector<double> &y){
    return (s_t(y) - s_r(n,x,y))/s_t(y);
}


int main()
{
    int n=5;//size of array
    vector<double> x,y;
    x = {log(1),log(2),log(3),log(4),log(5)};
    y = {log(0.5),log(2),log(4.5),log(8),log(12.5)};

    double res = fitness(5,x,y);
    cout<<res<<endl;
    return 0;
}