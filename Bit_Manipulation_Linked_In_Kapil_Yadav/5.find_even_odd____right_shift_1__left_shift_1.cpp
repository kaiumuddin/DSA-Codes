#include <bits/stdc++.h>
using namespace std;

void pb(unsigned int n)
{
    // print integer in binary
    for (int i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
            cout << 1;
        else cout << 0;
    }
    cout << " : "; cout << n << endl;
}

void find_even_odd_bitwise_and(unsigned int n)
{
    pb(n);
    pb(n & 1);
}

void find_even_odd_left_and_right_shift(unsigned int n)
{
    pb(n);
    pb((n >> 1) << 1);
}

int main() {
    find_even_odd_bitwise_and(15);
    printf("--------------------------------\n");
    find_even_odd_left_and_right_shift(2); // even if n == n, after operator shift
    find_even_odd_left_and_right_shift(1); // odd if n != n, after operator shift
    return 0;
}