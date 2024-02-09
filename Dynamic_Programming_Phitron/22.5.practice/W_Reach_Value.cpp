#include<bits/stdc++.h>
using namespace std;

bool solve(long long n, long long mul)
{
    if (mul > n) return false;
    if (mul == n) return true;

    return solve(n, mul * 10) || solve(n, mul * 20);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (solve(n, 1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}