#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr) {
    map<int, int> mp; // sum, index

    mp[0] = -1;


    int sum = 0;
    int maxLength = 0;

    int i = 0;
    while (i < arr.size()) {
        sum += arr[i];

        if (mp.count(sum) == 0) {
            mp[sum] = i;
        }
        else {
            int len = i - mp[sum];
            maxLength = max(len, maxLength);
        }

        i++;
    }

    cout << maxLength << endl;
}

int main() {
    solve({ 2,8,-3,-5,2,-4,6,1,2,1,-3,4 });
    return 0;
}