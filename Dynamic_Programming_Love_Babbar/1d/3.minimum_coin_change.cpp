// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    //     int solve(vector<int>& coins, int amount){
    //         if(amount == 0) return 0;
    //         if(amount < 0) return INT_MAX;

    //         int mini = INT_MAX;
    //         for(int coin: coins){
    //             int faith = solve(coins, amount - coin);
    //             if(faith != INT_MAX){
    //                 mini = min(mini, 1 + faith);
    //             }
    //         }
    //         return mini;
    //     }

    vector<int> dp;
    //     int solve(vector<int>& coins, int amount){
    //         if(amount == 0) return 0;
    //         if(amount < 0) return INT_MAX;

    //         if(dp[amount] != -1) return dp[amount];

    //         int mini = INT_MAX;
    //         for(int coin: coins){
    //             int faith = solve(coins, amount - coin);
    //             if(faith != INT_MAX){
    //                 mini = min(mini, 1 + faith);
    //             }
    //         }
    //         return dp[amount] = mini;
    //     }

    int solve(vector<int>& coins, int amount) {
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int mini = INT_MAX;

            for (int coin : coins) {

                if (i - coin >= 0) {
                    int faith = dp[i - coin];

                    if (faith != INT_MAX) {
                        mini = min(mini, 1 + faith);
                    }
                }
            }
            dp[i] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, INT_MAX);
        int ans = solve(coins, amount);

        return ans != INT_MAX ? ans : -1;
    }
};

int main() {
    Solution s;
    vector<int> coins = { 1,2,3,4 };
    cout << s.coinChange(coins, 10) << endl;
}