#include <bits/stdc++.h>
using namespace std;

void pb(unsigned int n)
{
    // print integer in binary
    for (int i = 3; i >= 0; i--)
    {
        if (n & (1 << i))
            cout << 1;
        else cout << 0;
    }
    cout << " : "; cout << n << endl;
}

void toggle_kth_bit_set(unsigned int n, unsigned int k = 0)
{
    pb(n);
    // 1000 : 8
    pb(1 << k - 1);
    // 0100 : 4
    pb(n ^ (1 << k - 1));
    // 1100 : 12
}

int main() {
    toggle_kth_bit_set(8, 3);
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
// 0 ^ 1 = 1 // flip/toggle
// 1 ^ 0 = 1
// 1 ^ 1 = 0 // flip/toggle
