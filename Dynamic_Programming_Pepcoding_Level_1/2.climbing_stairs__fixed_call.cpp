#include <bits/stdc++.h>
using namespace std;

int cs(int n, vector<int>& dp) {
    if (n == 0) return 1;

    if (dp[n] != -1) return dp[n];

    int a = cs(n - 1, dp);
    int b = 0;
    if (n - 2 >= 0) b = cs(n - 2, dp);
    int c = 0;
    if (n - 3 >= 0) c = cs(n - 3, dp);

    return dp[n] = a + b + c;
}

int tabu(int n, vector<int>& dp) {
    for (int i = 0; i <= n; i++)
    {
        if (i == 0) {
            dp[0] = 1;
            continue;
        }
        int a = dp[i - 1];
        int b = 0;
        if (i - 2 >= 0) b = dp[i - 2];
        int c = 0;
        if (i - 3 >= 0) c = dp[i - 3];

        dp[i] = a + b + c;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    // cout << cs(n, dp) << endl;
    cout << tabu(n, dp) << endl;
}