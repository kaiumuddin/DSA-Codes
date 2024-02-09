class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int row, int col, int color, int compColor, vector<vector<bool>>& visited)
    {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return true;
        if(visited[row][col]) return false;
        if(grid[row][col] != compColor) return true;
        
        visited[row][col] = true;
        
        bool u = dfs(grid,row-1,col,color, compColor,visited);
        bool f = dfs(grid,row,col+1,color,compColor, visited);
        bool d = dfs(grid,row+1,col,color,compColor, visited);
        bool b = dfs(grid,row,col-1,color,compColor, visited);
        if(u || f || d || b){
            // GETTING TRUE IMPLIES THAT CURRENT VERTEX IS ON BORDER
            grid[row][col] = color; // changing to required color
        }
    
        return false;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(grid, row, col, color, grid[row][col], visited);
        return grid;                 
    }
};

// https://leetcode.com/problems/coloring-a-border/