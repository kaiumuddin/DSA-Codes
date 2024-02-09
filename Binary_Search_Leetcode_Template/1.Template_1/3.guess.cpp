#include<bits/stdc++.h>
using namespace std;

int guess(int num) {
    int pick = 200;
    if (num == pick) return 0;
    else if (num < pick) return 1;
    return -1;
}

int guessNumber(int n) {
    long long l = 1, r = 1LL * n + 1;
    long long m;

    while (l <= r) {
        m = l + (r - l) / 2;
        if (guess(m) == 0) {
            return m;
        }
        if (guess(m) == 1) {
            l = m + 1;
        }
        else if (guess(m) == -1) {
            r = m - 1;
        }
    }

    return m;
}

int main() {
    cout << guessNumber(500);
    return 0;
}