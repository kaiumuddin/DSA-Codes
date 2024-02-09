#include<bits/stdc++.h>
using namespace std;

void inputGraph(vector<vector<int>>& g, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0;j < m;j++)
        {
            int ele;
            cin >> ele;
            row.push_back(ele);
        }
        g.push_back(row);
    }
}

void printGraph(vector<vector<int>>& g, int n, int m)
{
    cout << "-------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-------------------------" << endl;
}

void dfs(vector<vector<int>>& g, int i, int j, vector<vector<bool>>& visited)
{
    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size()) return;
    if (g[i][j] == 1) return;
    if (visited[i][j]) return;

    visited[i][j] = true;

    dfs(g, i - 1, j, visited);
    dfs(g, i + 1, j, visited);
    dfs(g, i, j - 1, visited);
    dfs(g, i, j + 1, visited);
}

void exploreComps(vector<vector<int>>& g, int n, int m)
{
    // bool visited[n][m] = { false };
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int totalComps = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m; j++)
        {
            if (g[i][j] == 1) continue;
            if (visited[i][j]) continue;
            dfs(g, i, j, visited);
            totalComps++;
        }
    }

    cout << totalComps << endl;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g;
    inputGraph(g, n, m);
    // printGraph(g, n, m);
    exploreComps(g, n, m);
}
