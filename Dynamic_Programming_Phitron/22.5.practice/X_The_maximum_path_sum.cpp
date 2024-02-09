#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 11;
int a[N][N];

int solve(int i, int j)
{
    if (i == n - 1 && j == m - 1)
        return a[i][j];
    else if (i == n || j == m)
        return -1000000;

    int r = solve(i, j + 1) + a[i][j];
    int d = solve(i + 1, j) + a[i][j];

    return max(r, d);
}

int main() {
    cin >> n >> m;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << solve(0, 0) << endl;
}
