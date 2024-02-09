#include<bits/stdc++.h>
using namespace std;

// stable

void count_sort(vector<int>& arr, int exp)
{
    // change
    int mn = 0;
    int range = 10;
    vector<int> freq(range, 0);
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] / exp % 10 - mn]++; // change
    }

    for (int i = 1; i < range; i++)
    {
        freq[i] += freq[i - 1];
    }

    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i] / exp % 10; // change
        int pos = freq[val - mn];
        freq[val - mn]--;
        int idx = pos - 1;
        ans[idx] = arr[i];
    }

    arr = ans;
}

void radix_sort(vector<int>& arr)
{
    int mx = *max_element(arr.begin(), arr.end());

    int exp = 1;
    while (exp <= mx)
    {
        count_sort(arr, exp);
        exp *= 10;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    radix_sort(arr);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
