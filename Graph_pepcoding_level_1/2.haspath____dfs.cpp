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

// DFS
bool hasPath(vector<vector<Edge>>& g, int src, int dest, vector<bool>& visited)
{
    if (src == dest)
        return true;

    visited[src] = true;
    for (Edge edge : g[src])
    {
        if (visited[edge.nbr]) continue;
        bool hasNbrPath = hasPath(g, edge.nbr, dest, visited);
        if (hasNbrPath) return true;
    }
    visited[src] = false;

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    // printGraph(g);


    int src, dest;
    cin >> src >> dest;

    vector<bool> visited(n, false);
    cout << hasPath(g, src, dest, visited) << endl;

}
