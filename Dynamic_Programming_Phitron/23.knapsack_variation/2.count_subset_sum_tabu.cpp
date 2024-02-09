#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

// bool solve(int n, int a[], int s)
// {
//     if (n == 0) {
//         if (s == 0) return true;
//         else return false;
//     }

//     if (dp[n][s] != -1) return dp[n][s];

//     if (s >= a[n - 1])
//     {
//         bool l = solve(n - 1, a, s - a[n - 1]);
//         bool r = solve(n - 1, a, s);

//         return dp[n][s] = l || r;
//     }
//     else {
//         bool r = solve(n - 1, a, s);
//         return dp[n][s] = r;
//     }

// }

int solve(int n, int a[], int s)
{
    dp[0][0] = 1;

    // for (int i = 1; i <= s; i++)
    // {
    //     dp[0][i] = 0;
    // }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0) {
                if (j == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j <= s;j++)
        {
            if (j >= a[i - 1])
            {
                int l = dp[i - 1][j - a[i - 1]];
                int r = dp[i - 1][j];

                dp[i][j] = l + r;
            }
            else {
                int r = dp[i - 1][j];

                dp[i][j] = r;
            }

        }
    }

    return dp[n][s];
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++) {
        cin >> a[i];
    }

    int s;
    cin >> s;

    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = 0;
        }
    }

    cout << solve(n, a, s) << endl;


    // for (int i = 0; i <= n;i++) {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }


}
