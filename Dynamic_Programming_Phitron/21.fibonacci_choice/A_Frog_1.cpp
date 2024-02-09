#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];


// solution by Rahat vai
// int solve(int a[], int n)
// {
//     if (n == 1) {
//         return 0;
//     }

//     if (dp[n] != -1) return dp[n];

//     if (n == 2) {
//         return dp[n] = abs(a[2] - a[1]);
//     }
//     else {
//         int l = solve(a, n - 1) + abs(a[n] - a[n - 1]);
//         int r = solve(a, n - 2) + abs(a[n] - a[n - 2]);

//         return dp[n] = min(l, r);
//     }
// }

// solution by me
// int solve(int a[], int n)
// {
//     if (n <= 1) return 0;
//     if (n == 2) return dp[n] = abs(a[2] - a[1]);

//     if (dp[n] != -1) return dp[n];

//     int l = solve(a, n - 1) + abs(a[n] - a[n - 1]);
//     int r = solve(a, n - 2) + abs(a[n] - a[n - 2]);

//     return dp[n] = min(l, r);
// }

// solution by Rahat vai
int solve(int a[], int n)
{
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);

    for (int i = 3; i <= n;i++)
    {
        int l = dp[i - 1] + abs(a[i] - a[i - 1]);
        int r = dp[i - 2] + abs(a[i] - a[i - 2]);
        dp[i] = min(l, r);
    }

    return dp[n];
}


int main() {
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        cin >> a[i];
    }

    cout << solve(a, n) << endl;
}
