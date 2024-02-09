#include<bits/stdc++.h>
using namespace std;

// int solve(int n, int x, int y, int z) {
//   if (n < 0)
//     return INT_MIN;
//   if (n == 0)
//     return 0;

//   int a = solve(n - x, x, y, z);
//   int b = solve(n - y, x, y, z);
//   int c = solve(n - z, x, y, z);

//   return max(a, max(b,c)) + 1;
// }

// int solve(int n, int x, int y, int z,vector<int>& dp) {
//   if (n == 0)
//     return 0;
//   if (n < 0)
//     return INT_MIN;

//   if(dp[n] != -1) return dp[n];

//   int a = solve(n - x, x, y, z, dp);
//   int b = solve(n - y, x, y, z, dp);
//   int c = solve(n - z, x, y, z, dp);

//   return dp[n] = max(a, max(b,c)) + 1;
// }

int solve(int n, int x, int y, int z, vector<int>& dp) {
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int a = (i - x >= 0) ? dp[i - x] : INT_MIN;
        int b = (i - y >= 0) ? dp[i - y] : INT_MIN;
        int c = (i - z >= 0) ? dp[i - z] : INT_MIN;

        dp[i] = max(a, max(b, c)) + 1;
    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n + 1, -1);
    // int ans = solve(n, x, y,z);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}

int main() {

    return 0;
}