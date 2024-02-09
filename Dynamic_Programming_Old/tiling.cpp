#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;

map<int, ull> memo = {};
ull tiling(int n)
{
    if (memo.find(n) != memo.end())
        return memo[n];
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    memo[n] = tiling(n - 1) + tiling(n - 2);
    return memo[n];
}

int main()
{
    system("cls");
    cout << tiling(5) << endl;

    for (auto e : memo)
        cout << e.first << "\t" << e.second << endl;
}