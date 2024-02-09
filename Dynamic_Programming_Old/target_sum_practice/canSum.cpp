#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;

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
    cout << canSum(1, { 2,3 }) << endl;
}