#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 1e3 + 5;
int a[N][N];
bool vis[N][N];
int n, m;
vector<pii> path = { {0,1},{0,-1},{1,0},{-1,0} };

bool isValid(int ci, int cj)
{
    if (ci < 0 || cj < 0 || ci >= n || cj >= m) return false;
    if (a[ci][cj] == 0) return false;
    return true;
}

int dfsSum = 0;
int dfsCnt = 0;

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    dfsSum += a[si][sj];
    dfsCnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + path[i].first;
        int cj = sj + path[i].second;

        if (isValid(ci, cj) and not vis[ci][cj]) {
            dfs(ci, cj);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        int finalAns = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0 and not vis[i][j]) {
                    dfs(i, j);
                    if (dfsCnt >= 2)
                        finalAns += dfsSum;
                }
                dfsSum = 0;
                dfsCnt = 0;
            }
        }

        cout << finalAns << endl;

        // reset
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                a[i][j] = 0;
                vis[i][j] = false;
            }
        }
        n = 0;
        m = 0;
        finalAns = 0;
    }

}
