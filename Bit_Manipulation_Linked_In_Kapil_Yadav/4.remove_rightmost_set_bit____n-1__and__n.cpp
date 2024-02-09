#include <bits/stdc++.h>
using namespace std;

void pb(unsigned int n)
{
    // print integer in binary
    for (int i = 8; i >= 0; i--)
    {
        if (n & (1 << i))
            cout << 1;
        else cout << 0;
    }
    cout << " : "; cout << n << endl;
}

void remove_rightmost_set_bit(unsigned int n)
{
    pb(n);
    // 000001001 : 9
    pb(n - 1);
    // 000001000 : 8
    pb(n & (n - 1));
    // 000001000 : 8
}

void print_(unsigned int n) {
    for (int i = 0; i < n; i++) {
        pb(i);
    }
}

int main() {
    // print_(10); cout << endl;
    remove_rightmost_set_bit(12);
    return 0;
}

// and 
// 0 & 0 = 0
// 0 & 1 = 0 // clear
// 1 & 0 = 0 // clear
// 1 & 1 = 1 // check

// or 
// 0 | 0 = 0
// 0 | 1 = 1 // set
// 1 | 0 = 1 
// 1 | 1 = 1 // set

// xor 
// 0 ^ 0 = 0
// 0 ^ 1 = 1 // flip
// 1 ^ 0 = 1
// 1 ^ 1 = 0 // flip