#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        int s = 0;
        s = p1 + p2 + p3;
        if (s % 2 != 0)
            cout << "-1/n";
        int a = min(p1, p2, p3);
        int b = max(min(p1, p2), min(p2, p3), min(p1, p3));
        if ((a + b) <= (s / 2))
            cout << (a + b) << endl;
        else
            cout << s / 2 << endl;
    }
    return 0;
}