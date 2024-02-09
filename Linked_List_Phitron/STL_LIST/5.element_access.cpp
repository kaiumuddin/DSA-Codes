#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> a = { 1,3,5,6,7,8 };
    cout << a.front() << endl;
    cout << a.back() << endl;
    cout << *next(a.begin(), 3) << endl;
    return 0;
}