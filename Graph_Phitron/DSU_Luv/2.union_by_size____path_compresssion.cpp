#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int sizee[N];

void make(int v) {
    parent[v] = v;
    sizee[v] = v;
}

int find(int v) {
    if (v == parent[v]) return v;
    // path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        // union by size
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}


int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        make(i);
    }
    while (k--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int connected_cnt = 0;

    for (int v = 1; v <= n; v++) {
        if (find(v) == v)
            connected_cnt++;
    }

    cout << connected_cnt << endl;
}

// TC = O(alpha(n)) -> reverse Ackerman function
// Amortized time complexity = first time very long, slowly average
