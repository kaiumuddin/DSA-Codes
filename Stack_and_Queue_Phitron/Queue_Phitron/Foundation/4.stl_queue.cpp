#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(30);
    q.push(20);
    q.push(40);
    while (q.size()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}