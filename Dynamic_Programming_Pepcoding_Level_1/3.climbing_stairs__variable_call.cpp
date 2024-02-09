#include <bits/stdc++.h>
using namespace std;

// this solution works in reverse way hence ans is different
// int memo(int n, vector<int>& arr, vector<int>& dp) {
//     if (n == 0) return 1;

//     int total = 0;
//     for (int j = 1; j <= arr[n - 1]; j++) {
//         if (n - j >= 0) {
//             total += memo(n - j, arr, dp);
//         }
//     }

//     return total;
// }

int memo(int n, int index, vector<int>& arr, vector<int>& dp) {
    if (index == n) return 1;

    int total = 0;
    for (int j = 1; j <= arr[index]; j++) {
        if (index + j <= n)
        {
            total += memo(n, index + j, arr, dp);
        }
    }

    return total;
}

int tabu(int n, int index, vector<int>& arr, vector<int>& dp) {
    for (int i = n; i >= 0;i--)
    {
        if (i == n) {
            dp[i] = 1;
            continue;
        }

        int total = 0;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j <= n)
                total += dp[i + j];
        }
        dp[i] = total;
    }

    return dp[index];
}




int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n + 1, -1);
    // cout << memo(n, 0, arr, dp) << endl;
    cout << tabu(n, 0, arr, dp) << endl;
}