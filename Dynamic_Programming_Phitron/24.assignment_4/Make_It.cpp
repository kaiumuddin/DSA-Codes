#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

bool solve(int start, int n)
{
    if (start == n) return true;

    if (dp[start] != -1) return dp[start];

    bool l = false;
    if (start + 3 <= n)
        l = solve(start + 3, n);

    bool r = false;
    if (start * 2 <= n)
        r = solve(start * 2, n);

    return dp[start] = l || r;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        memset(dp, -1, sizeof dp);

        if (solve(1, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
