#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N];

int knapsack(int n, int v[], int w[], int s)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (j >= w[i - 1])
            {
                int take = dp[i - 1][j - w[i - 1]] + v[i - 1];
                int notTake = dp[i - 1][j];

                dp[i][j] = max(take, notTake);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }


    }

    return dp[n][s];

}


int main() {
    int n;
    cin >> n;
    int v[n + 1], w[n + 1];

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];

    for (int i = 0; i < N;i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 1;
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
