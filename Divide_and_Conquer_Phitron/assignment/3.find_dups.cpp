#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;

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

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int indx = binarySearch(nums, k);

    if (indx == 0 && nums[1] == k) {
        cout << "YES" << endl;
        return 0;
    }
    else if (indx == n - 1 && nums[n - 2] == k) {
        cout << "YES" << endl;
        return 0;
    }
    else {
        if (nums[indx - 1] == k || nums[indx + 1] == k) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
