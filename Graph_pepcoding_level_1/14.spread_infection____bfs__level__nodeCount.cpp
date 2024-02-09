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
    int time;

    Pair(int v, int time) {
        this->v = v;
        this->time = time; // time is level actually
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
int countSpread(vector<vector<Edge>>& g, int src, int t, vector<int>& visited)
{
    queue<Pair> q;
    q.push(Pair(src, 1));
    int count = 0;

    while (q.size() > 0)
    {
        Pair front = q.front();
        q.pop();

        if (front.time > t) return count;

        if (visited[front.v] > 0) continue;
        visited[front.v] = front.time;
        count++;

        for (Edge e : g[front.v])
        {
            if (visited[e.nbr] > 0) continue;
            q.push(Pair(e.nbr, front.time + 1));
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    int src, t;
    cin >> src >> t;

    vector<int> visited(n, -1);
    cout << countSpread(g, src, t, visited) << endl;
}
