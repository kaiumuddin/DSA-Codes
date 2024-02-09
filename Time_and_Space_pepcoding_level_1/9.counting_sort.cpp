#include<bits/stdc++.h>
using namespace std;

// stable

void count_sort(vector<int>& arr)
{
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());
    int range = mx - mn + 1;
    vector<int> freq(range, 0);
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - mn]++;
    }

    for (int i = 1; i < range; i++)
    {
        freq[i] += freq[i - 1];
    }

    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = freq[val - mn];
        freq[val - mn]--;
        int idx = pos - 1;
        ans[idx] = arr[i];
    }

    arr = ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    count_sort(arr);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
