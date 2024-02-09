#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 15;
    for (int i = 1; i <= n; i++) { // O(n)
        int x = i;
        while (x > 0) { // O( log n)
            int digit = x % 10;
            cout << digit << " ";
            x /= 10;
        }
        cout << endl;
    }
    return 0;
}