#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 1e5 + 5;
vector<pii> v;

int main() {
    int e;
    cin >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end());

    for (pii e : v)
    {
        cout << e.first << " " << e.second << endl;
    }
}
