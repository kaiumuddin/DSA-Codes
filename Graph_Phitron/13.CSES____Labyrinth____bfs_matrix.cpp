#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;

vector<string> g;
bool visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii> direc = { {0,-1},{0,1},{-1,0},{1,0} };

int n, m;
int si, sj, di, dj;

void inputGraph()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        g.push_back(x);
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'A') si = i, sj = j;
            if (x[j] == 'B') di = i, dj = j;
        }
    }
}

bool isValid(int i, int j)
{
    return i >= 0 && i < n
        && j >= 0 && j < m;
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({ si,sj });
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (not q.empty())
    {
        pii upair = q.front();
        int ui = upair.first;
        int uj = upair.second;
        q.pop();

        for (pii d : direc)
        {
            int ni = ui + d.first;
            int nj = uj + d.second;

            if (not isValid(ni, nj)) continue;
            if (visited[ni][nj]) continue;
            if (g[ni][nj] == '#') continue;

            q.push({ ni, nj });
            visited[ni][nj] = true;
            level[ni][nj] = level[ui][uj] + 1;
            parent[ni][nj] = { ui,uj };
        }
    }
}

void printPath()
{
    vector<pii> path;
    pii curr = { di, dj };

    while (not (curr.first == si && curr.second == sj))
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back({ si,sj });
    reverse(path.begin(), path.end());

    for (int i = 1; i < path.size(); i++)
    {
        // path[i-1] -> path[i]
        if (path[i - 1].first == path[i].first)
        {
            if (path[i - 1].second + 1 == path[i].second)
                cout << "R";
            else
                cout << "L";
        }
        else
        {
            if (path[i - 1].first + 1 == path[i].first)
                cout << "D";
            else
                cout << "U";
        }
    }
}

int main() {
    inputGraph();

    bfs(si, sj);

    if (level[di][dj] != 0)
    {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;
    }
    else
        cout << "No" << endl;

    printPath();
}
