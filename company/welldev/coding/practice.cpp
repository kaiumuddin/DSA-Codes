#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& left, vector<int>& right)
{
    vector<int> merged(left.size() + right.size());

    int i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }

    while (i < left.size())
        merged[k++] = left[i++];

    while (j < right.size())
        merged[k++] = right[j++];

    return merged;
}

vector<int> mergeSort(vector<int>& nums, int left_index, int right_index)
{
    if (left_index >= right_index) {
        return { nums[left_index] };
    }

    int mid_index = (left_index + right_index) / 2;

    vector<int> left_sorted_half = mergeSort(nums, left_index, mid_index);
    vector<int> right_sorted_half = mergeSort(nums, mid_index + 1, right_index);


    vector<int> merged = merge(left_sorted_half, right_sorted_half);

    return merged;
}

int main() {
    vector<int> nums = { 2,5,3,10,1,4,7 };

    vector<int> sortedNums = mergeSort(nums, 0, nums.size() - 1);

    for (int num : sortedNums) cout << num << " ";
}
