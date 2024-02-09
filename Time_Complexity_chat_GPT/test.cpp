#include<bits/stdc++.h>
using namespace std;
void pv(vector<int>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    vector<int> v = { 1,2,3,4,5 };
    v.erase(v.begin() + 2, v.end());
    pv(v);
}