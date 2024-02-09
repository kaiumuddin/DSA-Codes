#include<bits/stdc++.h>
using namespace std;

int parent[100];
int UnionRank[100];

void _make(int n)
{
    for (int i = 1;i <= n;i++)
    {
        parent[i] = i;
        UnionRank[i] = 0;
    }
}
int _find(int node)
{
    cout << "call stack " << node << endl;
    if (parent[node] == node) {
        return node;
    }

    return parent[node] = _find(parent[node]);
}

void _union(int a, int b)
{
    int pa = _find(a);
    int pb = _find(b);

    if (pa != pb) {
        // parent[pb] = pa;
        if (UnionRank[pa] > UnionRank[pb]) {
            parent[pb] = pa;
        }
        else if (UnionRank[pa] < UnionRank[pb])
        {
            parent[pa] = pb;
        }
        else {
            parent[pb] = pa;
            UnionRank[pa]++;
        }
    }
}

void _print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "\nparent of " << i << " : " << parent[i];
    }
    cout << endl;
}

int main() {
    int n, e;
    cin >> n >> e;

    _make(n);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        _union(a, b);
    }
    // _print(n);

}
