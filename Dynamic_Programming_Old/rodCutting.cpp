#include <bits/stdc++.h>
using namespace std;

// Brute Force
// int cnt;
// int cuttRod(int length, vector<int> prices)
// {
//     ++cnt;

//     if (length <= 0)
//         return 0;

//     int maxProfit = INT_MIN;

//     for (int i = 1; i <= length; i++)
//     {
//         maxProfit = max(maxProfit, prices[i] + cuttRod(length - i, prices));
//     }

//     return maxProfit;
// }

// Memoization
// using ull = unsigned long long int;
// map<int, ull> memo = {};
// int cnt;
// int cuttRod(int length, vector<int> prices)
// {
//     ++cnt;
//     if (memo[length])
//         return memo[length];

//     if (length <= 0)
//         return 0;

//     int maxProfit = INT_MIN;

//     for (int i = 1; i <= length; i++)
//     {
//         maxProfit = max(maxProfit, prices[i] + cuttRod(length - i, prices));
//         memo[length] = maxProfit;
//     }

//     return maxProfit;
// }

// // Memoization 2
using ull = unsigned long long int;
map<int, ull> memo = {};
int cnt;
int cuttRod(int length, vector<int> prices)
{
    ++cnt;

    if (length <= 0)
        return 0;

    int maxProfit = INT_MIN;

    for (int i = 1; i <= length; i++)
    {
        int temp;
        if (memo.find(length - i) != memo.end())
            temp = memo[length - i];
        else
            temp = cuttRod(length - i, prices), memo[length - i] = temp;

        maxProfit = max(maxProfit, prices[i] + temp);
    }
    memo[length] = maxProfit;
    return maxProfit;
}
void pMemo()
{
    for (auto e : memo)
        cout << e.first << "\t" << e.second << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << cuttRod(3, {0, 3, 4, 5}) << endl;
    cout << cuttRod(8, {0, 1, 5, 8, 9, 10, 17, 17, 20}) << endl;
    cout << cnt << endl;
    pMemo();
}