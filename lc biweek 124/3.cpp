#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int sum, int left, int right, vector<int> &a, vector<vector<int>> &dp)
    {

        if (left >= right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;

        if (left + 1 <= right && a[left] + a[left + 1] == sum)
        {
            ans1 = 1 + solve(sum, left + 2, right, a, dp);
        }

        if (right - 1 >= left && a[right] + a[right - 1] == sum)
        {
            ans2 = 1 + solve(sum, left, right - 2, a, dp);
        }

        if (a[left] + a[right] == sum)
        {
            ans3 = 1 + solve(sum, left + 1, right - 1, a, dp);
        }

        return dp[left][right] = max(ans1, max(ans2, ans3));
    }
    int maxOperations(vector<int> &a)
    {

        int n = a.size();

        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        vector<int> v4;
        vector<int> v5;
        vector<int> v6;

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        vector<vector<int>> dp3(n, vector<int>(n, -1));

        for (int left = 0; left < n - 2; left++)
            v2.push_back(a[left]);
        for (int left = 1; left < n - 1; left++)
            v3.push_back(a[left]);
        for (int left = 2; left < n; left++)
            v1.push_back(a[left]);
        for (int left = 1; left < n; left++)
            v5.push_back(a[left]);
        for (int left = 0; left < n - 1; left++)
            v4.push_back(a[left]);

        for (int left = 0; left < n - 1; left++)
            v6.push_back(a[left]);
        for (int left = 0; left < n - 2; left++)
            v3.pop_back();
        for (int left = 0; left < n - 2; left++)
            v4.pop_back();
        for (int left = 0; left < n - 2; left++)
            v2.pop_back();
        for (int left = 0; left < n - 2; left++)
            v5.pop_back();
        for (int left = 0; left < n - 2; left++)
            v6.pop_back();
        for (int left = 0; left < n - 2; left++)
            v1.pop_back();

        int ans1 = solve((a[0] + a[1]), 2, n - 1, a, dp1);
        int ans2 = solve((a[n - 1] + a[n - 2]), 0, n - 3, a, dp2);
        int ans3 = solve((a[0] + a[n - 1]), 1, n - 2, a, dp3);

        return 1 + max(ans1, max(ans2, ans3));
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << "Maximum number of operations that can be performed are: " << sol.maxOperations(nums) << "\n";
    return 0;
}