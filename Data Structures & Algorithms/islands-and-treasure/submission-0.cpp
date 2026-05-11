class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int i = cell.first;
            int j = cell.second;
            for(int d = 0;d<4;d++){
                int newrow = i+dir[d][0];
                int newcol = j+dir[d][1];
                if(newrow<0 || newcol<0 || newrow>=n || newcol>=m) continue;
                 if(grid[newrow][newcol] != 2147483647) continue;
                grid[newrow][newcol]=grid[i][j]+1;
                q.push({newrow,newcol});
            }
        }
    }
};
