#include<bits/stdc++.h>
using namespace std;

void print_ss(vector<int> a, int l, int m, int r) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < a.size(); i++) {
        if (i == l) cout << "l";
        if (i == m) cout << "m";
        if (i == r) cout << "r";

        cout << "\t";
    }
    cout << endl;
    cout << endl;
}

void v1(vector<int>& a, int x) {
    printf("_____ version 1 ____ l<=r ____ \n\n");

    int l = 0,
        r = a.size() - 1,
        m = (l + r) / 2;

    while (l <= r) {
        m = (l + r) / 2;
        print_ss(a, l, m, r);
        if (x > a[m]) l = m + 1;
        else r = m - 1;
    }
    print_ss(a, l, m, r);
}

void v2(vector<int>& a, int x) {
    printf("_____ version 2 ____ l<r ____ \n\n");

    int l = 0,
        r = a.size() - 1,
        m = (l + r) / 2;

    while (l < r) {
        m = (l + r) / 2;
        // print_ss(a, l, m, r);
        if (x > a[m]) l = m + 1;
        else r = m;
    }
    print_ss(a, l, m, r);
}


void v3(vector<int>& a, int x) {
    printf("_____ version 3 ____ l+1<r ____ \n\n");

    int l = 0,
        r = a.size() - 1,
        m = (l + r) / 2;

    while (l + 1 < r) {
        m = (l + r) / 2;
        // print_ss(a, l, m, r);
        if (x > a[m]) l = m;
        else r = m;
    }
    print_ss(a, l, m, r);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    v1(a, x);
    // v2(a, x);
    // v3(a, x);

    return 0;
}