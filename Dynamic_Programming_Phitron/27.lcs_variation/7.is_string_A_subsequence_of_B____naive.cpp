#include<bits/stdc++.h>
using namespace std;

bool solve(string a, string b, int n, int m)
{
    int x = 0;
    bool ans = false;

    for (char c : b)
    {
        if (c == a[x])
        {
            x++;
        }
        if (x == a.size())
        {
            ans = true;
            break;
        }
    }

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    cout << solve(a, b, n, m);
}
