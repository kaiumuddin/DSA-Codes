#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 8;
int level[N][N];
int visited[N][N];
vector<pii> direc = { {1,2}, {1,-2}, {-1,2}, {-1,-2},
                        {2,1}, {2,-1}, {-2, 1}, {-2,-1} };

void reset()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            level[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

bool isValid(int i, int j)
{
    return (i >= 0 && i < 8) && (j >= 0 && j < 8);
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

            q.push({ ni, nj });
            visited[ni][nj] = true;
            level[ni][nj] = level[ui][uj] + 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int si, sj, di, dj;
        si = x[0] - 'a';
        sj = x[1] - '1';

        di = y[0] - 'a';
        dj = y[1] - '1';

        bfs(si, sj);
        cout << level[di][dj] << endl;
        // reset();
        memset(level, 0, sizeof level);
        memset(visited, 0, sizeof visited);
    }
}
