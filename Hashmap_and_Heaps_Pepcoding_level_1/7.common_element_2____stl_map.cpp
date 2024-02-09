#include<bits/stdc++.h>
using namespace std;

void common_element(vector<int>a, vector<int>b) {
    map<int, int> mp;
    for (int val : a) {
        mp[val]++;
    }

    for (int val : b) {
        if (mp[val] > 0) {
            cout << val << " ";
            mp[val]--;
        }
    }
}

int main() {
    common_element({ 1,1,2,2,2,3,5 }, { 1,1,1,2,2,4,5 });
    return 0;
}