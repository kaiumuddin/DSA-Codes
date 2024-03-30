#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void best(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();

        while (r < n)
        {
            if (nums[r] != 0)
            {
                swap(nums[l++], nums[r++]);
            }
            else
                r++;
        }
    }

    void best2(vector<int>& nums) {
        int writeIndex = 0;
        int n = nums.size();

        for (int i = 0; i < n;i++)
        {
            if (nums[i] != 0)
            {
                nums[writeIndex++] = nums[i];
            }
        }

        for (int i = writeIndex; i < n; i++)
        {
            nums[i] = 0;
        }
    }

    void moveZeroes(vector<int>& nums) {
        // best(nums);
        best2(nums);
    }
};

int main() {
    Solution solution;

    // Test case
    vector<int> nums = { 0, 1, 0, 3, 12 };

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
