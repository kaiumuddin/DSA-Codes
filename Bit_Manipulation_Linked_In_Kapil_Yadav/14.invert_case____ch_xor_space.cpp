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
    cout << " : "; cout << n << " : " << (char)n << endl;
}

void invert_case(char ch, unsigned int k = 0)
{
    pb(ch);
    // 001000001 : 65 : A
    pb(' ');
    // 000100000 : 32 :
    pb(ch ^ ' ');
    // 001100001 : 97 : a
}

int main() {
    invert_case('A');
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
