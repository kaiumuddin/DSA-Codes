#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int w[n];
    for (int i = 0; i < n;i++)
    {
        cin >> w[i];
    }

    int s;
    cin >> s;

    int dp[n + 1][s + 1];
    dp[0][0] = 0;

    for (int i = 1; i <= s; i++)
        dp[0][i] = INT_MAX - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                int l = dp[i][j - w[i - 1]] + 1;
                int r = dp[i - 1][j];

                dp[i][j] = min(l, r);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][s] << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

// 3
// 1 2 3
// 5
