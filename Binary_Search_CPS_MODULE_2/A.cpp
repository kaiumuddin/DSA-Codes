#include <bits/stdc++.h>
using namespace std;
int foc(vector<int> nums, int target) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (target == nums[mid]) {
            ans = mid;
            r = mid - 1;
        }
        if (target < nums[mid]) {
            r = mid - 1;
        }
        if (nums[mid] < target)
            l = mid + 1;
    }
    return ans;
}

int loc(vector<int> nums, int target) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (target == nums[mid]) {
            ans = mid;
            l = mid + 1;
        }
        if (target < nums[mid]) {
            r = mid - 1;
        }
        if (nums[mid] < target)
            l = mid + 1;
    }
    return ans;
}

int lowerb(vector<int> nums, int target) {
    int l = 0,
        r = nums.size() - 1;
    int ans = nums.size();

    while (l <= r) {
        int mid = (l + r) / 2;
        std::cout << nums[l]
            << " " << nums[mid]
            << " " << nums[r]
            << " -ans: " << ans << std::endl;
        if (target <= nums[mid]) {
            ans = mid;
            r = mid - 1;
        }
        if (target > nums[mid]) {
            l = mid + 1;
        }
    }

    return ans;
}

int upperb(vector<int> nums, int target) {
    int l = 0,
        r = nums.size() - 1;
    int ans = nums.size();

    while (l <= r) {
        int mid = (l + r) / 2;
        std::cout << nums[l]
            << " " << nums[mid]
            << " " << nums[r]
            << " -ans: " << ans << std::endl;
        if (target < nums[mid]) {
            ans = mid;
            r = mid - 1;
        }
        if (target >= nums[mid]) {
            l = mid + 1;
        }
    }

    return ans;
}

int bst(vector<int>& nums, int t) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] == t) return m;
        else if (t < nums[m]) r = m;
        else if (t > nums[m]) l = m + 1;
    }

    return -1;
}

int mysqrt(int t) {
    int l = 0, r = t + 1;
    int m;
    while (l < r) {
        m = l + (r - l) / 2;
        cout << l << " " << m << " " << r << endl;
        // if (m * m == t) return m;
        if (t < m * m) r = m;
        if (m * m <= t) l = m + 1;
    }
    cout << l << " " << m << " " << r << endl;
    return l - 1;
}

int main() {
    vector<int> nums = { 10,20,30,40,50,50,80,90 };

    int t = 10;
    // std::cout << foc(nums, t) << endl;
    // std::cout << loc(nums, t) << endl;
    // std::cout << lowerb(nums, t) << endl;
    // std::cout << upperb(nums, t) << endl;
    // std::cout << std::lower_bound(nums.begin(), nums.end(), t) - nums.begin() <<endl;
    // std::cout << std::upper_bound(nums.begin(), nums.end(), t) - nums.begin() <<endl;
    // cout << bst(nums, 20) <<endl;
    // cout << bst(nums, 70) <<endl;
    // cout << bst(nums, 0) <<endl;
    // cout << bst(nums, 50) <<endl;

    cout << mysqrt(36) << endl;
}













