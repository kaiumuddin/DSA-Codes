#include<bits/stdc++.h>
using namespace std;

// procedure bubbleSort(arr: array of integer, n: integer)
//     for i from 1 to n - 1
//         for j from 0 to n - i - 1
//             if arr[j] > arr[j + 1]
//                 swap(arr[j], arr[j + 1])
//             end if
//         end for
//     end for
// end procedure

// n element, n-1 iteration
// stable
// in place
// offline

// on every iteration big element goes to last;
// void bubbleSort(int arr[], int n)
// {
//     for (int i = 1; i <= n - 1; i++) {
//         for (int j = 0; j < n - i; j++) {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
