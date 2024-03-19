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

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v]) continue;
        dfs(v);
    }
}

void dfs_iterative(int s)
{
    stack<int> st;
    st.push(s);

    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        visited[u] = true;

        for (int v : adj[u]) {
            if (visited[v]) continue;
            st.push(v);
        }
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        visited[u] = true;

        for (int v : adj[u]) {
            if (visited[v]) continue;
            q.push(v);
        }
    }
}

void exploreAllComponents(int n)
{
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        // dfs(i);
        dfs_iterative(i);
        // bfs(i);
        cc++;
    }
    cout << "Num of connected component: " << cc << endl;
}

int main()
{
    int n = inputGraph();
    exploreAllComponents(n);
}
