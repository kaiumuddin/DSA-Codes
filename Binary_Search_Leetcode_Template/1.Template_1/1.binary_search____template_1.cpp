#include<bits/stdc++.h>
using namespace std;

void print_ss(vector<int> a, int l, int m, int r) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < a.size(); i++) {
        if (i == l) cout << "l";
        if (i == m) cout << "m";
        if (i == r) cout << "r";

        cout << "\t";
    }
    cout << endl;
    cout << endl;
}

int binarySearch(vector<int> nums, int target) {
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
        // Prevent (left + right) overflow
        mid = left + (right - left) / 2;
        print_ss(nums, left, mid, right);

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    print_ss(nums, left, mid, right);

    // End Condition: left > right
    return -1;
}

int main() {
    cout << binarySearch({ 0 }, -10) << endl;
    return 0;
}