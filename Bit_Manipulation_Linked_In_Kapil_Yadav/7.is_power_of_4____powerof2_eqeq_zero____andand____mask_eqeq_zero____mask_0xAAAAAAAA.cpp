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

void is_power_of_4(unsigned int n)
{
    if (n == 0) no;

    pb(n);
    pb(0xAAAAAAAA);
    pb(n & 0xAAAAAAAA);

    bool powerOf2 = (n & (n - 1)) == 0;
    bool mask = (n & 0xAAAAAAAA) == 0;

    if (powerOf2 && mask) yes;
    else no;
    cout << "-----------------------------------" << endl;
}

int main() {
    is_power_of_4(64);
}