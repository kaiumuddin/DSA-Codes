#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> adj[N];
bool visited[N];

int inputGraph()
{
    int n, e;
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

void printGraph()
{
    for (int i = 0; i < 1000; i++)
    {
        if (adj[i].empty()) continue;
        cout << i << ": ";
        for (int j : adj[i])
        {
            cout << j << ",";
        }
        cout << endl;
    }
}

int dfs(int u)
{
    visited[u] = true;
    int total = 0;
    for (int v : adj[u])
    {
        if (visited[v]) continue;
        total += dfs(v);
    }
    return total + 1;
}

void exploreAllComponents(int N)
{
    vector<int> ans;
    for (int i = 0; i <= N; i++)
    {
        if (visited[i]) continue;
        // if (adj[i].empty()) continue;
        int result = dfs(i);
        if (result > 1)
            ans.push_back(result);
    }

    sort(ans.begin(), ans.end());
    for (int v : ans)
        cout << v << " ";
    cout << endl;
}

int main() {
    int n = inputGraph();
    // printGraph();
    exploreAllComponents(N);
}
