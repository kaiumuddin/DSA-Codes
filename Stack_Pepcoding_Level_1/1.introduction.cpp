#include<bits/stdc++.h>
using namespace std;


void printStack(stack<int>& st) {
    if (st.empty()) return;

    int val = st.top();
    st.pop();
    cout << val << " ";

    printStack(st);

    st.push(val);
}

void solve() {

}

int main() {

    stack<int> st;
    printStack(st);

    return 0;
}