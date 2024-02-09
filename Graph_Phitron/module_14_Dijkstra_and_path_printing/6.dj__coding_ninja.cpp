#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source)
{
    // Write your code here.

    vector<pii> g[vertices];
    bool vis[vertices] = { false };
    vector<int> dist(vertices, INT_MAX);

    for (auto e : vec) {
        g[e[0]].push_back({ e[2], e[1] });
        g[e[1]].push_back({ e[2], e[0] });
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({ 0, source });

    while (pq.size() > 0) {
        pii rem = pq.top();
        pq.pop();

        if (vis[rem.second] == true)
            continue;
        vis[rem.second] = false;

        dist[rem.second] = rem.first;

        for (pii c : g[rem.second])
        {
            if (vis[c.second] == false)
            {
                pq.push({ rem.first + c.first, c.second });
            }
        }
    }

    return dist;
}

int main()
{

}

// https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=1