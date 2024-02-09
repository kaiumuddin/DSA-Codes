#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];

int inputGraph()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return n;
}

void printGraph(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void handleAns()
{
    int k;
    cin >> k;

    cout << adj[k].size() << endl;
}

int main() {
    int  n = inputGraph();
    // printGraph(n);
    handleAns();
}
