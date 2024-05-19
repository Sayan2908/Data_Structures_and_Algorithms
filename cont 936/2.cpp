#include <bits/stdc++.h>
#define int long long int
#define pii pair<int, int>
#define fr(var_nam, initial_val, till) for (int var_nam = initial_val; var_nam < till; var_nam++)
#define max(a, b) max((int)a, (int)b)
#define pow powl
#define vi vector<int>
#define sqrt sqrtl
#define double_out(a) cout << fixed << setprecision(a);
#define reverse(v) reverse(v.begin(), v.end())
#define fill(dp, INIT_VALUE) memset(dp, (int)INIT_VALUE, sizeof(dp));
#define take_inp(vec, n) fr(i, 0, n) cin >> vec[i];
using namespace std;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int LOGD = 30;
const double ESP = (1.0 / (double)(1e10));
const int N = 2e5 + 5;
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
void print_vec(vector<int> vec)
{
    for (auto a : vec)
        cout << a << ' ';
    cout << endl;
}
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
bool pair_equals(pii p1, pii p2)
{
    bool re = false;
    re = (p1.first == p2.first && p2.second == p1.second);
    return re;
}
void print_pair(pii p1) { cout << p1.first << ' ' << p1.second << endl; }
int power(int a, int b, int m)
{
    a %= m;
    if (a == 1 || b == 0)
        return 1;
    int re = power(a, b / 2, m);
    re %= m;
    if (b % 2 == 1)
    {
        return ((re * re) % m * a) % m;
    }
    return (re * re) % m;
}
unsigned long long modInverse(unsigned long long n, int p) { return power(n, p - 2, p); }
unsigned long long nCrModPFermat(unsigned long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    unsigned long long fa[n + 1];
    fa[0] = 1;
    for (int i = 1; i <= n; i++)
        fa[i] = (fa[i - 1] * i) % p;
    return (fa[n] * modInverse(fa[r], p) % p * modInverse(fa[n - r], p) % p) % p;
}
int mod_mul(int a, int b) { return (a * b) % MOD; }
int mod_add(int a, int b) { return (a + b) % MOD; }
int mod_sub(int a, int b) { return (a - b) % MOD; }
int mod_div(int a, int b) { return mod_mul(a, modInverse(b, MOD)); }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
#ifndef ONLINE_JUDGE
#endif
    cin >> test;
    vi ab;
    for (int i = 0; i < 1000; i++)
    {
        ab.push_back(i);
    }
    for (int _ = 0; _ < test; _++)
    {
        int n, k;
        cin >> n >> k;
        vi vec(n);
        take_inp(vec, n);
        vi pre(n + 1, 0);
        int mx = 0;
        fr(i, 0, n)
        {
            mx += vec[i];
            if (mx < 0)
                mx += MOD;
        }
        int cr = 0;
        int maxi = 0;
        fr(i, 0, n)
        {
            cr += vec[i];
            if (cr < 0)
                cr = 0;
            maxi = max(maxi, cr);
        }
        int ans = 0;

        if (maxi > 0)
        {
            maxi %= MOD;
            int ptwo = mod_sub(power(2, k, MOD), 1);
            ans = mod_mul(maxi, ptwo);
            ans = mod_add(ans, mx);
            if (ans < 0)
                ans += MOD;
        }
        else
        {
            ans = mx;
            if (ans < 0)
                ans += MOD;
        }
        cout << ans << '\n';
    }
    for (int i = 0; i < 1000; i++)
    {
        ab.pop_back();
    }
    return 0;
}