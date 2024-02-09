#include<bits/stdc++.h>
using namespace std;

class median_pq {
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

    void add(int val) {
        if (right.size() > 0 && val > right.top()) {
            right.push(val);
        }
        else {
            left.push(val);
        }

        if (left.size() - right.size() == 2) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() - left.size() == 2) {
            left.push(right.top());
            right.pop();
        }
    }

    int remove() {
        if (this->size() == 0) {
            cout << "Underflow" << endl;
            return -1;
        }
        else if (left.size() >= right.size()) {
            int top = left.top();
            left.pop();
            return top;
        }
        else {
            int top = right.top();
            right.pop();
            return top;
        }
    }

    int peek() {
        if (this->size() == 0) {
            cout << "Underflow" << endl;
            return -1;
        }
        else if (left.size() >= right.size()) {
            return left.top();
        }
        else {
            return right.top();
        }
    }

    int size() {
        return left.size() + right.size();
    }
};

int main() {

    return 0;
}