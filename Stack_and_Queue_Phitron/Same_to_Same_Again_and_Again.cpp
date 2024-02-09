#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    queue<int> q;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    if (st.size() != q.size()) {
        cout << "NO" << endl;
        return 0;
    }

    list<int> a;
    list<int> b;

    while (!st.empty()) {
        a.push_back(st.top());
        st.pop();
    }
    while (!q.empty()) {
        b.push_back(q.front());
        q.pop();
    }

    auto ai = a.begin();
    auto bi = b.begin();

    while (ai != a.end() && bi != b.end()) {
        if (*ai != *bi) {
            cout << "NO" << endl;
            return 0;
        }
        ai++;
        bi++;
    }
    cout << "YES" << endl;

    return 0;
}