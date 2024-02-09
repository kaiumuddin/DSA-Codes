#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        int sum = 1000 - m;
        int dp[n + 1][sum + 1];

        for (int i = 0; i <= n;i++)
        {
            for (int j = 0; j <= sum;j++)
            {
                if (i == 0 && j == 0) dp[i][j] = 0;
                else dp[i][j] = INT_MAX - 1;
            }
        }

        for (int i = 1; i <= n;i++)
        {
            for (int j = 0; j <= sum;j++)
            {
                if (a[i - 1] <= j)
                {
                    int l = dp[i][j - a[i - 1]] + 1;
                    int r = dp[i - 1][j];
                    dp[i][j] = min(l, r);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }


        if (dp[n][sum] == INT_MAX - 1) cout << -1 << endl;
        else cout << dp[n][sum] << endl;
    }
}
