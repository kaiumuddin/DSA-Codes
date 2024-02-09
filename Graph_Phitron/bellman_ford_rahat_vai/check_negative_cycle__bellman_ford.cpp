#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
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

    vector<int> dis(n + 1, INT_MAX);
    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < edgeList.size(); j++)
        {
            Edge ed = edgeList[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] + w < dis[b])
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
        int w = ed.w;
        if (dis[a] + w < dis[b])
        {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle)
    {
        cout << "Has Cycle" << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " : " << dis[i] << endl;
    }
}
