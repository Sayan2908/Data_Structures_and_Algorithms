#include <bits/stdc++.h>
#define ll long long

using namespace std;

int umapSayanain()
{
    int Tes;
    cin >> Tes;
    while (Tes--)
    {
        ll nSay;
        cin >> nSay;
        vector<ll> a(nSay);
        map<ll, ll> umapSayan;
        for (int i = 0; i < nSay; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < nSay; i++)
        {
            ll ax;
            cin >> ax;
            umapSayan[a[i]] = ax;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < nSay; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < nSay; i++)
        {
            cout << umapSayan[a[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}