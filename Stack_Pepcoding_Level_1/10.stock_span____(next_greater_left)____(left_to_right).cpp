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
    vector<int> span(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        while (st.size() > 0 && arr[i] > arr[st.top()]) {
            st.pop();
        }

        if (st.size() == 0) {
            span[i] = i + 1;
        }
        else {
            span[i] = i - st.top();
        }

        st.push(i);
    }


    for (int v : span) cout << v << " ";
    cout << endl;
}

int main() {
    // solve({ 5,5,3,8,-2,7 });
    // solve({ 30, 35,40,30,20,10,1,2,3,4,5,6 });
    solve({ 2,5,9,3,1,12,6,8,7 });
}
// left to right
// boro asbe, chuto gulo pop korbe, chuto gulor ans boro ta hbe, boro ta nije push hbe,
// chuto asle, push