#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 5;
ll a[N];

ll fibo(int n)
{
        a[0] = 1;
        a[1] = 1;
        for (int i = 2;i <= n;i++)
        {
                a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
}

int main() {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
                a[i] = -1;
        }

        cout << fibo(n) << endl;
}
