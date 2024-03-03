#include <iostream>
#include <vector>

using namespace std;

int upperBound(vector<int>& arr, int x, int n) {
    int l = 0;
    int r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] <= x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return l;
}

int main() {
    vector<int> arr = { 1, 2, 4, 4, 4, 6, 7 };
    int x = 4;
    int n = arr.size();

    int result = upperBound(arr, x, n);

    cout << "Upper bound of " << x << " in the array is at index: " << result << endl;

    return 0;
}
