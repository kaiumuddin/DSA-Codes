#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

const int N = 1005;
char a[N][N];
bool vis[N][N];
int dis[N][N];
vector<pii> path = { {-1,0},{1,0}, {0,-1}, {0,1} };

bool isValid(int ci, int cj, int n, int m)
{
    if (ci < 0 || cj < 0 || ci >= n || cj >= m) return false;
    return true;
}

void bfs(int si, int sj, int n, int m)
{
    queue<pii> q;
    q.push({ si, sj });
    dis[si][sj] = 0;
    vis[si][sj] = true;

    while (q.size())
    {
        pii parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + path[i].first;
            int cj = pj + path[i].second;

            if (not isValid(ci, cj, n, m)) continue;
            if (vis[ci][cj]) continue;

            q.push({ ci, cj });
            vis[ci][cj] = true;
            dis[ci][cj] = dis[pi][pj] + 1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0;j < m; j++) {
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    bfs(si, sj, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0;j < m; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}
