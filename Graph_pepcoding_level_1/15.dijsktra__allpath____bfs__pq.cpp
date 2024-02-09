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
    int wsf;

    Pair(int v, string psf, int wsf) {
        this->v = v;
        this->psf = psf;
        this->wsf = wsf;
    }
};

class cmp {
public:
    bool operator()(Pair& a, Pair& b) {
        if (a.wsf > b.wsf) return true;
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

// BFS
void allPath(vector<vector<Edge>>& g, int src, vector<bool>& visited)
{
    priority_queue<Pair, vector<Pair>, cmp> pq;
    pq.push(Pair(src, to_string(src), 0));

    while (pq.size())
    {
        // remove top, 
        // if visited continue, else visit[node] 
        // print, 
        // add nbr if not visited
        Pair top = pq.top();
        pq.pop();

        if (visited[top.v]) continue;
        visited[top.v] = true;

        cout << top.v << " via " << top.psf << " @ " << top.wsf << endl;

        for (Edge e : g[top.v])
        {
            if (visited[e.nbr]) continue;
            pq.push(Pair(e.nbr, top.psf + to_string(e.nbr), top.wsf + e.wt));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    int src;
    cin >> src;

    vector<bool> visited(n, false);
    allPath(g, src, visited);

}
