#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 1e5 + 5;
vector<pii> v[N];
int dis[N];
bool vis[N];
int parent[N];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,s });
    dis[s] = 0;
    parent[s] = -1;

    while (!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        int pc = p.first;
        int pn = p.second;

        if (vis[pn]) continue;
        vis[pn] = true;

        for (pii c : v[pn])
        {
            int cc = c.first;
            int cn = c.second;

            if (pc + cc < dis[cn])
            {
                pq.push({ pc + cc, cn });
                dis[cn] = pc + cc;
                parent[cn] = pn;
            }
        }
    }
}

void print_shortest_path(int n)
{
    if (n == -1) return;

    print_shortest_path(parent[n]);
    cout << n << endl;
}

int main() {
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({ w,b });
        v[b].push_back({ w,a });
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << "dist Node " << i << ": " << dis[i] << endl;
    }

    // print_shortest_path(5);
}
