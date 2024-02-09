#include<bits/stdc++.h>
using namespace std;

int lcsub(string a, string b, int i = 0, int j = 0, int count = 0)
{
    if (a[i] == '\0' || b[j] == '\0')
        return count;
    if (a[i] == b[j])
        count = lcsub(a, b, i + 1, j + 1, count + 1);
    int count1 = lcsub(a, b, i + 1, j, 0);
    int count2 = lcsub(a, b, i, j + 1, 0);
    return max(count, max(count1, count2));
}

int main()
{
    cout << lcsub("abcd", "bcd");
    return 0;
}