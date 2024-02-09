#include <bits/stdc++.h>
using namespace std;

#define yes cout << "Yes" << endl
#define no cout << "No" << endl

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

void is_power_of_8(unsigned int n)
{
    if (n == 0) no;

    pb(n);
    // 001000000 : 64
    pb(0xB6DB6DB6);
    // 110110110 : 3067833782
    pb(n & 0xB6DB6DB6);
    // 000000000 : 0

    bool powerOf2 = (n & (n - 1)) == 0;
    bool mask = (n & 0xB6DB6DB6) == 0;

    if (powerOf2 && mask) yes;
    else no;
    cout << "-----------------------------------" << endl;
}

int main() {
    is_power_of_8(64);
}