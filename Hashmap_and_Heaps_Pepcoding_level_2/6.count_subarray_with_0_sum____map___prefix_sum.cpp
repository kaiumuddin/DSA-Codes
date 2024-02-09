#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr) {
    map<int, int> mp; // sum, frequency

    mp[0] = 1;

    int sum = 0;
    int count = 0;

    int i = 0;
    while (i < arr.size()) {
        sum += arr[i];

        if (mp.count(sum)) {
            count += mp[sum];
        }
        mp[sum]++;

        i++;
    }
    cout << count << endl;
}

int main() {
    solve({ 2,8,-3,-5,2,-4,6,1,2,1,-3,4 });
    solve({ 2,8,-3,-5,2,-4,6,1,2,1,-3,4, -1,-3 });
    return 0;
}