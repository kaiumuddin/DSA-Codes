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

void set_ith_bit(unsigned int n, unsigned int k = 0)
{
    pb(n);
    // 000001101 : 13
    pb(1 << k - 1);
    // 000000010 : 2
    pb(n | (1 << k - 1));
    // 000001111 : 15
}

int main() {
    set_ith_bit(13, 2);
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
