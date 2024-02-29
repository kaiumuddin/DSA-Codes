#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x, ans = x;

        while (l <= r) {
            long mid = l + (r - l) / 2;

            if (x == mid * mid) {
                return mid;
            } else if (x < mid * mid) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Test case
    int x = 8;

    cout << "Square root of " << x << " is: " << solution.mySqrt(x) << endl;

    return 0;
}
