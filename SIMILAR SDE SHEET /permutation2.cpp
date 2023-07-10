class Solution {
public:
    void recurse(int index,vector<int>nums,vector<vector<int>>&finalAns)
    {
       if(index==nums.size())
       {
         finalAns.push_back(nums);
         return ;
       }
       for(int i=index;i<nums.size();i++)
       {
         // swap nums[i]with index
         swap(nums[i],nums[index]);
         recurse(index+1,nums,finalAns);
         swap(nums[i],nums[index]);
       }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>finalAns;
        recurse(0,nums,finalAns);
        map<vector<int>,int>mp;
        for(auto it : finalAns)
        {
          mp[it]=1;
        }
        vector<vector<int>>ans;
        for(auto it: mp)
        {
          ans.push_back(it.first);
        }
        return ans;
    }
};
