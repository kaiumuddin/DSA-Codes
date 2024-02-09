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

    return n;
}

void printGraph(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "List " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int dfs(int s, int d)
{
    if (s == d) return 0;

    visited[s] = true;
    int minDis = INT_MAX;

    for (int v : adj[s])
    {
        if (visited[v] == true) continue;
        int dis = dfs(v, d);
        if (dis != INT_MAX)
            minDis = min(minDis, dis + 1);
    }

    return minDis;
}

int bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == d) return level[u];

        for (int v : adj[u])
        {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }

    return -1;
}

void handleQuery()
{
    int q;
    cin >> q;

    while (q--)
    {
        memset(level, 0, sizeof(level));
        memset(visited, 0, sizeof(visited));
        int s, d;
        cin >> s >> d;

        int ans = bfs(s, d);
        cout << ans << endl;
    }
}

int main()
{
    int n = inputGraph();
    // printGraph(n);
    handleQuery();
}
