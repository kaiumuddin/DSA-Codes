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

void solve(string str) {
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);

        if (ch == ')')
        {
            if (st.top() == '(')
            {
                cout << "Duplicate Exits" << endl;
                return;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }

    cout << "Duplicate Not Exits" << endl;
}

int main() {

    stack<int> st;
    printStack(st);
    solve("(a+b)");
    solve("((a+b))");
    return 0;
}