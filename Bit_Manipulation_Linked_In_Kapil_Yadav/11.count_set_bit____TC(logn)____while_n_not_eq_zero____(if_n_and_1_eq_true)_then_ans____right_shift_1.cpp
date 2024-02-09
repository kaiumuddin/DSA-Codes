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

void count_set_bits(unsigned int n, unsigned int k = 0)
{
    unsigned int count = 0;
    while (n != 0) {
        pb(n);
        if (n & 1 == 1) count++;
        n >>= 1;
    }

    cout << count << endl;
}

int main() {
    count_set_bits(15);
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
