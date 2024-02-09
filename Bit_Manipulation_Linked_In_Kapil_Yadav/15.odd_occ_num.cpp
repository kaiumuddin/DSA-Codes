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

void getOddOccur(vector<int> arr)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res = res ^ arr[i];
    }
    cout << res << endl;
}

int main() {
    pb(5);
    pb(3);
    pb(5);
    pb(5 ^ 5 ^ 3);
    // getOddOccur({ 5,5,2,2,3 });
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
