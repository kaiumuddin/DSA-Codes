#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> a = { 10,20,30,40 ,50 };

    // list<int> b;
    // b = a;
    // for (int val : b) cout << val << endl;

    list<int> c;
    c.assign(a.begin(), a.end());

    c.push_back(100);
    c.pop_back();
    c.push_front(200);
    c.pop_front();
    // for (int val : c) cout << val << endl;

    a.insert(next(a.begin(), 2), 1000);
    a.insert(next(a.begin(), 7), 1000); // cyclic gurbe, ghure samne cole jbe;
    for (int val : a) cout << val << endl;

    cout << endl;
    a.erase(next(a.begin(), 2));
    for (int val : a) cout << val << endl;

    a.insert(next(a.begin(), 2), { 1,2,4 });
    a.insert(next(a.begin(), 2), c.begin(), c.end()); // O(n + k);

    a.erase(next(a.begin(), 2), next(a.begin(), 5));

    replace(a.begin(), a.end(), 10, 143);

    auto it = find(a.begin(), a.end(), 60);
    if (it != a.end()) cout << "found" << endl;

    return 0;
}