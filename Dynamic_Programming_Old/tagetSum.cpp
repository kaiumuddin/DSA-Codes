#include<bits/stdc++.h>
using namespace std;

// bool targetSum(int target, int num)
// {
//     if(target == 0) return true;
//     if(target < 0) return false;
//     int remainder = target - num;
//     return targetSum(remainder, num);
//     return false;
// }

bool targetSum(int target, std::vector<int> numBank)
{
    if(target == 0) return true;
    if(target < 0) return false;

    for(int num:numBank)
    {
        int remainder = target - num;
        if(targetSum(remainder, numBank) == true)
        {
            // cout<< num <<endl;
            return true;
        }
    }
    return false;
}


int main()
{
    cout << targetSum(5, {2,3}) <<endl;

}
