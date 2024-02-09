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

class Ans
{
public:
    string spath;
    int spathwt = INT_MAX;
    string lpath;
    int lpathwt = INT_MIN;
    string cpath;
    int cpathwt = INT_MAX;
    string fpath;
    int fpathwt = INT_MIN;
    priority_queue <
        pair<int, string>,
        vector < pair<int, string>>,
        greater < pair<int, string>>
    > pq;

    void print(int k)
    {
        cout << "spath : " << spath << " " << "@" << spathwt << endl;
        cout << "lpath : " << lpath << " " << "@" << lpathwt << endl;
        cout << "cpath : " << cpath << " " << "@" << cpathwt << endl;
        cout << "fpath : " << fpath << " " << "@" << fpathwt << endl;
        cout << k << " th largest : " << pq.top().second << "@" << pq.top().first << endl;
    }
};
Ans ans;

// DFS
void multisolver(vector<vector<Edge>>& g, int src, int dest, vector<bool>& visited, int criteria, int k, string psf, int wsf)
{
    if (src == dest)
    {
        cout << psf << " @" << wsf << endl;
        if (wsf < ans.spathwt) {
            ans.spathwt = wsf;
            ans.spath = psf;
        }
        if (wsf > ans.lpathwt) {
            ans.lpathwt = wsf;
            ans.lpath = psf;
        }
        if (wsf > criteria && wsf < ans.cpathwt) {
            ans.cpathwt = wsf;
            ans.cpath = psf;
        }
        if (wsf < criteria && wsf > ans.fpathwt) {
            ans.fpathwt = wsf;
            ans.fpath = psf;
        }

        if (ans.pq.size() < k) {
            ans.pq.push({ wsf, psf });
        }
        else {
            if (wsf > ans.pq.top().first) {
                ans.pq.pop();
                ans.pq.push({ wsf, psf });
            }
        }
        return;
    }

    visited[src] = true;
    for (Edge edge : g[src])
    {
        if (visited[edge.nbr]) continue;
        multisolver(g, edge.nbr, dest, visited, criteria, k, psf + "-" + to_string(edge.nbr), wsf + edge.wt);
    }
    visited[src] = false; // mark false when going back from node, not child btw
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    inputGraph(g, n, m);
    printGraph(g);

    int src, dest;
    cin >> src >> dest;

    int criteria, k;
    cin >> criteria >> k;

    vector<bool> visited(n, false);
    string psf = to_string(src);
    int wsf = 0;

    multisolver(g, src, dest, visited, criteria, k, psf, wsf);

    ans.print(k);
}
