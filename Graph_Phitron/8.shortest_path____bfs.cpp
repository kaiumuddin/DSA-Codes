#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

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

// Time : O(2m)
// Time : O(n + m)
int bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

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
            parent[v] = u;
        }
    }

    return -1;
}

void printParent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Parent of " << i << ": "
            << parent[i] << " " << endl;
    }
    cout << endl;
}

// Time : O(n)
void printPath(int n, int s, int d)
{
    vector<int> path;
    int child = d;

    while (child != -1)
    {
        path.push_back(child);
        child = parent[child];
    }

    reverse(path.begin(), path.end());

    cout << "Path : ";
    for (int v : path)
        cout << v << " ";
    cout << endl;
}

void handleQuery(int n)
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
        // cout << ans << endl;
        // printParent(n);
        printPath(n, s, d);
    }
}

int main()
{
    int n = inputGraph();
    // printGraph(n);
    handleQuery(n);
}
