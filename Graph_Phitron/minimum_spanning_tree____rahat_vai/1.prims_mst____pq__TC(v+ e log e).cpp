#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int N = 1e5 + 5;
vector<pii> v[N];
bool vis[N];

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s)
{
    vector<Edge> edgeList;

    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(-1, s, 0));

    while (pq.size())
    {
        // remove
        Edge parent = pq.top();
        pq.pop();

        // mark *
        if (vis[parent.b]) continue;
        vis[parent.b] = true;

        // work / print
        edgeList.push_back(parent);

        // add nbr
        for (pii child : v[parent.b])
        {
            if (vis[child.first]) continue;
            pq.push(Edge(parent.b, child.first, child.second));
        }
    }

    edgeList.erase(edgeList.begin());
    for (Edge edge : edgeList)
    {
        cout << edge.a << " " << edge.b << " " << edge.w << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({ b,w });
        v[b].push_back({ a,w });
    }

    prims(1);
}

// 8 11
// 1 5 2
// 1 2 4
// 1 4 10
// 5 4 5
// 2 4 8
// 2 3 18
// 3 4 11
// 4 8 9
// 4 7 11
// 7 6 1
// 8 6 2