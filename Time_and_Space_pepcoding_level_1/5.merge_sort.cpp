#include<bits/stdc++.h>
using namespace std;


vector<int> mergeTwoSortedArrays(vector<int>& a, vector<int>& b)
{
    vector<int> res(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
    }

    while (i < a.size()) res[k++] = a[i++];
    while (j < b.size()) res[k++] = b[j++];

    return res;
}

vector<int> mergeSort(vector<int>& arr, int l, int r)
{
    if (l >= r) {
        vector<int> ba = { arr[l] };
        return ba;
    }

    int m = (l + r) / 2;
    vector<int> fsh = mergeSort(arr, l, m);
    vector<int> ssh = mergeSort(arr, m + 1, r);

    vector<int> fsa = mergeTwoSortedArrays(fsh, ssh);
    return fsa;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> res = mergeSort(a, 0, n);

    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
