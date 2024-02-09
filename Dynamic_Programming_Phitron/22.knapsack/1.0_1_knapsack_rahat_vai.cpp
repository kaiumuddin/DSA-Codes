#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int v[], int w[], int s)
{
    if (n == 0) return 0;
    if (s == 0) return 0;

    if (s >= w[n - 1])
    {
        int take = knapsack(n - 1, v, w, s - w[n - 1]) + v[n - 1];
        int notTake = knapsack(n - 1, v, w, s);

        return max(take, notTake);
    }
    else
    {
        return knapsack(n - 1, v, w, s);
    }
}

int main() {
    int n;
    cin >> n;
    int v[n], w[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    int s;
    cin >> s;

    cout << knapsack(n, v, w, s) << endl;
}
