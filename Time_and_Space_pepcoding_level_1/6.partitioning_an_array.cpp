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
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << partition(arr, arr[n - 1], 0, n - 1) << endl;

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
