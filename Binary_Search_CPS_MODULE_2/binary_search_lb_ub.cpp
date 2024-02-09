#include <bits/stdc++.h>
using namespace std;

// Iterator lower_bound(Iterator first, Iterator last, const val)
// lower_bound returns an iterator pointing to the first element in the range[first, last) which has a value greater/equal than ‘val’.

// Iterator upper_bound(Iterator first, Iterator last, const val)
// upper_bound returns an iterator pointing to the first element in the range[first, last) which has a value greater than ‘val’.

// If the value is not present in the vector then it returns the end iterator.

int lb(vector<int> nums, int target) {
    int left = 0,              // search space begin, ss should be at least 2 element
        right = nums.size(),    // search space end, it can be nums.size() - 1 also, also can be ans
        mid = 0;              // m can  be anywhere

    while (left < right) {
        mid = left + (right - left) / 2;    // to overcome interger overflow
        // calculated mid can be on left, or anywhere in ss

        if (nums[mid] >= target) {   // is the mid you are looking for?
            right = mid; // mid can  be ans, include in ss
        }
        else {
            left = mid + 1;
        }
    }

    return right;
}
int ub(vector<int> nums, int target) {
    int left = 0,              // search space begin
        right = nums.size(),    // search space end, it can be nums.size() - 1 also, also can be ans
        mid = 0;              // m can  be anywhere

    while (left < right) {
        mid = left + (right - left) / 2;    // to overcome interger overflow
        // calculated mid can be on left, or anywhere in ss

        if (nums[mid] > target) {   // is the mid you are looking for?
            right = mid; // mid can  be ans, include in ss
        }
        else {
            left = mid + 1;
        }
    }

    return right;
}

int main() {
    vector<int> nums = { 1,3 };
    cout << "Lower Bound" << endl;
    cout << lb(nums, 0) << endl;
    cout << lb(nums, 1) << endl;
    cout << lb(nums, 2) << endl;
    cout << lb(nums, 3) << endl;
    cout << lb(nums, 4) << endl;
    cout << "Upper Bound" << endl;
    cout << ub(nums, 0) << endl;
    cout << ub(nums, 1) << endl;
    cout << ub(nums, 2) << endl;
    cout << ub(nums, 3) << endl;
    cout << ub(nums, 4) << endl;
}
