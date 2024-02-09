#include<bits/stdc++.h>
using namespace std;

// max - min == i - j
bool solve(vector<int> arr) {
    map<int, int> mp; // sum, frequency
    int ans = 0;

    for (int i = 0; i < arr.size() - 1; i++) {
        int mini = arr[i];
        int maxi = arr[i];

        set<int> dup;
        dup.insert(arr[i]);

        for (int j = i + 1; j < arr.size(); j++) {
            if (dup.count(arr[j])) {
                break;
            }
            dup.insert(arr[j]);

            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);

            if (maxi - mini == j - i) {
                int len = j - i + 1;
                if (len > ans) {
                    ans = len;
                }
            }
        }
    }

    cout << ans << endl;

}

int main() {
    solve({ 9,2,7,5,6,23,24,22,23,19,17,16,18,39,0 });
    return 0;
}