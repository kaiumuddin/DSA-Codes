#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int pivot, int lo, int hi)
{
    // small_eq , big, unknown

    // start/0 to j-1 <= pivot
    // j to i-1 > pivot
    // i to end/n => unknown

    // big index starts from j
    // pivot index in j-1

    int i = lo;
    int j = lo;

    while (i <= hi)
    {
        if (arr[i] > pivot)
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }

    return j - 1;
}

// kth smallest number
int quickselect(vector<int>& arr, int lo, int hi, int k)
{
    int pivot = arr[hi];
    int pi = partition(arr, pivot, lo, hi);

    if (k > pi) {
        return quickselect(arr, pi + 1, hi, k);
    }
    else if (k < pi) {
        return quickselect(arr, lo, pi - 1, k);
    }
    else
        return arr[pi];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << partition(arr, arr[n - 1], 0, n - 1) << endl;
    int element = quickselect(arr, 0, n - 1, k - 1);
    cout << element << endl;

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
