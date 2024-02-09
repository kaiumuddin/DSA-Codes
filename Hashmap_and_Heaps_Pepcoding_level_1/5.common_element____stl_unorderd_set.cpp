#include<bits/stdc++.h>
using namespace std;

void common_element(vector<int>a, vector<int>b) {
    unordered_set<int> us;
    for (int val : a) {
        us.insert(val);
    }

    for (int val : b) {
        if (us.count(val) > 0) {
            cout << val << " ";
            us.erase(val);
        }
    }
}

int main() {
    common_element({ 1,1,2,2,2,4,5,6 }, { 1,2,2,3,5 });
    return 0;
}