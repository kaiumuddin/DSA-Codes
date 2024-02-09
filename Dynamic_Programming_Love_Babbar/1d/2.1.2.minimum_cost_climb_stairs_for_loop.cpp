#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:

    int solve(vector<int>& cost, int i) {
        if (i == 0) return cost[i];
        if (i == 1) return cost[i];

        int ans = INT_MAX;
        for (int j = 1; j <= 2; j++) {
            ans = min(ans, solve(cost, i - j));
        }

        if (i == cost.size())
            return ans;
        return ans + cost[i];
    }

    vector<int> dp;

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n + 1);
        return solve(cost, n);
    }
};