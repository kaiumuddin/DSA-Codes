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

class Pair {
public:
    int v;
    string psf;

    Pair(int v, string psf) {
        this->v = v;
        this->psf = psf;
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

// BFS
bool isCyclic(vector<vector<Edge>>& g, int src, vector<bool>& visited)
{
    queue<Pair> q;
    q.push(Pair(src, to_string(src)));

    while (q.size())
    {
        Pair front = q.front();
        q.pop();

        if (visited[front.v]) return true; // already visited

        visited[front.v] = true;

        for (Edge e : g[front.v])
        {
            if (visited[e.nbr]) continue;
            q.push(Pair(e.nbr, front.psf + to_string(e.nbr)));
        }
    }

    return false;
}

void exploreComps(vector<vector<Edge>>& g, int n, vector<bool>& visited)
{
    for (int v = 0; v < n; v++)
    {
        if (visited[v]) continue;

        bool ans = isCyclic(g, v, visited);
        if (ans == true) {
            cout << "Cycle" << endl;
            return;
        }
    }

    cout << "No cycle" << endl;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    vector<bool> visited(n, false);
    exploreComps(g, n, visited);

}
