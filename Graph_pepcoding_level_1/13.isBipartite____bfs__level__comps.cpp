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
    int level;

    Pair(int v, string psf, int level) {
        this->v = v;
        this->psf = psf;
        this->level = level;
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
bool isBipartite(vector<vector<Edge>>& g, int src, vector<int>& visited)
{
    queue<Pair> q;
    q.push(Pair(src, to_string(src), 0));

    while (q.size())
    {
        Pair curr = q.front();
        q.pop();

        if (visited[curr.v] != -1)
        {
            if (curr.level != visited[curr.v]) {
                return false;
            }
        }
        else {
            visited[curr.v] = curr.level;
        }

        for (Edge e : g[curr.v])
        {
            if (visited[e.nbr] == -1)
                q.push(Pair(e.nbr, curr.psf + to_string(e.nbr), curr.level + 1));
        }
    }

    return true;
}

void exploreComps(vector<vector<Edge>>& g, int n, vector<int>& visited)
{
    for (int v = 0; v < n; v++)
    {
        if (visited[v] != -1) continue;

        bool ans = isBipartite(g, v, visited);
        if (ans == false) {
            cout << "false" << endl;
            return;
        }
    }

    cout << "true" << endl;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    vector<int> visited(n, -1);
    exploreComps(g, n, visited);

}
