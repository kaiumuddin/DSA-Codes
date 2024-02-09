// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h> 
using namespace std;

// int solve(int n){
//     if(n == 0) return 1;
//     if(n < 0) return 0;

//     int faith = (solve(n-1) + solve(n-2));
//     return faith;
// }

// vector<int> dp;
// int solve(int n){
//     if(n == 0) return 1;
//     if(n < 0) return 0;

//     if(dp[n] != -1) return dp[n];

//     int faith = (solve(n-1) + solve(n-2)) % 1000000007;

//     return dp[n] = faith;
// }

vector<int> dp;
int solve(int n) {
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    return dp[n];
}

int countDistinctWays(int nStairs) {
    dp.resize(nStairs + 1, -1);
    return solve(nStairs);
}

int main() {
    cout << countDistinctWays(4) << endl;
}

