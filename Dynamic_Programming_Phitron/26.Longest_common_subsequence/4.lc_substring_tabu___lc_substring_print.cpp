#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<vector<int>> dp(N, vector<int>(N, 0));

int solve(string a, int n, string b, int m)
{
    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0; // diffrence b/w lcsubsequence
            }
        }
    }

    // print dp, find maximum
    int mx = 0;
    int ci, cj; // maximum position
    for (int i = 0; i <= n; i++) {
        for (int j = 0;j <= m; j++)
        {
            // cout << dp[i][j] << " ";
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                ci = i;
                cj = j;
            }
        }
        cout << endl;
    }

    string ans;
    while (ci != 0 && cj != 0)
    {
        if (a[ci - 1] == b[cj - 1])
        {
            ans += a[ci - 1];
            ci--;
            cj--;
        }
        else
        {
            break;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return mx;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << solve(a, a.size(), b, b.size()) << endl;
}
