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
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        g[v1].push_back(Edge(v1, v2, wt));
        g[v2].push_back(Edge(v2, v1, wt));
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

void dfs(vector<vector<Edge>>& g, vector<bool>& visited, int src, vector<int>& comp)
{
    visited[src] = true;
    comp.push_back(src);

    for (Edge edge : g[src])
    {
        if (visited[edge.nbr]) continue;
        dfs(g, visited, edge.nbr, comp);
    }

}

void exploreComps(vector<vector<Edge>>& g, int n)
{
    vector<bool> visited(n, false);
    vector<vector<int>> comps;

    for (int v = 0; v < n; v++)
    {
        if (visited[v]) continue;
        vector<int> comp;
        dfs(g, visited, v, comp);
        comps.push_back(comp);
    }

    // true or false 
    cout << (comps.size() == 1) << endl;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    exploreComps(g, n);
}
