#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> v[N];
int dis[N];
bool vis[N];
int n, e;
vector<int> cmp;

void dfs(int s)
{
    vis[s] = true;
    cmp.push_back(s);
    for (int c : v[s])
    {
        if (not vis[c])
        {
            dfs(c);
        }
    }
}

int main() {
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (not vis[i])
        {
            cnt++;
            dfs(i);
            for (int val : cmp) cout << val << " ";
            cout << endl;
            cmp.clear();
        }
    }
    cout << cnt << endl;
}
