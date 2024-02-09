#include<bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int i = 0, int j = 0) {
    if (a[i] == '\0' || b[j] == '\0')
        return 0;
    else if (a[i] == b[j])
        return 1 + lcs(a, b, i + 1, j + 1);
    else
        return max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
}

int main()
{
    cout << lcs("kaimu", "aiu") << endl;

    return 0;
}