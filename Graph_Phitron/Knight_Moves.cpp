#include<bits/stdc++.h>
using namespace std;

#define pii  pair<int,int>
const int N = 1e2 + 2;
vector<vector<bool>> vis(N, vector<bool>(N, false));
vector<vector<int>> dis(N, vector<int>(N, 0));
int n, m;

vector<vector<int>> path = { {1,2}, {1,-2}, {-1,2}, {-1,-2},
                        {2,1}, {2,-1}, {-2, 1}, {-2,-1} };

void bfs(int ki, int kj)
{
    queue<pii> q;
    q.push({ ki,kj });
    dis[ki][kj] = 0;
    // vis[ki][kj] = true;

    while (q.size())
    {
        pii p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;
        vis[pi][pj] = true;


        for (int i = 0; i < 8; i++)
        {
            int ci = pi + path[i][0];
            int cj = pj + path[i][1];

            if (ci < 0 || cj < 0 || ci >= n || cj >= m) continue;
            if (vis[ci][cj]) continue;

            dis[ci][cj] = dis[pi][pj] + 1;
            q.push({ ci, cj });
            // vis[ci][cj] = true;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int ki, kj;
        int qi, qj;
        cin >> n >> m;
        cin >> ki >> kj;
        cin >> qi >> qj;

        bfs(ki, kj);

        if (vis[qi][qj])
            cout << dis[qi][qj] << endl;
        else
            cout << -1 << endl;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                dis[i][j] = 0;
                vis[i][j] = false;
            }
    }
}
