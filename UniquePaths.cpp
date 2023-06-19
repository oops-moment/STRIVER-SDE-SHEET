class Solution {
public:
    int recursePaths(int m , int n , int presentX, int presentY,vector<vector<int>>&dp)
    {
        // Base Case
        if(presentX==0 && presentY==0)
        {
            return 1;
        }
        if(presentX<0 || presentY<0)
        {
            return 0;
        }
        if(dp[presentX][presentY]!=-1)
        {
            return dp[presentX][presentY];
        }
        return dp[presentX][presentY]=recursePaths(m,n,presentX-1,presentY,dp) + recursePaths(m,n,presentX,presentY-1,dp);
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,-1));
       return recursePaths(m,n,m-1,n-1,dp); 
    }
};
