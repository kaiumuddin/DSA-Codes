#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
        {
            arr[i] = i + 1;
        }

        // for (int i = 0; i < n; ++i)
        // {
        //     cout << arr[i] << "\t";
        // }
        // cout << endl;

        prev_permutation(arr, arr + n);

        if (n % 2 == 1)
        {
            int l = n - 1;
            int middle = l / 2;

            swap(arr[middle], arr[middle + 1]);
        }

        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}