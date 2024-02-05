#include <bits/stdc++.h>

using namespace std;
int invpair(vector<int> a){
    int count=0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] > a[j])
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int count=0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] > a[j])
            {
                count++;
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}