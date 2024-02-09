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

    int ans = binarySearch(nums, k);
    if (ans == -1)
        cout << "Not Found" << endl;
    else
        cout << ans << endl;
}
