#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<vector<int>> dp(N, vector<int>(N, -1));

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
                int l = dp[i - 1][j];
                int r = dp[i][j - 1];
                dp[i][j] = max(l, r);
            }
        }
    }

    int i = n;
    int j = m;
    string ans;

    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += a[i - 1];
            i--;
        }
        else
        {
            ans += b[j - 1];
            j--;
        }
    }

    while (i != 0)
    {
        ans += a[i - 1];
        i--;
    }
    while (j != 0)
    {
        ans += b[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return dp[n][m];
}

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    int lcs = solve(a, n, b, m);
    int ans = n + m - lcs;
    cout << ans << endl;
}
