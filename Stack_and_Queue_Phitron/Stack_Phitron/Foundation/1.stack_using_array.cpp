#include<bits/stdc++.h>
using namespace std;

class myStack
{
public:
    vector<int> v;
    void push(int val) {
        v.push_back(val); // O(1)
    }
    void pop() {
        v.pop_back(); // O(1)
    }
    int top() {
        return v.back(); // O(1)
    }
    int size() {
        return v.size(); // O(1)
    }
    bool empty() {
        return v.empty(); // O(1)
    }
};

void printStack(myStack st) {
    if (st.empty()) return;

    int val = st.top();
    cout << val << endl;
    st.pop();

    printStack(st);

    st.push(val);
}
void printStackRev(myStack st) {
    if (st.empty()) return;

    int val = st.top();
    st.pop();

    printStackRev(st);

    cout << val << endl;
    st.push(val);
}

int main() {
    myStack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    printStackRev(st);

    return 0;
}