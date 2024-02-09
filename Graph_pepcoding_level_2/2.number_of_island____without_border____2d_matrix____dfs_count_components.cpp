class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if(row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size())
            return INT_MAX;
        if(grid[row][col] == 1) return 0;
        
        grid[row][col] = 1;
        
        int r = dfs(grid, row, col + 1);
        int l = dfs(grid, row, col - 1);
        int t = dfs(grid, row + 1, col);
        int b = dfs(grid, row - 1, col);
        
        if(r == INT_MAX || l == INT_MAX || t ==  INT_MAX || b == INT_MAX) return INT_MAX;
        return 1;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int compSize = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) continue;
                
                int comps = dfs(grid, i, j);
                if(comps != INT_MAX) compSize+=1;
            }
        }
        return compSize;
    }
};