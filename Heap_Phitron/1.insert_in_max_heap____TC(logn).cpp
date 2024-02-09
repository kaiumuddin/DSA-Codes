#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& v, int x) { // logn
    v.push_back(x);

    int curr_idx = v.size() - 1;
    int parent_idx;

    while (curr_idx != 0)
    {
        parent_idx = (curr_idx - 1) / 2;
        
        if (v[parent_idx] < v[curr_idx])
            swap(v[parent_idx], v[curr_idx]);
        else
            break;

        curr_idx = parent_idx;
    }
}

int main() {
    // vector<int> v = { 50,40,45,30,35,42,32,25,20,10 };
    vector<int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        insert(v, x);
    }

    for (int i : v) cout << i << " ";
}