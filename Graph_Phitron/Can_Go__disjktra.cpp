#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 1e5 + 5;
const int INF = 1e9 + 10;
vector<pii> g[N];
bool vis[N];
vector<int> dis(N, INF);
int n, e;

void dijsktra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[s] = 0;
    pq.push({ dis[s],s });

    while (pq.size())
    {
        int pn = pq.top().second; // second is node
        int pw = pq.top().first; // first is weight
        pq.pop();

        if (vis[pn]) continue;
        vis[pn] = true;

        for (pii child : g[pn])
        {
            int cn = child.first; // first is  node
            int cw = child.second; // second is weight

            if (vis[cn]) continue;

            if (dis[pn] + cw < dis[cn])
            {
                dis[cn] = dis[pn] + cw;
                pq.push({ dis[cn], cn });
            }
        }
    }
}

int main() {
    cin >> n >> e;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({ b,w });
        // g[b].push_back({ a,w });
    }

    int s;
    cin >> s;
    dijsktra(s);

    int t;
    cin >> t;
    while (t--)
    {
        int d, w;
        cin >> d >> w;

        if (dis[d] <= w) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " " << dis[i] << endl;
    // }


}

