#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 1e5 + 5;
vector<pii> v[N];
int dis[N];
bool vis[N];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,s });

    while (!pq.empty())
    {
        pii rem = pq.top();
        pq.pop();

        if (vis[rem.second]) continue;
        vis[rem.second] = true;

        dis[rem.second] = rem.first;

        for (pii c : v[rem.second])
        {
            if (vis[c.second] == false)
            {
                pq.push({ rem.first + c.first, c.second });
            }
        }
    }
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

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "dist Node " << i << ": " << dis[i] << endl;
    }
}
