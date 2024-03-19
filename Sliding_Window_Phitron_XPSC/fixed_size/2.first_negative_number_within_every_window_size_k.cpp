#include<bits/stdc++.h>
using namespace std;

void template1(long long int A[], long long int n, long long int k) {
    queue<long long> q;
    int l = 0;
    int r = 0;
    vector<long long> ans;

    while (r < n)
    {
        if (A[r] < 0) q.push(A[r]);

        if (r >= k - 1)
        {
            if (q.size())
                // ans.push_back(q.front());
                cout << q.front() << " ";
            else
                // ans.push_back(0);
                cout << 0 << " ";

            if (A[l] < 0)
                q.pop();

            l++;
        }

        r++;
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

}


int main() {
    long long n, k;
    cin >> n >> k;

    long long  a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    template1(a, n, k);

}
