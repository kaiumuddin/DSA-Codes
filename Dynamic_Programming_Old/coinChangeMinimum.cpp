#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;

map<int, ull> memo = {};

void pMemo()
{
    for (auto e : memo)
        cout << e.first << "\t" << e.second << endl;
}

// Brute Force
// ull coinChange(int amount, vector<int> coins)
// {
//     if (amount == 0)
//         return 1;
//     if (amount < 0)
//         return 0;
//     ull nCombos = 0;
//     for (auto coin : coins)
//     {
//         nCombos += coinChange(amount - coin, coins);
//     }
//     return nCombos;
// }

// Brute Force
ull coinChange(int amount, vector<int> coins, int coinCounter = 0)
{
    if (amount == 0)
        return coinCounter;
    if (amount < 0)
        return INT_MAX;

    ull min = INT_MAX;
    for (auto coin : coins)
    {
        int newMin = coinChange(amount - coin, coins, coinCounter + 1);
        if (newMin < min)
            min = newMin;
    }
    return min;
}

int main()
{
    system("cls");
    cout << "Minimum" << endl;
    cout << coinChange(7, {7, 7, 7}) << endl;     //1
    cout << coinChange(7, {4, 3, 5}) << endl;     //2
    cout << coinChange(10, {2, 3, 6}) << endl;    //3
    cout << coinChange(13, {7, 2, 3, 6}) << endl; //2
    cout << coinChange(4, {1, 2, 3}) << endl;     //2
    cout << coinChange(10, {1, 2, 3}) << endl;    //4
    cout << coinChange(8, {2, 3, 5}) << endl;     //2
    cout << coinChange(5, {1, 2, 3}) << endl;     //2
    cout << coinChange(3, {1, 2}) << endl;        //2
    cout << coinChange(2, {1, 2}) << endl;        //1
    cout << coinChange(200, {50, 100}) << endl;   //2
    cout << coinChange(11, {9, 6, 5, 1}) << endl; //2
    cout << coinChange(30, {25, 10, 5}) << endl;  //2
}