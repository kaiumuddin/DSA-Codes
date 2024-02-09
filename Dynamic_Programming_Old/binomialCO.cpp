#include <bits/stdc++.h>
using namespace std;

int binomialCo(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0 || n == k)
        return 1;

    return binomialCo(n - 1, k - 1) + binomialCo(n - 1, k);
}

int main()
{
    cout << binomialCo(3, 0) << endl;
    cout << binomialCo(3, 1) << endl;
    cout << binomialCo(3, 2) << endl;
    cout << binomialCo(3, 3) << endl;
    // cout << binomialCo(140, 88) << endl;

    return 0;
}