#include <iostream>
#include <vector>

using namespace std;

// First version of search function
int search1(vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return -1;
}

// Second version of search function
int search2(vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    if (arr[l] == x) {
        return l;
    }
    return -1;
}

// Third version of search function
int search3(vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return -1;
}

// Fourth version of search function
int search4(vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size() - 1;

    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (arr[l] == x) {
        return l;
    }
    if (arr[r] == x) {
        return r;
    }
    return -1;
}

// Fifth version of search function
int search5(vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size();

    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (arr[l] == x) {
        return l;
    }

    return -1;
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int x = 7;

    // Call each version of the search function
    cout << "Using search1: " << search1(arr, x) << endl;
    cout << "Using search2: " << search2(arr, x) << endl;
    cout << "Using search3: " << search3(arr, x) << endl;
    cout << "Using search4: " << search4(arr, x) << endl;
    cout << "Using search5: " << search5(arr, x) << endl;

    return 0;
}
