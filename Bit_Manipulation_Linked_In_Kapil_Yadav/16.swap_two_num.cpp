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
    cout << " : "; cout << n << " : " << (char)n << endl;
}

void swap2Num(int& a, int& b)
{
    pb(a = a ^ b);
    pb(b = a ^ b);
    pb(a = a ^ b);
}

int main() {
    int a = 1;
    int b = 2;
    pb(a);
    pb(b);
    cout << "-------------------------------" << endl;
    swap2Num(a, b);
    cout << "-------------------------------" << endl;
    pb(a);
    pb(b);
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
