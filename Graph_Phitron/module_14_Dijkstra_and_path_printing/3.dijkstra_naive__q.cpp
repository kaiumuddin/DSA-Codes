#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 1e5 + 5;
vector<pii> v[N];
int dis[N];

void dijkstra(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (pii c : v[parent])
        {
            int childCost = c.first;
            int childNode = c.second;

            if (dis[parent] + childCost < dis[childNode])
            {
                q.push(childNode);
                dis[childNode] = dis[parent] + childCost;
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
