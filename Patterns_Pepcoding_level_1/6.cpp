#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int sp = n / 2;
    int st = 1;

    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= sp; i++) {
            cout << "\t";
        }
        for (int i = 1; i <= st; i++) {
            cout << "*\t";
        }
        cout << endl;

        if (i <= n / 2) {
            sp--;
            st += 2;
        }
        else {
            sp++;
            st -= 2;
        }
    }
}

//                 *
//         *       *       *
// *       *       *       *       *
//         *       *       *
//                 *