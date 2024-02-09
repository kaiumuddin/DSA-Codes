#include<bits/stdc++.h>
using namespace std;

void partition(vector<int>& arr, int lo, int hi)
{
    // small_eq , big, unknown

    // start/0 to j-1 <= pivot  // 0 region
    // j to i-1 > pivot         // 1 region
    // i to k => unknown                    // changes
    // k+1 to end/n => 2        // 2 region // changes

    // big index starts from j
    // pivot index in j-1

    int j = lo;
    int i = lo;
    int k = hi;

    while (i <= k) // until any unknown // changes
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[k]);
            k--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    partition(arr, 0, n - 1); // changes

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
