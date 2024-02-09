#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    map<long long, long long> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }

    auto yes = [&](long long s)
    {
        long long ball = 3 * s;

        for (auto e : arr)
        {
            ball -= min(s, e.second);
        }
        return ball <= 0;
    };

    long long l = 0, h = 1e9, ans = 0;
    while (l <= h)
    {
        long long mid = l + (h - l) / 2;
        if (yes(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << ans << endl;
}