#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<vector<int>> dp(N, vector<int>(N, -1));

int solve(string a, int n, string b, int m)
{
    if (n == 0 || m == 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];

    if (a[n - 1] == b[m - 1])
    {
        int l = solve(a, n - 1, b, m - 1) + 1;
        return dp[n][m] = l;
    }
    else
    {
        int l = solve(a, n - 1, b, m);
        int r = solve(a, n, b, m - 1);

        return dp[n][m] = max(l, r);
    }
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << solve(a, a.size(), b, b.size()) << endl;
}
