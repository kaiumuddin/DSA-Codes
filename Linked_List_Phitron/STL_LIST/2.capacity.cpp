#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> a = { 10,20,30 };
    cout << a.max_size() << endl;
    cout << a.max_size() / 2 << endl;
    // a.clear();
    a.resize(2);
    a.resize(5, 34);
    for (int val : a) cout << val << endl;

    return 0;
}