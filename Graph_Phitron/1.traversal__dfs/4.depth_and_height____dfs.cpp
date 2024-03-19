#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];

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

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return n;
}

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == true) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        height[u] = max(height[u], height[v] + 1);
    }
}

void printDepth(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "Depth of node " << i << " : " << depth[i] << endl;
    }
}

void printHeight(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "Height of node " << i << " : " << height[i] << endl;
    }
}

int main()
{
    int n = inputGraph();
    cout << "Dfs : ";
    dfs(1);
    printDepth(n);
    printHeight(n);
}
