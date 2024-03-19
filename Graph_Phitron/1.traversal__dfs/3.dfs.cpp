#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];

void inputGraph()
{
    int  n, m; // n is node, m is edge
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (int j : g[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void dfs(int s)
{
    cout << s << " ";
    visited[s] = true;
    for (int c : g[s])
    {
        if (visited[c] == true) continue;
        dfs(c);
    }
}

int main()
{
    inputGraph();
    dfs(1);
}

// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?leftPanelTab=0