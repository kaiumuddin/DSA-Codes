//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int dnc(vector<int>& arr, int n, int l, int r)
    {
        if (l == r) {
            return arr[l];
        }
        int mid = (l + r) / 2;
        int p = dnc(arr, n, l, mid);
        int q = dnc(arr, n, mid + 1, r);

        if (p > q) return p;
        return q;

    }
    int largest(vector<int>& arr, int n)
    {
        if (arr.size() == 1) return arr[0];
        return dnc(arr, n, 0, arr.size() - 1);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends