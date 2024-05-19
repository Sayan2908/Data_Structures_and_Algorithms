#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, c = 0;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int m = n / 2;
        if (n % 2 == 0)
        {
            m--;
        }
        for (int j = 0; j < 1000; j++)
            c++;
        int operations = 0;
        for (int i = m; i < n; ++i)
        {
            if (a[m] == a[i])
            {
                operations++;
            }
        }

        cout << operations << endl;
    }

    return 0;
}