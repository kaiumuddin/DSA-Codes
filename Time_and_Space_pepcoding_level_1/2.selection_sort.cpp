#include<bits/stdc++.h>
using namespace std;

// procedure selectionSort(arr: array of integers, n: integer)
//     for i from 0 to n - 1 - 1
//         minIndex = i
//         for j from i + 1 to n - 1
//             if arr[j] < arr[minIndex]
//                 minIndex = j

//         swap(arr[i], arr[minIndex])
//     end for
// end procedure


// n element, n-1 iteration, like bubble sort
// find minimum, then swap it with front element

// not stable
// inplace
// offline
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int mi = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mi]) {
                mi = j;
            }
        }

        swap(arr[i], arr[mi]);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
