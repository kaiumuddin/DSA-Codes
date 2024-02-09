#include<limits.h>
// // Brute Force
// int solve(int n, int x, int y, int z) {
//     if(n < 0)
//         return INT_MIN;
//     if(n == 0)
//         return 0;

//     int ans1 = solve(n - x, x, y, z);
//     int ans2 = solve(n - y, x, y, z);
//     int ans3 = solve(n - z, x, y, z);
//     int ans = max(ans1, max(ans2, ans3));

//     int maxi = INT_MIN;
//     if(ans != INT_MIN)
//         maxi = max(maxi, 1 + ans);

//     return maxi;
// }

// int cutSegments(int n, int x, int y, int z) {
//     int ans = solve(n,x,y,z);
//     if(ans < 0)
//         return 0;
//     return ans;
// }


// Memo
// int solve(int n, int x, int y, int z, vector<int> &memo) {
//     if(n < 0)
//         return INT_MIN;
//     if(n == 0)
//         return 0;

//      if(memo[n]!=INT_MIN)
//          return memo[n];

//     int ans1 = solve(n - x, x, y, z, memo);
//     int ans2 = solve(n - y, x, y, z, memo);
//     int ans3 = solve(n - z, x, y, z, memo);
//     int ans = max(ans1, max(ans2, ans3));

//     int maxi = INT_MIN;
//     if(ans != INT_MIN)
//         maxi = max(maxi, 1 + ans);

//     return memo[n] = maxi;
// }

// int cutSegments(int n, int x, int y, int z) {
//     vector<int> memo;
//     memo.resize(n+1, INT_MIN);
//     int ans = solve(n,x,y,z, memo);
//     if(ans < 0)
//         return 0;
//     return ans;
// }

int solve(int n, int x, int y, int z, vector<int>& dp) {

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {


        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);

    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp;
    dp.resize(n + 1, INT_MIN);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}