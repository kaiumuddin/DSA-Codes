#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

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

bool dfs(int u, int p = -1)
{
    visited[u] = true;
    bool cycleExist = false;
    for (int v : adj[u])
    {
        if (v == p) continue;
        if (visited[v])
            return true;
        cycleExist = cycleExist | dfs(v, u);
    }

    return cycleExist;
}

void exploreAllComponents(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        if (dfs(i))
        {
            cout << "Cycle Detected" << endl;
            return;
        }
    }
    cout << "No Cycle Detected" << endl;
}

int main()
{
    int n = inputGraph();
    exploreAllComponents(n);
}
