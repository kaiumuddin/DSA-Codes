class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if(row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size()) return INT_MAX;
        if(grid[row][col] == 0) return 0;
        
        grid[row][col] = 0; // visited
        
        int r = dfs(grid, row, col + 1);
        int l = dfs(grid, row, col - 1);
        int t = dfs(grid, row + 1, col);
        int b = dfs(grid, row - 1, col);
        
        if(r == INT_MAX or l == INT_MAX or t == INT_MAX or b == INT_MAX)
            return INT_MAX;
        return r + l + t + b + 1;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j] == 0) continue;
                
                int cells = dfs(grid, i,j);
                if(cells != INT_MAX) 
                    ans += cells;
            }
        }
        
        return ans;
    }
};
// https://leetcode.com/problems/number-of-enclaves/
// https://leetcode.com/problems/number-of-enclaves/discuss/3388147/Easy-to-understand-code-oror-Simple-DFS-oror-Single-Traversal