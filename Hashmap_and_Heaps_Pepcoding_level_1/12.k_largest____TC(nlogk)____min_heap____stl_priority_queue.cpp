#include<bits/stdc++.h>
using namespace std;

void k_largest(vector<int> a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // min Heap

    for (int i = 0; i < a.size(); i++) {
        if (i < k) {
            pq.push(a[i]);
        }
        else {
            if (a[i] > pq.top()) {
                pq.pop();
                pq.push(a[i]);
            }
        }
    }

    while (pq.size() > 0) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    k_largest({ 2,10,5,17,7,18,6,4 }, 3);
    return 0;
}

// all true
// val - 1 hole false
// startPoint teke calculate