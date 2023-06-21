class Solution {
public:
    int recurse(vector<int>&coins,int index, int target,vector<vector<int>>dp)
    {
        //Base Case
        if(target==0)
        {
            return 0;
        }
        if(index>=coins.size() || target < 0)
        {
            return 1e8;
        }
        if(dp[index][target]!=-1)
        {
                return dp[index][target];
        }
        // Two Options 
        int pick=1+recurse(coins,index,target-coins[index],dp);
        int notpick=recurse(coins,index+1,target,dp);

        return dp[index][target]=min(pick,notpick);

    }
    int coinChange(vector<int>& coins, int amount) {
        // we need find minimum number of coins
        int index=0;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=recurse(coins,index,amount,dp);
        if(ans>=1e8)
        {
            return -1;
        }
        return ans;

    }
};
