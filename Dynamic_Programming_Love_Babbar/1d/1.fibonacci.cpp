#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n <= 1)
        return n;

    int faith = fib(n - 1) + fib(n - 2);
    return faith;
}

// vector<int> dp;
// int fib(int n) {
//     if (n <= 1)
//         return n;
//     if (dp[n] != -1)
//         return dp[n];

//     dp[n] = fib(n - 1) + fib(n - 2);
//     return dp[n];
// }

// vector<int> dp;
// int fib(int n) {
//     dp.resize(n + 1, 0);
//     dp[0] = 0;
//     dp[1] = 1;

//     for (int i = 2; i <= n; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];

// }

int main() {
    int n;
    cin >> n;
    // dp.resize(n + 1, -1);
    cout << fib(n) << endl;
}

// https://youtu.be/PGsgv6nXhLw?t=1656
// for bottom up / tabulation

// 0. create dp array

// 1. Base case check
// n == 0, dp[0] = 0
// n == 1, dp[1] = 1

// 2. for loop after base case, from 2
// convert fib() to dp[]


// for space optimization
