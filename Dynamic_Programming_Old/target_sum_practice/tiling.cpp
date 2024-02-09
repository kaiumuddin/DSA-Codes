#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;

int tile(int n)
{
    if (n <= 2)
        return n;
    return tile(n - 1) + tile(n - 2);
}

int main() {

    cout << tile(4) << endl;
}