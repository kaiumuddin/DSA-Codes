//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
// 	int MinSquares_(int n , vector<int> &dp)
// 	{
// 	    if(n == 0) return 0;
// 	    // Code here
	    
// 	       if(dp[n] != -1) return dp[n];
	    
// 	    int mini = n;
// 	    for(int i=1; i * i <= n; i++)
// 	    {
// 	       int sub = MinSquares_(n - i*i, dp) + 1;
// 	       mini = min(mini, sub);
// 	    }
	    
// 	    return dp[n] = mini;
// 	}
	
	int MinSquares_(int n , vector<int> &dp)
	{
	    dp[0] = 0;
	    
	    for(int i = 1; i<= n; i++)
	    {
	        for(int j=1; j*j <= i; j++)
	        {
	            int sub = dp[i - j*j] + 1;
	            dp[i] =  min(dp[i], sub);
	        }
	    }
	    
	    return dp[n];
	}
	
	
	int MinSquares(int n)
	{
	   // vector<int> dp(n + 1, -1);
	    vector<int> dp(n + 1, INT_MAX);
	    return MinSquares_(n, dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1