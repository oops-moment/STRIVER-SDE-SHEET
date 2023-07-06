class Solution {
public:
    int recurse(vector<int>&coins,int amount, int index,vector<vector<int>>&dp)
    {   
        if(amount==0)
        {
            return 0;
        }
        if(index==0)
        {
            // here we have some amount left
            if(amount<coins[0])
            {
                return 1e8;
            }
            else
            {
                if(amount%coins[0]==0)
                {
                    return amount/coins[0];
                }
                else
                {
                    return 1e8;
                }
            }
        }
        // now for all we have two options  pick and not pick
        int pick=1e8;
        if(dp[amount][index]!=-1)
        {
            return dp[amount][index];
        }
        if(coins[index]<=amount)
        {
            pick=1+recurse(coins,amount-coins[index],index,dp);
        }
        int notpick=recurse(coins,amount,index-1,dp);
        return dp[amount][index]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int index=coins.size()-1;
        vector<vector<int>>dp(amount+1,vector<int>(index+1,-1));
        int ans=recurse(coins,amount,index,dp);
        if(ans>=1e8)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
