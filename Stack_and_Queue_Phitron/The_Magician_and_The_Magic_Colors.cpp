#include<bits/stdc++.h>
using namespace std;

char mix2color(char a, char b) {
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

    return 'X';
}

void printStackInRev(stack<char> st) {
    if (st.empty()) return;

    char top = st.top();
    st.pop();
    printStackInRev(st);
    cout << top;
}

void singleCase() {
    int x;
    cin >> x;
    string s;
    cin >> s;

    stack<char> st;

    char last = s.back();
    bool odd = false;
    if (x % 2 == 1) {
        x--;
        odd = true;
    }
    for (int i = 0; i < x; i += 2) {
        if (s[i] == s[i + 1]) {
            continue;
        }
        char mixColor = mix2color(s[i], s[i + 1]);
        if (st.empty()) {
            st.push(mixColor);
            continue;
        }

        if (st.top() == mixColor) {
            st.pop();
            continue;
        }
        else {
            st.push(mixColor);
        }
    }

    if (odd) {
        st.push(last);
    }
    printStackInRev(st);
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        singleCase();
    }

    return 0;
}
