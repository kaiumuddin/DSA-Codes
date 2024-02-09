#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adjmat[N][N];

void inputGraph() {
    int  n, m; // n is node, m is edge
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjmat[u][v] = 1;// for directed
        adjmat[v][u] = 1; // for undirected
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    inputGraph();
}
