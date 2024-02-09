#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool solve(int n, int a[], int s)
{
    if (n == 0) {
        if (s == 0) return true;
        else return false;
    }

    if (dp[n][s] != -1) return dp[n][s];

    if (s >= a[n - 1])
    {
        bool l = solve(n - 1, a, s - a[n - 1]);
        bool r = solve(n - 1, a, s);

        return dp[n][s] = l || r;
    }
    else {
        bool r = solve(n - 1, a, s);
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

    if (solve(n, a, s)) cout << "YES" << endl;
    else cout << "NO" << endl;

    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}
