#include<bits/stdc++.h>
using namespace std;

class myQueue {
public:
    list<int> l;

    void push(int val) {
        l.push_back(val);
    }

    void pop() {
        l.pop_front();
    }

    int front() {
        return l.front();
    }
    int size() {
        return l.size();
    }
    bool empty() {
        return l.empty();
    }
};

int main() {
    myQueue q;
    q.push(10);
    q.push(20);
    q.push(40);
    q.push(30);
    while (q.size()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}