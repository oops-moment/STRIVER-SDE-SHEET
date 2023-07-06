class Solution {
public:
    int recurse(vector<vector<int>>&grid, int x, int y,vector<vector<int>>&dp)
    {
        if(x<0 || y<0)
        {
            return 1e8;
        }
        if(x==0 && y==0)
        {
            return grid[0][0];
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        //now two option
        int up=grid[x][y]+recurse(grid,x-1,y,dp);
        int left=grid[x][y]+recurse(grid,x,y-1,dp);
        return dp[x][y]= min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return recurse(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};
