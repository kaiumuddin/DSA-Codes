//-------------------//
// author: kaium2909 //
//-------------------//

#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define si set<int>
#define msi multiset<int>
#define pb push_back
#define insr insert
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(12) << x
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define in(x) \
    ll x;     \
    cin >> x
#define ins(x) \
    string x;  \
    cin >> x
#define out(x) \
    cout << x << nl;
#define nl '\n'
#define fore(t)      \
    for (auto e : t) \
        cout << e << nl;

using namespace std;

void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool f(long long x, long long sum)
{
    // cout << x * (x + 1) / 2 << '\n';
    if (x * (x + 1) / 2 < sum)
    {
        return true;
    }
    return false;
}

void solve()
{
    long long sum = 15;
    long long l = 0,
              r = 1e9;
    long long res = 0;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (f(mid, sum))
        {
            l = mid + 1;
        }
        else
        {
            res = mid;
            r = mid - 1;
        }
    }

    cout << res << '\n';
}

// FFFFFFFTTTTTTTTTTTTTTTT
// FFFFFFFFFFFFFFFFFTTTTTT

int main()
{
    // init_code();

    solve();

    return 0;
}
