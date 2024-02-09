#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> a = { 1,4,2,6,4,7,5,7 };
    // a.remove(7); // sob remove krbe
    // a.sort();
    a.sort(greater<int>());
    a.unique();

    

    for (int val : a) cout << val << " ";
    return 0;
}