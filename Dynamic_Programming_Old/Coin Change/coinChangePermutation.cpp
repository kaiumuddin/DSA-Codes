#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;

map<int, ull> memo = {};

void pMemo()
{
    for (auto e : memo)
        cout << e.first << "\t" << e.second << endl;
}
int cnt;
ull coinChange(int amount, vector<int> coins)
{
    cnt++;
    if (amount == 0)
        return 1;
    if (amount < 0)
        return 0;
    ull nCombos = 0;
    for (auto coin : coins)
    {
        nCombos += coinChange(amount - coin, coins);
    }
    return nCombos;
}

int main()
{
    system("cls");
    // cout << coinChange(7, {7, 7, 7}) << endl;
    // cout << coinChange(7, {7, 4, 3}) << endl;
    // cout << coinChange(10, {2, 3, 6}) << endl;
    // cout << coinChange(13, {7, 2, 3, 6}) << endl;
    // cout << coinChange(4, {1, 2, 3}) << endl;
    // cout << coinChange(5, {2, 3}) << endl;//1
    cout << coinChange(4, {1, 2}) << endl;//5
    // cout << coinChange(10, {1, 2, 3}) << endl;
    // cout << coinChange(8, {2, 3, 5}) << endl;
    // cout << coinChange(5, {1, 2, 3}) << endl;
    // cout << coinChange(3, {1,2}) << endl;
    // cout << coinChange(2, {1, 2}) << endl;
    // cout << coinChange(7, {2, 3}) << endl;
    // cout << coinChange(10, {2, 5, 3, 6}) << endl;
    cout << cnt << endl;
}