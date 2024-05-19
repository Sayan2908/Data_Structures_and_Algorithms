#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

int build(int node, int low, int high, vector<int> &nums)
{
    if (low == high)
        return tree[node] = nums[low];
    int mid = low + high >> 1;
    return tree[node] = build(node << 1, low, mid, nums) | build(node << 1 | 1, mid + 1, high, nums);
}

int q(int node, int low, int high, int ql, int qr)
{
    if (low > qr || high < ql)
        return 0;
    if (low >= ql && high <= qr)
        return tree[node];
    int mid = low + high >> 1;
    return q(node << 1, low, mid, ql, qr) | q(node << 1 | 1, mid + 1, high, ql, qr);
}

int F(int n, vector<int> &nums)
{
    auto good = [&](int len)
    {
        for (int i = len; i < n; i++)
        {
            if (q(1, 0, n - 1, i - len, i - 1) != q(1, 0, n - 1, i - len + 1, i))
                return false;
        }
        return true;
    };
    int ans = n;
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + high >> 1;
        if (good(mid))
            high = mid - 1, ans = mid;
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &num : nums)
            cin >> num;
        tree.resize(n << 2, 0);
        build(1, 0, n - 1, nums);
        cout << F(n, nums) << endl;
    }
    return 0;
}