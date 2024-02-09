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

vector<int> nextSmallerRight(vector<int> arr) {
    stack<int> st;
    vector<int> rb(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (st.size() > 0 && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.size() == 0) {
            rb[i] = arr.size();
        }
        else {
            rb[i] = st.top();
        }
        st.push(i);
    }

    for (int v : rb) cout << arr[v] << " ";
    cout << endl;
    return rb;
}

vector<int> nextSmallerLeft(vector<int> arr) {
    stack<int> st;
    vector<int> lb(arr.size());

    for (int i = 0;i < arr.size(); i++) {
        while (st.size() > 0 && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.size() == 0) {
            lb[i] = -1;
        }
        else {
            lb[i] = st.top();
        }
        st.push(i);
    }

    for (int v : lb) cout << arr[v] << " ";
    cout << endl;
    return lb;
}

void largestAreaHistogram(vector<int> his) {
    vector<int> rb = nextSmallerRight(his);
    vector<int> lb = nextSmallerLeft(his);

    int maxArea = 0;
    for (int i = 0; i < his.size(); i++) {
        int width = rb[i] - lb[i] - 1;
        int area = his[i] * width;
        maxArea = max(maxArea, area);
    }

    cout << "Max area: " << maxArea << endl;
}

int main() {
    // nextSmallerRight({ 6,2,5,4,5,1,6 });
    // nextSmallerLeft({ 6,2,5,4,5,1,6 });
    largestAreaHistogram({ 6,2,5,4,5,1,6 }); // ans : 12
}
// left to right
// boro asbe, chuto gulo pop korbe, chuto gulor ans boro ta hbe, boro ta nije push hbe,
// chuto asle, push