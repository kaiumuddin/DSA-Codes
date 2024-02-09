#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 10e6;
    for (int i = 1; i <= n; i *= 2) {
        cout << i << endl;
    }

    for (int i = n; i >= 1; i /= 2) {
        cout << i << endl;
    }

    return 0;
}