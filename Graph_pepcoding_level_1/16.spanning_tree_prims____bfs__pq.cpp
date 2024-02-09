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
    int av;
    int wt;

    Pair(int v, int av, int wt) {
        this->v = v;
        this->av = av;
        this->wt = wt;
    }
};

class cmp {
public:
    bool operator()(Pair& a, Pair& b) {
        if (a.wt > b.wt) return true;
        return false;
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

// BFS ,disjkta
void spanningTree(vector<vector<Edge>>& g, int src, vector<bool>& visited)
{
    priority_queue<Pair, vector<Pair>, cmp> pq;
    pq.push(Pair(src, -1, 0));

    while (pq.size() > 0)
    {
        Pair rem = pq.top();
        pq.pop();

        if (visited[rem.v]) continue;
        visited[rem.v] = true;

        if (rem.av != -1)
            cout << rem.v << "-" << rem.av << "@" << rem.wt << endl;

        for (Edge e : g[rem.v])
        {
            if (visited[e.nbr]) continue;
            pq.push(Pair(e.nbr, rem.v, e.wt));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    vector<bool> visited(n, false);
    spanningTree(g, 0, visited);

}
