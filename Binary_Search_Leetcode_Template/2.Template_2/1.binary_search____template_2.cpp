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
    while (left < right) {
        // Prevent (left + right) overflow
        mid = left + (right - left) / 2;
        print_ss(nums, left, mid, right);

        if (nums.at(mid) == target) {
            return mid;
        }
        else if (nums.at(mid) < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    print_ss(nums, left, mid, right);
    // Post-processing:
    // End Condition: left == right
    if (nums.at(left) == target) return left;
    return -1;
}

int main() {
    // cout << binarySearch({ 0 }, 0) << endl;
    // cout << binarySearch({ 0, 10 }, 10) << endl;
    cout << binarySearch({ 0, 10 }, 5) << endl;
    return 0;
}