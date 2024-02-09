#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> a;

    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        a.push_back(x);
    }

    a.sort();
    a.unique();
    for (int val : a) cout << val << " ";

    return 0;
}