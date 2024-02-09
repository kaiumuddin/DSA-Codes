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

bool yes(long long k, vector<long long> &a)
{
    a[0] = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[i] - a[i - 1] > k)
            return false;
        if (a[i] - a[i - 1] == k)
            --k;
    }
    return true;
}

long long solve()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long l = 0, r = 1e9, res = 0;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (yes(mid, a))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return res;
}

int main()
{
    init_code();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case " << i << ": " << solve() << '\n';

    return 0;
}
