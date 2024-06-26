#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

int inputGraph()
{
    int  n, m; // n is node, m is edge
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "List " << i << ": ";
    //     for (int j : adj[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    return n;
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // section 1 : Node

        cout << u << " ";

        for (int v : adj[u])
        {
            // section 2 : Going to child
            if (visited[v] == true) continue;
            level[v] = level[u] + 1;
            visited[v] = true;
            q.push(v);
            // section 3 : returning from child
        }

        // section 4 : returning from node
    }
    cout << endl;

}

void printLevel(int n) {
    for (int i = 1; i <= n; i++)
    {
        cout << "Level of " << i << ": " << level[i] << endl;
    }
}

int main()
{
    int n = inputGraph();
    bfs(1);
    printLevel(n);
}

// https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?leftPanelTab=1
