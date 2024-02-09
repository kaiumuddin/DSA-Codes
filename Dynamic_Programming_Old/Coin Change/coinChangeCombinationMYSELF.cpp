#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;
using ull = unsigned long long int;

ull coinChange(int amount, vector<int> v, int i = 0)
{
    if (i == v.size())
        return 0;
    if (amount < 0)
        return 0;
    if (amount == 0)
        return 1;

    return coinChange(amount - v[i], v, i) + coinChange(amount, v, i + 1);
}

// map<string, ull> memo = {};
// int cnt = 0;
// ull coinChange(int amount, vector<int> coins, int index = 0)
// {
//     cnt++;
//     if (index == coins.size())
//         return 0;
//     if (amount == 0)
//         return 1;
//     if (amount < 0)
//         return 0;

//     string key = to_string(index) + "|" + to_string(amount);

//     if (memo.find(key) == memo.end())
//         memo[key] = coinChange(amount - coins[index], coins, index) + coinChange(amount, coins, index + 1);

//     return memo[key];
// }


// ull coinChange(int amount, vector<int> coins, int index = 0)
// {
//     if (index == coins.size())
//         return 0;
//     if (amount == 0)
//         return 1;
//     if (amount < 0)
//         return 0;

//     string key = to_string(index) + "|" + to_string(amount);

//     if (memo.find(key) == memo.end())
//     {
//         int include = coinChange(amount - coins[index], coins, index);
//         int exclude = coinChange(amount, coins, index + 1);

//         memo[key] = include + exclude;
//     }

//     return memo[key];
// }

int main()
{
    // cout << coinChange(500, {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}) << endl;
    cout << coinChange(4, {1, 2}) << endl;//5

    // cout << cnt << endl;

    return 0;
}