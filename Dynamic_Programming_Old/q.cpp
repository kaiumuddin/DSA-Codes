// C++ program to illustrate
// prev_permutation example

// this header file contains prev_permutation function
#include <algorithm>

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = i + 1;
    }

    do
    {
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    } while (next_permutation(arr, arr + n));

    return 0;
}
