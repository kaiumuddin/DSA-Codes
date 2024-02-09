#include<bits/stdc++.h>
using namespace std;

void nearly(vector<int> a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // min Heap

    for (int i = 0; i <= k; i++) {
        pq.push(a[i]);
    }

    for (int i = k + 1; i < a.size(); i++) {
        cout << pq.top() << " ";
        pq.pop();
        pq.push(a[i]);
    }

    while (pq.size() > 0) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    nearly({ 2,3,1,4,6,7,5,8,9 }, 2); // nearly sorted 2 places
    return 0;
}

// all true
// val - 1 hole false
// startPoint teke calculate