//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // int solve(int s, int w[], int v[], int n, vector<vector<int>> &dp)
    // {
    //     if(n == 0 || s == 0) return 0;
        
    //     if(dp[n][s] != -1) return dp[n][s];
        
    //     int inc = -1;
    //     if(s >= w[n-1])
    //         inc = solve(s - w[n-1], w,v, n - 1, dp) + v[n-1];
    //     int exc = solve(s, w, v, n - 1, dp);
        
    //     return dp[n][s] = max(inc, exc);
        
    // }
    
    int solve(int s, int w[], int v[], int n, vector<vector<int>> &dp)
    {
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=s; j++)
            {
                if(i==0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                
                int inc = 0;
                if(j >= w[i-1])
                    inc = dp[i-1][j - w[i-1]] + v[i-1];
                int exc = dp[i - 1][j];
                
                dp[i][j] = max(inc, exc);
            }
        }
        
        return dp[n][s];
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n + 1, vector<int>(W + 1, 1));
       return solve(W, wt, val, n, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends