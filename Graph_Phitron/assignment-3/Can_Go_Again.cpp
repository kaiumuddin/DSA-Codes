#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

class Edge
{
public:
    int u;
    int v;
    long long w;
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;
    while (e--)
    {
        Edge ed;
        cin >> ed.u >> ed.v >> ed.w;
        edgeList.push_back(ed);
    }

    int s;
    cin >> s;

    vector<long long> dis(n + 1, INF);
    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < edgeList.size(); j++)
        {
            Edge ed = edgeList[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;

            if (dis[a] < INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool hasCycle = false;
    for (int j = 0; j < edgeList.size(); j++)
    {
        Edge ed = edgeList[j];
        int a = ed.u;
        int b = ed.v;
        long long w = ed.w;

        if (dis[a] < INF && dis[a] + w < dis[b])
        {
            hasCycle = true;
            break;
        }
    }


    if (hasCycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int d;
        cin >> d;


        if (dis[d] >= INF)
            cout << "Not Possible" << endl;
        else
            cout << dis[d] << endl;
    }

}