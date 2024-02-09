#include <bits/stdc++.h>
using namespace std;

int memo(int n, int index, vector<int>& arr, vector<int>& dp) {
    if (index == n) return 0;

    int mini = INT_MAX;
    for (int j = 1; j <= arr[index]; j++) {
        if (index + j <= n)
        {
            int l = memo(n, index + j, arr, dp);
            if (l != INT_MAX)
                mini = min(l, mini) + 1;
            else
                mini = min(l, mini);
        }
    }

    return mini;
}

int tabu(int n, int index, vector<int>& arr, vector<int>& dp) {
    for (int i = n; i >= 0;i--)
    {
        if (i == n) {
            dp[i] = 0;
            continue;
        }

        int mini = INT_MAX;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j <= n) {
                int l = dp[i + j];
                if (l != INT_MAX)
                    mini = min(l, mini) + 1;
                else
                    mini = min(l, mini);
            }
        }
        dp[i] = mini;
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
    cout << memo(n, 0, arr, dp) << endl;
    // cout << tabu(n, 0, arr, dp) << endl;
}