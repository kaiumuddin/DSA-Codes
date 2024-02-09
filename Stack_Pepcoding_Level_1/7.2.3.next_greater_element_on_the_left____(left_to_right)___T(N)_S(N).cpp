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

    st.push(arr[0]);
    nge[0] = -1;
    for (int i = 1;i < arr.size();i++) {
        while (st.size() > 0 && arr[i] >= st.top()) { // >= for next greater element on left
            st.pop();
        }

        if (st.size() == 0) {
            nge[i] = -1;
            st.push(arr[i]);
        }
        else {
            nge[i] = st.top();
            st.push(arr[i]);
        }
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