#include<bits/stdc++.h>
using namespace std;

using ll = int;
ll solve1(vector<ll>& nums, int n)
{
    cout << n << " ";
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    ll incl = solve1(nums, n - 2);
    ll excl = solve1(nums, n - 1);

    if (n == nums.size()) return max(incl, excl);
    return max(incl + nums[n], excl);
}

ll solve2(vector<ll>& nums, int n, vector<int>& dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    if (dp[n] != -1)
        return dp[n];

    ll incl = solve2(nums, n - 2, dp);
    ll excl = solve2(nums, n - 1, dp);

    return dp[n] = max(incl + nums.at(n), excl);
}

ll solve3(vector<ll>& nums, ll n)
{
    vector<ll> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (i < 2)
        {
            ll incl = nums[i] + 0;
            ll excl = 0 + dp[i - 1];
            dp[i] = max(incl, excl);
        }
        else
        {
            ll incl = nums[i] + dp[i - 2];
            ll excl = 0 + dp[i - 1];
            dp[i] = max(incl, excl);
        }
    }

    return dp[n - 1];
}

ll solve4(vector<ll>& nums, ll n)
{
    ll f;
    ll f2 = 0;
    ll f1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        ll incl = nums[i] + f2;
        ll excl = 0 + f1;
        f = max(incl, excl);

        f2 = f1;
        f1 = f;
    }

    return f1;
}


int main() {
    vector<int> nums = { 1,2,4 };
    // cout << solve1(nums, nums.size() - 1) << endl;
    // cout << solve2(nums, nums.size() - 1) << endl;
    cout << solve3(nums, nums.size()) << endl;
    return 0;
}