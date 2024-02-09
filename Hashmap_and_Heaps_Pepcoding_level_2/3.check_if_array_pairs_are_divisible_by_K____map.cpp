#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> nums, int k) {
    map<int, int> mp; // remainder frequency map

    for (int val : nums) {
        mp[val % k]++;
    }

    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }

    for (int val : nums) {
        int rem = val % k;

        if (rem == 0) {
            if (mp[rem] % 2 == 1) {
                return false;
            }
        }
        else if (2 * rem == k) {
            if (mp[rem] % 2 == 1) {
                return false;
            }
        }
        else {
            int fq = mp[rem];
            int ofq = mp[k - rem];

            if (fq != ofq) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    cout << check({ 9,56,25,52,72,44,80,36,71,55,60 }, 8) << endl;
    cout << check({ 22,12,45,55,65,78,88 }, 10) << endl;
    return 0;
}