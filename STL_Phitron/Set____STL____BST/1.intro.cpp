#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> s; // sorted // no duplicates
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        s.insert(x); // O(logN)
    }

    for (int e : s) {
        cout << e << endl;
    }

    for (auto i = s.rbegin(); i != s.rend(); i++) {
        cout << *i << endl;
    }

    s.count(100); // O(logN)
    return 0;
}