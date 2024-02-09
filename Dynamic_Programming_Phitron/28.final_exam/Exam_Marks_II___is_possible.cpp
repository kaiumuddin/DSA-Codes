#include<bits/stdc++.h>
using namespace std;

bool solve(int n, int s, int w[], vector<vector<int>>& dp)
{
    if (n == 0)
    {
        if (s == 0) return true;
        else return false;
    }

    if (dp[n][s] != -1) return dp[n][s];

    if (w[n - 1] <= s)
    {
        int l = solve(n, s - w[n - 1], w, dp);
        int r = solve(n - 1, s, w, dp);
        return dp[n][s] = l || r;
    }
    else
    {
        int r = solve(n - 1, s, w, dp);
        return dp[n][s] = r;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int w[n];

        for (int i = 0; i < n; i++) cin >> w[i];

        int s = 1000 - m;
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));

        if (solve(n, s, w, dp))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
