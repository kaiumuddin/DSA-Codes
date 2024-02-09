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

void clear_ith_bit(unsigned int n, unsigned int k = 0)
{
    pb(n);
    // 000000111 : 7
    pb(1 << k - 1);
    // 000000001 : 1
    pb(~(1 << k - 1));
    // 111111110 : 4294967294
    pb(n & ~(1 << k - 1));
    // 000000110 : 6
}

int main() {
    clear_ith_bit(7, 1);
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