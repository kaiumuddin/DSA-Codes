#include<bits/stdc++.h>
using namespace std;

int main() {
    // list<int> myList;
    // list<int> myList(10);
    list<int> myList(10, 5);
    cout << myList.size() << endl;
    cout << myList.front() << endl;

    for (auto it = myList.begin(); it != myList.end(); it++) {
        cout << *it << " ";
    }

    // list<int> l2 = { 1,2,3,4,4,5,5,6 };
    list<int> l2(myList);

    int arr[5] = { 10,20,30,40,50 };
    list<int> fromArr(arr, arr + 5);

    vector<int> v = { 100,200,300,400 };
    list<int> fromVec(v.begin(), v.end());

    for (int val : fromVec) cout << val << " ";

    return 0;
}