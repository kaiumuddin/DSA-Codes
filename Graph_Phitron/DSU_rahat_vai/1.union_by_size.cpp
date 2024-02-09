#include<bits/stdc++.h>
using namespace std;

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

    dsu_set(n);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    // print parent
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << parent[i] << endl;
    }
}