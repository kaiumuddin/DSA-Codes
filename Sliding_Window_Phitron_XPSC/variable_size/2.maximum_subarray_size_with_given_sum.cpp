#include <iostream>
#include <vector>

using namespace std;


int max_subarray_size(vector<int>& arr, int k) {
    int l = 0;
    int r = 0;

    int s = 0;
    int ans = 0;

    while (r < arr.size()) {
        s += arr[r]; 

        while (s > k) {
            s -= arr[l];
            l++;
        }

        if (s == k) {
            ans = max(ans, r - l + 1);
        }

        r++;
    }

    return ans;
}

int main() {

    vector<int> arr = { 3,2,1,1,2,2,5 };
    int k = 5;
    int result = max_subarray_size(arr, k);
    cout << "max subarray size with sum " << k << ": " << result
        << endl;
    return 0;
}
