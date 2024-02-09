#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

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

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (w[i - 1] <= j)
                {
                    int l = dp[i][j - w[i - 1]] % MOD;
                    int r = dp[i - 1][j] % MOD;
                    dp[i][j] = (l + r) % MOD;
                }
                else
                {
                    int r = dp[i - 1][j] % MOD;
                    dp[i][j] = (r) % MOD;
                }
            }
        }

        cout << dp[n][s] << endl;


    }
}
