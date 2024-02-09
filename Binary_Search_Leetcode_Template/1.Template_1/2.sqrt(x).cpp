#include<bits/stdc++.h>
using namespace std;

void print_ss(int l, int m, int r) {
    for (int i = 0; i <= r; i++) {
        cout << i << "\t";
    }
    cout << endl;

    for (int i = 0; i <= r; i++) {
        if (i == l) cout << "l";
        if (i == m) cout << "m";
        if (i == r) cout << "r";

        cout << "\t";
    }
    cout << endl;
    cout << endl;
}

int binarySearch(int target) {

    long long left = 0, right = pow(2, 31) - 1;
    long long mid = left + (right - left) / 2;
    long long ans = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (mid * mid == target) {
            return mid;
        }
        else if (mid * mid < target) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    cout << binarySearch(8) << endl;
    return 0;
}