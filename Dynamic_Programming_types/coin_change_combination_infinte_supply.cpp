//////////////////////////////
//       Kaium Uddin        //
//////////////////////////////

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define nl "\n";


int hasWay(vector<int>& nums, int n, int t)
{
    if (n == 0) {
        if (t == 0) return 1;
        return 0;
    }
    if (t == 0) return 1;

    int r = hasWay(nums, n - 1, t);
    int l = false;
    if (t - nums[n - 1] >= 0)
    {
        l = hasWay(nums, n - 1, t - nums[n - 1]);
    }

    return l || r;
}

int countWaysCombinations(vector<int>& nums, int n, int t)
{
    if (n == 0) {
        if (t == 0) return 1;
        return 0;
    }

    if (t == 0) return 1;

    int notTake = countWaysCombinations(nums, n - 1, t);
    int take = 0;
    if (nums[n - 1] <= t)
    {
        take = countWaysCombinations(nums, n, t - nums[n - 1]);
    }

    return take + notTake;

    // n=3, t=7
    // 2 3 5
    // Ans = 2

    // 3 7
    // 2 3 5
    // 2
}

int countWaysPermutations(vector<int>& nums, int n, int t)
{
    if (n == 0) {
        if (t == 0) return 1;
        return 0;
    }

    if (t == 0) return 1;

    int take = 0;
    for (int c = 0; c < n; c++)
    {
        if (nums[c] <= t)
        {
            take += countWaysPermutations(nums, n, t - nums[c]);
        }
    }

    return take;

    // n=3, t=7
    // 2 3 5
    // Ans = 5

    // 3 7
    // 2 3 5
    // 5
}

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // cout << hasWay(a, n, t) << endl;
    // cout << countWaysCombinations(a, n, t) << endl;
    cout << countWaysPermutations(a, n, t) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
