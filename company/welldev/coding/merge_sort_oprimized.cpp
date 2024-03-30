#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy the remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r)
{
    if (l >= r)
        return;

    // int mid = l + (r - l) / 2;
    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int main()
{
    vector<int> arr = { 2,5,3,10,1 };

    mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
