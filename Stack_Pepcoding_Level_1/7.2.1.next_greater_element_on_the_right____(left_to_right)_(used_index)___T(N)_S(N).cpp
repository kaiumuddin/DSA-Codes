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
    stack<int> st;
    vector<int> nge(arr.size());

    st.push(0);
    for (int i = 0;i < arr.size();i++) {
        while (st.size() > 0 && arr[i] > arr[st.top()]) { // > for next greater element
            int index = st.top();
            nge[index] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    while (st.size() > 0) {
        int index = st.top();
        nge[index] = -1;
        st.pop();
    }

    for (int v : nge) cout << v << " ";
    cout << endl;
}

int main() {
    // solve({ 5,5,3,8,-2,7 });
    solve({ 30, 35,40,30,20,10,1,2,3,4,5,6 });
}
// left to right
// boro asbe, chuto gulo pop korbe, chuto gulor ans boro ta hbe, boro ta nije push hbe,
// chuto asle, push