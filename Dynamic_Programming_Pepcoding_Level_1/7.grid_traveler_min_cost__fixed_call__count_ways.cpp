#include <bits/stdc++.h>
using namespace std;


int memo(int n, int m) {

    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    int l = memo(n - 1, m);
    int  r = memo(n, m - 1);

    return l + r;
}

// int tabu(int n, int index, vector<int>& arr, vector<int>& dp) {

// }

int main() {
    int n, m;
    cin >> n >> m;

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << memo(n, m) << endl;
    // cout << tabu(n, 0, arr, dp) << endl;


    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0;j <= m;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

}