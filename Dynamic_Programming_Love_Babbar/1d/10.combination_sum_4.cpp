#include <bits/stdc++.h>

// int findWays_(vector<int> &nums, int tar, vector<int>& dp) {
//   if (tar == 0)
//     return 1;

//   if(dp[tar] != -1) return dp[tar];

//   int ans = 0;
//   for (int i = 0; i < nums.size(); i++) {
//     if (tar >= nums[i]){
//         ans += findWays_(nums, tar - nums[i], dp);
//     }
//   }

//   return dp[tar] = ans;
// }

int findWays_(vector<int> &nums, int tar, vector<int>& dp) {
  dp[0] = 1;

  for(int t=1; t<=tar; t++)
  {
      for(int i=0; i<nums.size(); i++)
      {
          if(t >= nums[i])
          {
              dp[t] += dp[t- nums[i]];
          }
      }
  }

  return dp[tar];
}

int findWays(vector<int> &num, int tar) {
  // Write your code here.
//   vector<int> dp(tar + 1, -1); // for memo
  vector<int> dp(tar + 1, 0); // for tabu
  return findWays_(num, tar, dp);
}

// https://www.codingninjas.com/studio/problems/number-of-ways_3755252?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar