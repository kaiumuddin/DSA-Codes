#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    return solve(n - 1) + solve(n - 2);
}

int solve2(int n, vector<int> v)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    int result = 0;

    for (auto i : v)
        result += solve2(n - i, v);

    return result;
}

int main()
{
    system("cls");
    // cout << solve2(4, {1, 2, 3}) << endl;
    cout << solve2(6, {2, 4}) << endl;
    // solve(8);
    return 0;
}