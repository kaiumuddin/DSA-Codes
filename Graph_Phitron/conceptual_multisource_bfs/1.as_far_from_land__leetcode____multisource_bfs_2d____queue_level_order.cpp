class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        if(q.size() == 0 || q.size() == row*col) return -1;
        
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int level = -1;
        
        while(q.size()){
            level++;
            int sz = q.size();
            
            while(sz--){
                auto f = q.front();
                q.pop();

                int i = f.first;
                int j = f.second;

                for(auto dr: dir){
                    int ni = i + dr.first;
                    int nj = j + dr.second;

                    if(ni < 0 || nj < 0 || ni >= row || nj >= col) continue;
                    if(grid[ni][nj] == 1) continue;

                    grid[ni][nj] = 1;

                    q.push({ni,nj});
                }
            }
            
        }
        
        return level;
    }
};
// https://leetcode.com/problems/as-far-from-land-as-possible/