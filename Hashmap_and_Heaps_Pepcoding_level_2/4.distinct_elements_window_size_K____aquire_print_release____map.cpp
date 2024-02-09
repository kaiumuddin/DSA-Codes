#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int k) {
    map<int, int> mp; // k size frequency map

    for (int i = 0; i < k - 1; i++) {
        mp[arr[i]]++;
    }

    int j = 0;
    int i = k - 1;
    while (i < arr.size()) {
        mp[arr[i]]++; // aquire
        cout << mp.size() << " "; // print

        if (mp[arr[j]] == 1) {
            mp.erase(arr[j]); // release
        }
        else {
            mp[arr[j]]--; // release
        }
        i++;
        j++;
    }
}

int main() {
    solve({ 2,5,5,6,3,2,3,2,4,5,2,2,2,2,5,6 }, 4);
    return 0;
}