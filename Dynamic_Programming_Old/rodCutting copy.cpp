#include <bits/stdc++.h>
using namespace std;

int rodCutting(int n, vector<int> v)
{
    if (n <= 0)
        return 0;
    int maxP = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        maxP = max(maxP, v[i] + rodCutting(n - i, v));
    }

    return maxP;
}

int main()
{
    cout << rodCutting(3, {0, 4, 8, 13});

    return 0;
}