#include <bits/stdc++.h>
using namespace std;

// bool combRepeat(vector<int> nums, int target, int index = 0)
// {
//     if (target == 0)
//         return true;
//     if (target < 0)
//         return false;

//     for (int i = index; i < nums.size(); i++)
//     {
//         if (combRepeat(nums, target - nums[i], i + 1) == true)
//         {
//             cout << nums[i] << endl;
//             return true;
//         }
//     }

//     return false;
// }
int cnt = 0;
int knapsack(vector<int> wt, vector<int> pt, int W, int index = 0)
{
    cnt++;
    if (W <= 0 || index == wt.size())
        return 0;

    int total = INT_MIN;

    for (int i = index; i < wt.size(); i++)
    {
        total = max(total, pt[i] + knapsack(wt, pt, W - wt[i], i + 1));
    }
    return total;
}

int main()
{
    // cout << knapsack({2, 3, 1, 4}, {4, 5, 3, 7}, 5) << endl;
    // cout << knapsack({1, 2, 3}, {10, 20, 30}, 3) << endl;
    cout << knapsack({1, 2}, {10, 30}, 2) << endl;
    cout << cnt << endl;
}