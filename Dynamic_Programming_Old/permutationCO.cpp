#include <bits/stdc++.h>
using namespace std;

int permutationCo(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0)
        return 1;

    return k * permutationCo(n - 1, k - 1) + permutationCo(n - 1, k);
}

int main()
{
    cout << permutationCo(3, 0) << endl;
    cout << permutationCo(3, 1) << endl;
    cout << permutationCo(3, 2) << endl;
    cout << permutationCo(3, 3) << endl;

    return 0;
}