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

void dfs(vector<vector<int>>& g, int r, int c, int move)
{
    if (r < 0 || c < 0 || r >= g.size() || c >= g.size()) return;
    if (g[r][c] > 0) return;

    if (move == g.size() * g.size()) {
        g[r][c] = move;
        printGraph(g, g.size(), g.size());
        g[r][c] = 0;
        return;
    }


    g[r][c] = move;

    dfs(g, r - 2, c - 1, move + 1);
    dfs(g, r - 2, c + 1, move + 1);

    dfs(g, r - 1, c + 2, move + 1);
    dfs(g, r + 1, c + 2, move + 1);

    dfs(g, r + 2, c + 1, move + 1);
    dfs(g, r + 2, c - 1, move + 1);

    dfs(g, r + 1, c - 2, move + 1);
    dfs(g, r - 1, c - 2, move + 1);

    g[r][c] = 0;

}




int main() {
    int n, r, c;
    cin >> n >> r >> c;

    vector<vector<int>> g(n, vector<int>(n, 0));
    printGraph(g, n, n);

    dfs(g, r, c, 1);
}
