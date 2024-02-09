#include<bits/stdc++.h>
using namespace std;


// n element, n-1 iteration
// reverse bubble

// stable : sequence of same element is like previous
// in place: no extra space
// online : ekta element notun ashlei sathe sathe kaj suru kre.

vector<int> mergeTwoSortedArrays(vector<int>& a, vector<int>& b)
{
    vector<int> res(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
    }

    while (i < a.size()) res[k++] = a[i++];
    while (j < b.size()) res[k++] = b[j++];

    return res;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a(m);
    vector<int> b(n);

    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> res = mergeTwoSortedArrays(a, b);
    for (int i = 0; i < (m + n); i++) cout << res[i] << " ";
}
