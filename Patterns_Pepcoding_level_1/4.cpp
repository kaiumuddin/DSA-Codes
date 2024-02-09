#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int sp = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (j <= sp ? "\t" : "*\t");
        }
        sp++;
        cout << endl;
    }
}

// *       *       *       *       *
//         *       *       *       *
//                 *       *       *
//                         *       *
//                                 *