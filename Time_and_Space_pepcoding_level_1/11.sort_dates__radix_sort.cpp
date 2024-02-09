#include<bits/stdc++.h>
using namespace std;

// stable

void count_sort(vector<string>& arr, int div, int mod, int range)
{
    // change
    int mn = 0;

    vector<int> freq(range, 0);
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        freq[stoi(arr[i]) / div % mod - mn]++; // change
    }

    for (int i = 1; i < range; i++)
    {
        freq[i] += freq[i - 1];
    }

    vector<string> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int val = stoi(arr[i]) / div % mod; // change
        int pos = freq[val - mn];
        freq[val - mn]--;
        int idx = pos - 1;
        ans[idx] = arr[i];
    }

    arr = ans;
}

void sort_dates(vector<string>& arr)
{
    count_sort(arr, 1000000, 100, 32 ); // days
    count_sort(arr, 10000, 100, 13 ); // months
    count_sort(arr, 1, 10000, 2501 ); // years
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort_dates(arr);

    for (int i = 0; i < n; i++) cout << arr[i] << endl;

}
// input
// 5
// 12041996
// 20101996
// 05061997
// 12041989
// 11081987

// output
// 11081987
// 12041989
// 12041996
// 20101996
// 05061997