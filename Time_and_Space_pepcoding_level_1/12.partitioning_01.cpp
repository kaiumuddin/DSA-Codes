#include<bits/stdc++.h>
using namespace std;

void partition(vector<int>& arr, int pivot, int lo, int hi)
{
    // small_eq , big, unknown

    // start/0 to j-1 <= pivot  // 0 region
    // j to i-1 > pivot         // 1 region
    // i to end/n => unknown

    // big index starts from j
    // pivot index in j-1

    int i = lo;
    int j = lo;

    while (i <= hi)
    {
        if (arr[i] == 1) // if(arr[i] > pivot), pivot = 0 // changes
        {
            i++;
        }
        else if (arr[i] == 0) // changes
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
}
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    partition(arr, 0, 0, n - 1); // pivot = 0

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
