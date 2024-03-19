#include<bits/stdc++.h>
using namespace std;

void best(int a[], int n, int k)
{
    int mx = INT_MIN;

    int r = 0;
    int l = 0;

    int s = 0;
    while (r < n)
    {
        if (r < k) {
            s += a[r++];
        }
        else {
            s += a[r++];
            s -= a[l++];
            mx = max(mx, s);
        }
    }

    cout << mx << endl;
}


void best(int a[], int n, int k)
{
    int mx = INT_MIN;

    int r = 0;
    int l = 0;

    int s = 0;

    while (r < k)
    {
        s += a[r++];
    }
    mx = max(mx, s);

    while (r < n)
    {
        s += a[r++];
        s -= a[l++];
        mx = max(mx, s);
    }

    cout << mx << endl;
}

int main() {

}
