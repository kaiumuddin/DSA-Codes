#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 5;
ll save[N];

ll fibo(int n)
{
        if (n == 0 || n == 1) return 1;

        if (save[n] != -1) return save[n];

        ll ans1 = fibo(n - 1);
        ll ans2 = fibo(n - 2);

        save[n] = ans1 + ans2;

        return ans1 + ans2;
}

int main() {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
                save[i] = -1;
        }

        cout << fibo(n) << endl;
}
