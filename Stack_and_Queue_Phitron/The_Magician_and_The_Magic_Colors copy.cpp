#include<bits/stdc++.h>
using namespace std;

char getMixColor(char a, char b) {
    if (a == 'R') {
        if (b == 'B') {
            return 'P';
        }
        else if (b == 'G') {
            return 'Y';
        }
    }
    else if (a == 'B') {
        if (b == 'R') {
            return 'P';
        }
        else if (b == 'G') {
            return 'C';
        }
    }
    else if (a == 'G') {
        if (b == 'R') {
            return 'Y';
        }
        else if (b == 'B') {
            return 'C';
        }
    }
}

void printStackRev(stack<char> st) {
    if (st.empty()) return;

    char top = st.top();
    st.pop();
    printStackRev(st);
    cout << top;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        stack<char> st;

        for (char color : s) {
            if (st.empty()) {
                st.push(color);
                continue;
            }

            char top = st.top();

            if (color == 'R' || color == 'G' || color == 'B') {
                if (top == 'R' || top == 'G' || top == 'B') {

                    if (color == top) {
                        st.pop();
                        continue;
                    }
                    else {
                        char mixColor = getMixColor(color, top);
                        st.pop();
                        st.push(mixColor);
                    }
                }
                else if (top == 'P' || top == 'C' || top == 'Y') {
                    st.push(color);
                }
            }
        }

        printStackRev(st);
        cout << endl;
    }
    return 0;
}