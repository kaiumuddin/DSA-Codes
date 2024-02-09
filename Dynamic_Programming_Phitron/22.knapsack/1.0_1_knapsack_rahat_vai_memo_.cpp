#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

int knapsack(int n, int v[], int w[], int s)
{
    if (n == 0) return 0;
    if (s == 0) return 0;

    if (dp[n][s] != -1) {
        return dp[n][s];
    }

    if (s >= w[n - 1])
    {
        int take = knapsack(n - 1, v, w, s - w[n - 1]) + v[n - 1];
        int notTake = knapsack(n - 1, v, w, s);

        return dp[n][s] = max(take, notTake);
    }
    else
    {
        return dp[n][s] = knapsack(n - 1, v, w, s);
    }
}

int main() {
    int n;
    cin >> n;
    int v[n], w[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];

    for (int i = 0; i < N;i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    int s;
    cin >> s;

    cout << knapsack(n, v, w, s) << endl;

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < s; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}
