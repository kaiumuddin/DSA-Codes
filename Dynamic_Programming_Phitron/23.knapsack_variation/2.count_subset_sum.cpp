#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int solve(int n, int a[], int s)
{
    if (n == 0) {
        if (s == 0) return 1;
        else return 0;

    }

    if (dp[n][s] != -1) return dp[n][s];

    if (s >= a[n - 1])
    {
        int l = solve(n - 1, a, s - a[n - 1]);
        int r = solve(n - 1, a, s);

        return dp[n][s] = l + r;
    }
    else {
        int r = solve(n - 1, a, s);
        return dp[n][s] = r;
    }

}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++) {
        cin >> a[i];
    }

    int s;
    cin >> s;

    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << solve(n, a, s) << endl;

    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}
