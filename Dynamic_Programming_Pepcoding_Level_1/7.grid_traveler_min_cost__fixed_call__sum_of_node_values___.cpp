#include <bits/stdc++.h>
using namespace std;


int memo(int m, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {

    if (n == 0 || m == 0) return INT_MAX;

    if (dp[n][m] != -1) return dp[n][m];

    int l = INT_MAX;
    if (m - 1 >= 0) l = memo(m - 1, n, arr, dp);
    int  r = INT_MAX;
    r = memo(m, n - 1, arr, dp);

    if (l != INT_MAX && r != INT_MAX)
        return dp[n][m] = arr[m - 1][n - 1] + min(l, r);

    if (l == INT_MAX)
        return dp[n][m] = arr[m - 1][n - 1] + r;

    if (r == INT_MAX)
        return dp[n][m] = arr[m - 1][n - 1] + l;

}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0;j < n;j++)
            cin >> arr[i][j];
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << memo(m - 1, n - 1, arr, dp) << endl;
    // cout << memo(m, n, arr, dp) << endl;

    // cout << "dp------------------" << endl;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0;j <= m;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

}