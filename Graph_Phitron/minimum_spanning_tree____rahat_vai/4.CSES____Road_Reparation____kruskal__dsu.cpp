#include<bits/stdc++.h>
using namespace std;

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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

const int N = 1e5 + 10;
int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n;i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }

    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB]) {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    for (Edge e : v) {
        int leaderA = dsu_find(e.a);
        int leaderB = dsu_find(e.b);
        if (leaderA == leaderB) continue; // cycle
        ans.push_back(e);
        dsu_union(e.a, e.b);
    }

    long long wsum = 0;
    for (Edge e : ans) {
        wsum += (long long)e.w;
    }
    if (ans.size() == n - 1)
        cout << wsum << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}

// https://cses.fi/problemset/task/1675/