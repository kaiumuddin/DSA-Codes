#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

// top down memo
// int solve(int w[], int v[], int n, int s)
// {
//     if (n == 0) return 0;

//     if (dp[n][s] != -1) return dp[n][s];

//     int ans = solve(w, v, n - 1, s);
//     if (s >= w[n - 1])
//         ans = max(ans, solve(w, v, n - 1, s - w[n - 1]) + v[n - 1]);

//     return dp[n][s] = ans;
// }

// bootom up
int solve(int w[], int v[], int n, int s)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            int ans = dp[i - 1][j];
            if (j >= w[i - 1])
                ans = max(ans, dp[i - 1][j - w[i - 1]] + v[i - 1]);
            dp[i][j] = ans;
        }
    }

    return dp[n][s];
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;

        int w[n];
        int v[n];

        for (int i = 0; i < n;i++) cin >> w[i];
        for (int i = 0; i < n;i++) cin >> v[i];

        memset(dp, -1, sizeof dp); // top down
        // memset(dp, 0, sizeof dp); // bottom up
        

        cout << solve(w, v, n, s) << endl;
    }
}
