#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // first is node, second is weight
const int INF = 1e9 + 10;
const int N = 1e3 + 5;

vector<pii> adj[N];
vector<int> dist(N, INF);
vector<string> psf(N);
vector<bool> visited(N);

int inputGraph()
{
    int n, m; // n is node, m is edge
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }

    return n;
}

void dijkstra(int source) // BFS
{
    priority_queue<pii, vector<pii>, greater<pii>> pq; // first is distance, second is node

    dist[source] = 0;
    psf[source] = to_string(source);
    pq.push({ dist[source], source }); // first is distance, second is node


    while (!pq.empty())
    {
        int parent = pq.top().second;
        pq.pop();

        if (visited[parent]) continue;
        visited[parent] = true;

        for (pii child : adj[parent])
        {
            int childNode = child.first; // first is node
            int childCost = child.second; // second is weight

            if (visited[childNode]) continue;

            if (dist[parent] + childCost < dist[childNode])
            {
                dist[childNode] = dist[parent] + childCost;
                psf[childNode] = psf[parent] + "-" + to_string(childNode);
                pq.push({ dist[childNode], childNode });
            }
        }
    }
}

void printDistance(int n)
{
    for (int i = 1; i <= n;i++)
    {
        cout << "Distance of node: " << i << ": "
            << dist[i] << endl;
        cout << "path of node: " << i << ": "
            << psf[i] << endl << endl;
    }
}


int main() {
    int n = inputGraph();
    dijkstra(1);
    printDistance(n);
}


// doesn't work on negative edge