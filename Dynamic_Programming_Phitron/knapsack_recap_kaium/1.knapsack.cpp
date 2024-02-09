//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack_(int s, int w[], int v[], int n, vector<vector<int>>& dp)
    {
        if (n == 0 || s == 0)
        {
            return 0;
        }

        if (dp[n][s] != -1) return dp[n][s];

        if (w[n - 1] <= s)
        {
            int l = knapSack_(s - w[n - 1], w, v, n - 1, dp) + v[n - 1];
            int r = knapSack_(s, w, v, n - 1, dp);

            return dp[n][s] = max(l, r);
        }
        else
        {
            int r = knapSack_(s, w, v, n - 1, dp);

            return dp[n][s] = r;
        }
    }

    int knapSack_tabu(int s, int w[], int v[], int n, vector<vector<int>>& dp)
    {
        for (int i = 0;i <= n;i++) {
            for (int j = 0;j <= s; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (w[i - 1] <= j)
                {
                    int l = dp[i - 1][j - w[i - 1]] + v[i - 1];
                    int r = dp[i - 1][j];
                    dp[i][j] = max(l, r);
                }
                else
                {
                    int r = dp[i - 1][j];
                    dp[i][j] = r;
                }
            }
        }

        return dp[n][s];
    }

    int knapSack(int s, int w[], int v[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));

        // return knapSack_(s,w,v,n, dp);
        return knapSack_tabu(s, w, v, n, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0;i < n;i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0;i < n;i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;

    }
    return 0;
}
// } Driver Code Ends