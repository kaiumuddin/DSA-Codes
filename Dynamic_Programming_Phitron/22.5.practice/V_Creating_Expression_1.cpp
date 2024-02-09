#include<bits/stdc++.h>
using namespace std;

long long n, x;
long long a[21];

bool solve(long long sum, long long i)
{
    if (i == n) {
        return sum == x;
    }

    bool l = solve(sum + a[i], i + 1);
    bool r = solve(sum - a[i], i + 1);

    return l || r;
}

int main() {
    cin >> n >> x;

    for (int i = 0;i < n; i++)
    {
        cin >> a[i];
    }

    if (solve(a[0], 1)) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return 0;
}
