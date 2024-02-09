#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> visited(N, false);
vector<int> level(N, 0);
vector<int> parent(N, -1);

int inputGraph()
{
    int n, m; // n is node, m is edge
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    return n;
}

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    level[source] = 0;
    visited[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
            level[v] = level[u] + 1;
        }
    }
}

void exploreComps(int n)
{
    bfs(1);
    // cout << level[n] << endl;

    vector<int> path;
    int curr = n;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    if (path.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << path.size() << endl;
    for (int v : path) cout << v << " ";
    cout << endl;
}

int main() {
    // https://cses.fi/problemset/result/6811480/
    int n = inputGraph();
    exploreComps(n);
}
