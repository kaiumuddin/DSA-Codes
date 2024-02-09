#include <bits/stdc++.h>
using namespace std;

bool combRepeat(vector<int> nums, int target, int index = 0)
{
    if (target == 0)
        return true;
    if (target < 0)
        return false;

    for (int i = index; i < nums.size(); i++)
    {
        if (combRepeat(nums, target - nums[i], i + 1) == true)
        {
            cout << nums[i] << endl;
            return true;
        }
    }

    return false;
}

int main()
{
    cout << combRepeat({2, 3, 4}, 7) << endl; // output : 3 2 1
}