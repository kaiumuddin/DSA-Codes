#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

// int knapsack(int n, int v[], int w[], int s)
// {
//     if (s < 0) return INT_MIN;
//     // if (s < 0) return 0;
//     if (s == 0) return 0;
//     if (n == 0) return 0;

//     int take = knapsack(n - 1, v, w, s - w[n]) + v[n];
//     // if returned INT_MIN then INT_MIN + value will be less than 0
//     int notT = knapsack(n - 1, v, w, s);

//     return max(take, notT);
// }

int dp[N];
int knapsack(int n, int v[], int w[], int s)
{
    if (s < 0) return INT_MIN;
    // if (s < 0) return 0;
    if (s == 0) return 0;
    if (n == 0) return 0;

    if (dp[n] != INT_MIN) return dp[n];

    int take = knapsack(n - 1, v, w, s - w[n]) + v[n];
    // if returned INT_MIN then INT_MIN + value will be less than 0
    int notT = knapsack(n - 1, v, w, s);

    return dp[n] = max(take, notT);
}


int main() {
    int n;
    cin >> n;
    int v[n + 1], w[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    int s;
    cin >> s;

    for (int i = 1; i <= n; i++)
        dp[i] = INT_MIN;

    cout << knapsack(n, v, w, s) << endl;
}
