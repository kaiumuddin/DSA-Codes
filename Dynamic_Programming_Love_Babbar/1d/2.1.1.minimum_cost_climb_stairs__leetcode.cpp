#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int solve(vector<int>& cost, int n) {
        if (n == 0) return cost[n];
        if (n == 1) return cost[n];

        int l = solve(cost, n - 1);
        int r = solve(cost, n - 2);

        if (n == cost.size())
            return min(l, r);
        return min(l, r) + cost[n];
    }

    // vector<int> dp;
    // int solve(vector<int>& cost, int n) {
    //     if (n == 0) return cost[n];
    //     if (n == 1) return cost[n];
    //     if (dp[n] != -1) return dp[n];

    //     int l = solve(cost, n - 1);
    //     int r = solve(cost, n - 2);

    //     if (n == cost.size())
    //         return dp[n] = min(l, r);
    //     return dp[n] = min(l, r) + cost[n];
    // }

    // int solve(vector<int>& cost, int n) {
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];

    //     for (int i = 2; i <= n - 1; i++) {
    //         dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]; // replace recursion call with dp array
    //     }

    //     return min(dp[n - 1], dp[n - 2]);
    // }

    // int solve(vector<int>& cost, int n) {
    //     int prev2 = cost[0];
    //     int prev1 = cost[1];

    //     for (int i = 2; i <= n - 1; i++) {
    //         int curr = min(prev1, prev2) + cost[i];// replace dp[] call with variable
    //         prev2 = prev1;
    //         prev1 = curr;
    //     }

    //     return min(prev1, prev2);
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // dp.resize(n + 1);
        return solve(cost, n);
    }
};