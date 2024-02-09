#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b, int n, int m, vector<vector<int>>& dp)
{
    if (n == 0 || m == 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];

    if (a[n - 1] == b[m - 1])
    {
        return dp[n][m] = solve(a, b, n - 1, m - 1, dp) + 1;
    }
    else
    {
        int l = solve(a, b, n - 1, m, dp);
        int r = solve(a, b, n, m - 1, dp);
        return dp[n][m] = max(l, r);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int lcs = solve(a, b, n, m, dp);

        cout << n + m - lcs << endl;
    }
}
