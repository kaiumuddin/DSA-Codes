#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1)
        return;

    int writeIndex = 1; // Index to write the next unique element

    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[writeIndex - 1]) {
            arr[writeIndex++] = arr[i];
        }
    }

    arr.resize(writeIndex); // Truncate the array to remove duplicate elements
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5, 6};

    cout << "Original sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
