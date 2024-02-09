#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<vector<int>> dp(N, vector<int>(N, 0));

string solve(string a, int n, string b, int m)
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

    // print lcs
    int i = n, j = m;
    string lcs;

    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs += a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][i - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    return lcs;
}

int main() {
    string a;
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());

    string lps = solve(a, a.size(), b, b.size());

    cout << a.size() - lps.size() << endl;
}
