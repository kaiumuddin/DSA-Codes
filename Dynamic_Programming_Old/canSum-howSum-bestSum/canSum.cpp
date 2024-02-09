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
bool canSum(int targetSum, vector<int> numbers)
{
    if (targetSum == 0)
        return true;
    if (targetSum < 0)
        return false;

    for (auto num : numbers)
    {
        int remain = targetSum - num;
        if (canSum(remain, numbers) == true)
            return true;
    }

    return false;
}

int main()
{
    // system("cls");
    cout << canSum(7, {2, 3}) << endl;
    cout << canSum(7, {7, 7}) << endl;
    cout << canSum(7, {5, 3}) << endl;
}