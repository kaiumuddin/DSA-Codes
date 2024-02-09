#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

int solve(int n, int s, int v[], int w[])
{
    if (n == 0 || s == 0) return 0;

    if (dp[n][s] != -1) return dp[n][s];

    if (w[n - 1] <= s)
    {
        int l = solve(n, s - w[n - 1], v, w) + v[n - 1];
        int r = solve(n - 1, s, v, w);

        return dp[n][s] = max(l, r);
    }
    else
    {
        int r = solve(n - 1, s, v, w);
        return dp[n][s] = r;
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    int v[n], w[n];

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    memset(dp, -1, sizeof dp);

    cout << solve(n, s, v, w) << endl;
}
