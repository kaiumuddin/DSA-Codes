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

bool handleClosing(stack<char>& st, char opening) {
    if (st.size() == 0) {
        return false;
    }
    else if (st.top() != opening) {
        return false;
    }
    else {
        st.pop();
    }

    return true;
}

void solve(string str) {
    stack<char> st;
    bool ans = true;

    for (auto ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')') {
            ans = handleClosing(st, '(');
        }
        else if (ch == '}') {
            ans = handleClosing(st, '{');
        }
        else if (ch == ']') {
            ans = handleClosing(st, '[');
        }

        if (ans == false) {
            cout << false << endl;
            return;
        }
    }

    if (st.size() == 0) {
        cout << true << endl;
    }
    else {
        cout << false << endl;
    }

    printStack(st);
    // cout << endl;

}

int main() {
    solve("(a+b)");
    solve("[a+(b-a)]");
    solve("[a+(b-a]");
    return 0;
}