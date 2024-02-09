#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, n;
    cin >> k >> n;

    long long arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto yes = [&](long long t)
    {
        long long people = k * t;
        for (int i = 0; i < n; i++)
        {
            people -= min(t, arr[i]);
        }
        return people <= 0;
    };

    long long l = 0, h = 1e15, ans = 0;

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