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

void solve()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);

    long long l = 0, r = 1e14;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        l = max(l, a[i]);
    }

    long long res = 0;

    auto yes = [&](long long mid)
    {
        long long sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (sum + a[i] > mid)
            {
                ++cnt;
                sum = a[i];
            }
            else
            {
                sum += a[i];
            }
        }
        if (sum != 0)
            ++cnt;
        return cnt <= k;
    };

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (yes(mid))
        {
            r = mid - 1;
            res = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << res << '\n';
}
// FFFFFFFFFFFTTTTTTTTTTTT
int main()
{
    fast_io;
    init_code();

    solve();

    return 0;
}
