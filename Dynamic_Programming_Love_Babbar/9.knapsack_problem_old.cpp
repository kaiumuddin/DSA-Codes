#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& w, vector<int>& v, int n, int m)
{
    if (n == 0)
    {
        if (w[0] <= m)
            return v[0];
        else return 0;
    }

    int include = 0;
    if (w[n] <= m)
        include = v[n] + solve(w, v, n - 1, m - w[n]);
    int exclude = 0 + solve(w, v, n - 1, m);

    return max(include, exclude);
}

int solveMemo(vector<int>& w, vector<int>& v, int n, int m, vector<vector<int>>& dp)
{
    if (n == 0)
    {
        if (w[0] <= m)
            return v[0];
        else return 0;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    int include = 0;
    if (w[n] <= m)
        include = v[n] + solveMemo(w, v, n - 1, m - w[n], dp);
    int exclude = 0 + solveMemo(w, v, n - 1, m, dp);

    return dp[n][m] = max(include, exclude);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n - 1, maxWeight);

    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveMemo(weight, value, n - 1, maxWeight, dp);
}

int main() {
    cout << knapsack({ 1,2,4,5 }, { 5,4,8,6 }, 4, 5) << endl;
    return 0;
}