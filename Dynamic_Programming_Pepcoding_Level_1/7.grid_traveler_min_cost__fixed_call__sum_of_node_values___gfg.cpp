#include <bits/stdc++.h>
using namespace std;


int memo(int m, int n, vector<vector<int>>& arr, vector<vector<int>>& dp) {

    if (n < 0 || m < 0) return INT_MAX;
    if (n == 0 && m == 0)
        return dp[n][m] = arr[m][n];

    if (dp[n][m] != -1) return dp[n][m];

    int l = memo(m - 1, n, arr, dp);
    int  r = memo(m, n - 1, arr, dp);

    return dp[n][m] = arr[m][n] + min(l, r);
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