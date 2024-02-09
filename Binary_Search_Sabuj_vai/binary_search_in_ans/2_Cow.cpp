//-------------------//
// author: kaium2909 //
//-------------------//

#include <bits/stdc++.h>;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool yes(long long k, vector<long long> &a, int cow)
{
    long long last_cow = a[1];
    --cow;
    for (int i = 2; i < (int)a.size(); ++i)
    {
        if (a[i] - last_cow >= k)
        {
            last_cow = a[i];
            --cow;
        }
    }
    return cow <= 0;
}

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<long long> a(n + 1);
 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    long long l = 0, r = 1e9, res = 0;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (yes(mid, a, c))
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << res << '\n';
}

int main()
{
    fast_io;
    init_code();

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
