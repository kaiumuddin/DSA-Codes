//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string psf = "";
    
    void dfs(vector<vector<int>>& grid, int row, int col){
        
        grid[row][col] = 0;
        
        if(row - 1 >= 0 && grid[row - 1][col] == 1){ // going top row  - 1
            psf.push_back('t');
            dfs(grid, row - 1, col);
        }
        if(col - 1 >= 0 && grid[row][col - 1] == 1){
            psf.push_back('l');
            dfs(grid, row, col - 1);
        }
        if(row + 1 < grid.size() && grid[row + 1][col] == 1){
            psf.push_back('d');
            dfs(grid, row + 1, col);
        }
        if(col + 1 < grid[row].size() && grid[row][col + 1] == 1){
            psf.push_back('r');
            dfs(grid, row, col + 1);
        }
        psf.push_back('b');
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<string> ans;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    psf = string();
                    psf.push_back('x');
                    dfs(grid, i, j);
                    
                    ans.insert(psf);
                }
            }
        }
        
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1