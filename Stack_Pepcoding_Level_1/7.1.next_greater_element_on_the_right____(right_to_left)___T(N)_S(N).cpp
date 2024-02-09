#include<bits/stdc++.h>
using namespace std;

void printStack(stack<char>& st) {
    if (st.empty()) return;

    char val = st.top();
    st.pop();
    cout << val << "";

    printStack(st);

    st.push(val);
}

void solve(vector<int> arr) {
    stack<char> st;
    vector<int> nge(arr.size());

    st.push(arr.back());
    nge[arr.size() - 1] = -1;

    for (int i = arr.size() - 2; i >= 0; i--) {
        // pop ans push
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.size() == 0)
            nge[i] = -1;
        else
            nge[i] = st.top();

        st.push(arr[i]);
    }

    for (int v : nge) cout << v << " ";
    cout << endl;
}

int main() {
    solve({ 5,5,3,8,-2,7 });
    solve({ 30, 35,40,30,20,10,1,2,3,4,5,6 });
}