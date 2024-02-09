#include <bits/stdc++.h>
using namespace std;

#define yes cout << "Yes" << endl
#define no cout << "No" << endl

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

void check_if_number_is_power_of_2(unsigned int n)
{
    pb(n);
    pb(n - 1);
    pb(n & (n - 1));

    if ((n & (n - 1)) == 0)
        yes;
    else
        no;
    printf("--------------------------------\n");
}

int main() {
    check_if_number_is_power_of_2(1);
    check_if_number_is_power_of_2(2);
    check_if_number_is_power_of_2(3);
    check_if_number_is_power_of_2(4);
    check_if_number_is_power_of_2(12);
    check_if_number_is_power_of_2(16);
}