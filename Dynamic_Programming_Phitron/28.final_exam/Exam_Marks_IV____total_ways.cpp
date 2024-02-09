#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int solve(int w[], int n, int s, vector<vector<int>>& dp)
{
    if (n == 0)
    {
        if (s == 0) return 1;
        else return 0;
    }

    if (dp[n][s] != -1) return dp[n][s];

    if (w[n - 1] <= s)
    {
        int l = solve(w, n, s - w[n - 1], dp);
        int r = solve(w, n - 1, s, dp);
        return dp[n][s] = (l + r) % MOD;
    }
    else
    {
        int r = solve(w, n - 1, s, dp);
        return dp[n][s] = r % MOD;
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

        int ans = solve(w, n, s, dp);
        cout << ans << endl;

    }
}
