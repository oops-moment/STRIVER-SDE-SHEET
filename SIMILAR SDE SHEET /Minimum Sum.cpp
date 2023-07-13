O(N2)
class Solution {
public:
// Let's have the minimum path sum
    int solve(int i , int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0||j<0)
        {
            return 1e8;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // now we have two option either left or up
        int up=grid[i][j]+solve(i-1,j,grid,dp);
        int left=grid[i][j]+solve(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,grid,dp);
    }
};
