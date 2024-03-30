#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& fsh, vector<int>& ssh)
{
    vector<int> merged(fsh.size() + ssh.size());

    int l = 0, r = 0, k = 0;

    while (l < fsh.size() && r < ssh.size())
    {
        if (fsh[l] < ssh[r])
            merged[k++] = fsh[l++];
        else
            merged[k++] = ssh[r++];
    }

    while (l < fsh.size()) merged[k++] = fsh[l++];
    while (r < ssh.size()) merged[k++] = ssh[r++];

    return merged;
}

vector<int> mergeSort(vector<int>& arr, int l, int r)
{
    if (l >= r)
    {
        vector<int> baseArr = { arr[l] };
        return baseArr;
    }

    int mid = (l + r) / 2;

    vector<int> firstSortedHalf = mergeSort(arr, l, mid);
    vector<int> secondSortedHalf = mergeSort(arr, mid + 1, r);

    vector<int> merged = merge(firstSortedHalf, secondSortedHalf);

    return merged;
}

int main()
{
    vector<int> arr = { 2,5,3,10,1,4,7 };

    vector<int> sorted = mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < sorted.size(); i++)
        cout << sorted[i] << " ";
}