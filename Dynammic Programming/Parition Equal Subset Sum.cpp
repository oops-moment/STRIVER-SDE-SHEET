class Solution {
public:
    bool recurse(vector<int>&nums,int index,int target,vector<vector<int>>&dp)
    {   
        if(target==0)
        {
            return 1;
        }
        if(index==nums.size())
        {
            return 0; 
        }
        //  we have tow option
        int pick=0;
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        if(nums[index]<=target)
        {
            pick=recurse(nums,index+1,target-nums[index],dp);
        }
        int nonpick=recurse(nums,index+1,target,dp);
        return dp[index][target]=(pick||nonpick);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++)
        {
            totalSum+=nums[i];
        }
        if(totalSum%2!=0)
        {
            return 0;
        }
        totalSum=totalSum/=2;
        int target=totalSum;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return recurse(nums,0,target,dp);
    }
};
