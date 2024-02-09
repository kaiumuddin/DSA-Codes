#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt = 1) {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void inputGraph(vector<vector<Edge>>& g, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(Edge(v1, v2));
        g[v2].push_back(Edge(v2, v1));
    }

    return;
}

void printGraph(vector<vector<Edge>>& g)
{
    cout << "-------------------------" << endl;
    for (int i = 0;i < g.size(); i++)
    {
        cout << i << "-> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j].src << "-"
                << g[i][j].nbr << "@"
                << g[i][j].wt << ", ";
        }
        cout << endl;
    }

    cout << "-------------------------" << endl;
}

// topological sort
void dfs(vector<vector<Edge>>& g, vector<bool>& visited, int src, stack<int>& st)
{
    visited[src] = true;

    for (Edge e : g[src])
    {
        if (visited[e.nbr]) continue;
        dfs(g, visited, e.nbr, st);
    }

    st.push(src);
}

void exploreComps(vector<vector<Edge>>& g, int n)
{
    vector<bool> visited(n, false);
    stack<int> st;

    for (int v = 0; v < n; v++)
    {
        if (visited[v]) continue;
        dfs(g, visited, v, st);
    }

    // print stack in reverse order
    while (st.size())
    {
        cout << st.top() << endl;
        st.pop();
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    exploreComps(g, n);
}
