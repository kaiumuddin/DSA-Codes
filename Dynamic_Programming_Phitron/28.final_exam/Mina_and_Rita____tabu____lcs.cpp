#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b, int n, int m, vector<vector<int>>& dp)
{
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                int l = dp[i - 1][j];
                int r = dp[i][j - 1];
                dp[i][j] = max(l, r);
            }
        }
    }

    return dp[n][m];
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
