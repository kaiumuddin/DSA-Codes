#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> g;
bool visited[N][N];
int n, m;
vector<pii> direc = { {0,-1},{0,1},{-1,0},{1,0} };

void inputGraph()
{
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        g.push_back(x);
    }
}

bool isValid(int i, int j)
{
    return i >= 0 && i < n
        && j >= 0 && j < m;
}

void dfs(int i, int j)
{
    // base case smartly handled
    if (not isValid(i, j)) return;
    if (g[i][j] == '#') return;
    if (visited[i][j]) return;

    visited[i][j] = true;

    // no need to call smartly, base case smartly handled
    for (pii d : direc)
    {
        dfs(i + d.first, j + d.second);
    }
}

void exploreComps()
{
    int room = 0;

    for (int i = 0;i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '#') continue;
            if (visited[i][j]) continue;

            dfs(i, j);
            room++;
        }
    }

    cout << room << endl;
}

int main() {
https://cses.fi/problemset/result/6812134/
    cin >> n >> m;
    inputGraph();
    exploreComps();
}
