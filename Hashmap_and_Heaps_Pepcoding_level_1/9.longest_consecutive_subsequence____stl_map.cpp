#include<bits/stdc++.h>
using namespace std;

void longest(vector<int>a) {
    map<int, bool> mp;
    for (int val : a) {
        mp[val] = true;
    }

    for (int val : a) {
        if (mp.count(val - 1) > 0) {
            mp[val] = false;
        }
    }

    int maxLength = 0;
    int maxStartPoint = 0;
    for (int val : a) {
        if (mp.at(val) == true) {
            int tempLength = 1;
            int tempStartPoint = val;

            while (mp.count(tempStartPoint + tempLength)) {
                tempLength++;
            }

            if (tempLength > maxLength) {
                maxLength = tempLength;
                maxStartPoint = tempStartPoint;
            }
        }
    }

    for (int i = 0; i < maxLength; i++) {
        cout << maxStartPoint + i << " ";
    }
}

int main() {
    longest({ 10,5,9,1,11,8,6,15,3,12,2 });
    return 0;
}

// all true
// val - 1 hole false
// startPoint teke calculate