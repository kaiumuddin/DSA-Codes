#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int v[], int w[], int s)
{
    if (s < 0) return INT_MIN;
    if (s == 0) return 0;
    if (n == 0) return 0;


    int take = knapsack(n - 1, v, w, s - w[n - 1]) + v[n - 1];
    int notTake = knapsack(n - 1, v, w, s);

    return max(take, notTake);

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
