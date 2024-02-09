#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char a[N][N];
int n, m;
int si, sj;
int di, dj;
bool vis[N][N];
vector<vector<int>> path = { {0,1},{0,-1},{1,0},{-1,0} };
vector<vector<int>> comp;

void dfs(int si, int sj)
{
    if (si < 0 || sj < 0 || si >= n || sj >= m) return;
    if (a[si][sj] == '-') return;
    if (vis[si][sj]) return;

    vis[si][sj] = true;
    comp.push_back({ si,sj });

    for (int i = 0; i < 4; i++)
    {
        int ci = si + path[i][0];
        int cj = sj + path[i][1];

        dfs(ci, cj);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int minArea = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(i, j);
            if (comp.size() > 0) {
                int sz = comp.size();
                minArea = min(minArea, sz);
                comp.clear();
            }
        }
    }

    if (minArea == INT_MAX) cout << -1 << endl;
    else cout << minArea << endl;

}
