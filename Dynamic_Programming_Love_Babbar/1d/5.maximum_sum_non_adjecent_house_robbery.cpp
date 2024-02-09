https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
using namespace std;

long long int solve(vector<int>& nums, int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    long long int incl = solve(nums, n - 2);
    long long int excl = solve(nums, n - 1);

    return max(nums[n] + incl, excl);
}

long long int houseRobber(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> f(nums.begin() + 1, nums.end());
    vector<int> s(nums.begin(), nums.end() - 1);

    return max(solve(f, f.size() - 1), solve(s, s.size() - 1));
}