#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void removeDuplicates(vector<int>& arr) {
    unordered_set<int> seen;
    int writeIndex = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[writeIndex++] = arr[i];
        }
    }

    arr.resize(writeIndex); // Truncate the array to remove duplicate elements
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 2, 3, 5, 6, 7, 7, 8};
    
    cout << "Original array: ";
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
