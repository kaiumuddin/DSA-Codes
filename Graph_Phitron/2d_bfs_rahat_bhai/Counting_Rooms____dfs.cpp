#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 1e3 + 5;
char a[N][N];
bool vis[N][N];
int n, m;
vector<pii> path = { {0,1},{0,-1},{1,0},{-1,0} };

bool isValid(int ci, int cj)
{
    if (ci < 0 || cj < 0 || ci >= n || cj >= m) return false;
    if (a[ci][cj] == '#') return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + path[i].first;
        int cj = sj + path[i].second;

        if (isValid(ci, cj) and not vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '#' and not vis[i][j])
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
}
