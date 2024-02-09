#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& v, int x) { // logn
    v.push_back(x);

    int curr_idx = v.size() - 1;
    int parent_idx;

    while (curr_idx != 0) {
        parent_idx = (curr_idx - 1) / 2;
        if (v[parent_idx] < v[curr_idx]) {
            swap(v[parent_idx], v[curr_idx]);
        }
        else break;
        curr_idx = parent_idx;
    }
}

void delete_heap(vector<int>& v) {
    v[0] = v.back();
    v.pop_back();

    int curr = 0;

    while (1) {
        int li = curr * 2 + 1;
        int ri = curr * 2 + 2;

        int last_idx = v.size() - 1;

        if (li <= last_idx && ri <= last_idx)
        {
            if (v[li] > v[ri] && v[li] > v[curr]) {
                swap(v[li], v[curr]);
                curr = li;
            }
            else if (v[ri] > v[li] && v[ri] > v[curr]) {
                swap(v[ri], v[curr]);
                curr = ri;
            }
        }
        else if (li <= last_idx) {
            if (v[li] > v[curr]) {
                swap(v[li], v[curr]);
                curr = li;
            }
            else {
                break;
            }
        }
        else if (ri <= last_idx) {
            if (v[ri] > v[curr]) {
                swap(v[ri], v[curr]);
                curr = ri;
            }
            else {
                break;
            }
        }
        else break;
    }

    for (int i : v) cout << i << " ";
    cout << endl;
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
    cout << endl;

    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
    delete_heap(v);
}