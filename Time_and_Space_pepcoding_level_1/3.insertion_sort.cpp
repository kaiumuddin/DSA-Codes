#include<bits/stdc++.h>
using namespace std;


// n element, n-1 iteration
// reverse bubble

// stable : sequence of same element is like previous
// in place: no extra space
// online : ekta element notun ashlei sathe sathe kaj suru kre.
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]); 
            }
            else break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
