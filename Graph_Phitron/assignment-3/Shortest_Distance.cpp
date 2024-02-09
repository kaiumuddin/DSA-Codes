#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, e;
    cin >> n >> e;

    long long dis[n + 1][n + 1];

    // reset to INF
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            dis[i][j] = INF;
            if (i == j) dis[i][j] = 0;
        }
    }

    // input edges
    while (e--) {
        long long a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b], w);
    }

    // floyd warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // if (dis[i][k] == INF || dis[k][j] == INF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    // for (int i = 1; i <= n;i++) {
    //     for (int j = 1; j <= n;j++) {
    //         if (dis[i][j] == INF)
    //             dis[i][j] = -1;
    //         if (i == j) dis[i][j] = 0;

    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // handle query
    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (dis[x][y] == INF) cout << -1 << endl;
        else cout << dis[x][y] << endl;
    }
}

