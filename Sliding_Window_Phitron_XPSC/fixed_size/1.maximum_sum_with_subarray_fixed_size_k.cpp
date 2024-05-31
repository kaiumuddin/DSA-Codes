 #include<bits/stdc++.h>
using namespace std;

void brute(int a[], int n, int k)
{
    int mx = INT_MIN;
    for (int i = 0; i <= n - k; i++)
    {
        int s = 0;
        for (int j = i; j < i + k; j++)
        {
            s += a[j];
        }
        mx = max(mx, s);
    }

    cout << mx << endl;
}
 
void template1(int a[], int n, int k)
{
    int mx = INT_MIN;

    int r = 0;
    int l = 0;

    int s = 0;

    while (r < n)
    {
        s += a[r];

        if (r >= k - 1)
        {
            mx = max(mx, s);
            s -= a[l];
            l++;
        }

        r++;
    }

    cout << mx << endl;
}


void template2(int a[], int n, int k)
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
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    brute(a, n, k);
    // template1(a, n, k);
    // template2(a, n, k);
}
// 6 3
// 5 2 1 6 3 4
// 