#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

int inputGraph()
{
    int n, e; // n is node, e is edge
    cin >> n >> e;

    for (int i = 0; i < e; i++)
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
        cout << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
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

        for (int v : adj[u])
        {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

void handleAns(int n)
{
    int zamanLevel;
    cin >> zamanLevel;

    if (zamanLevel == 0)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> nodes;
    for (int i = 0; i <= 1e5; i++)
    {
        if (level[i] == zamanLevel)
        {
            nodes.push_back(i);
        }
    }

    if (nodes.empty()) cout << -1 << endl;
    else {
        for (int node : nodes) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = inputGraph();
    // printGraph(n);
    bfs(0);
    handleAns(n);
}