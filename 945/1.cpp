#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        // Ensure x is the largest
        if (x < y)
            swap(x, y);
        if (x < z)
            swap(x, z);

        int moves = 0;

        // Decrease x first with y and z
        while (x > 0)
        {
            if (y > z)
            {
                if (y == 0)
                    break;
                y--;
                x--;
                moves++;
            }
            else
            {
                if (z == 0)
                    break;
                z--;
                x--;
                moves++;
            }
        }

        // Decrease y and z together
        while (y > 0 && z > 0)
        {
            y--;
            z--;
            moves++;
        }

        // Check remaining x
        if (x > 0)
        {
            if (x % 2 == 0)
            {
                cout << moves << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            return 0;
        }

        // Check parity of remaining y and z
        if (y % 2 == 0 && z % 2 == 0)
        {
            cout << moves << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}