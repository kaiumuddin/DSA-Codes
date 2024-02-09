#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 1;
vector<int> adj[N];
int visited[N];

int inputGraph()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
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


void dfs(int s)
{
    visited[s] = true;
    for (int v : adj[s])
    {
        if (visited[v]) continue;
        dfs(v);
    }
}

void handleAns(int n)
{
    int k;
    cin >> k;

    dfs(k);

    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        if (visited[i]) ans++;
    }
    cout << ans - 1;
}

int main() {
    int  n = inputGraph();
    // printGraph(n);
    handleAns(n);
}
