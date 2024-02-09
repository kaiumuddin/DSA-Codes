#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int main() {
    int n, e;
    cin >> n >> e;

    int dis[n + 1][n + 1];

    // reset to INF
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            dis[i][j] = INF;
            if (i == j) dis[i][j] = 0;
        }
    }

    // input edges
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }

    // print
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n;j++) {
            if (dis[i][j] == INF)
                cout << "F" << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    // floyd_warshall : directed graph
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    cout << "\nUpdated" <<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INF)
                dis[i][j] = -1;
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}

// 4 6
// 1 2 3
// 2 1 2
// 1 4 5
// 4 3 2
// 3 2 1
// 2 4 4

// jkn src teke src negtive hy... then cycle
// 3 3
// 1 2 -1
// 2 3 2
// 3 1 -3

// 0 -1 F 
// F 0 2 
// -3 F 0 

// diagonal value neg hle. 0 na hye
// Updated
// -2 -3 -1 
// -1 -2 0 
// -5 -6 -4