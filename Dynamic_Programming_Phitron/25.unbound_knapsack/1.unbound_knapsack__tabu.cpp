#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int main() {
    int n, s;
    cin >> n >> s;
    int v[n], w[n];

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> w[i];




    int dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else dp[i][j] = 1005;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s;j++)
        {
            if (w[i - 1] <= j)
            {
                int l = dp[i][j - w[i - 1]] + v[i - 1];
                int r = dp[i - 1][j];

                dp[i][j] = max(l, r);
            }
            else
            {
                int r = dp[i - 1][j];
                dp[i][j] = r;
            }
        }
    }

    cout << dp[n][s] << endl;




    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

}
