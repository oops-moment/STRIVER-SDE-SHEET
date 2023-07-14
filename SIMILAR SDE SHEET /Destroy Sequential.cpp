class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        // now we need to count the number of time it acted as remiainder
        unordered_map<int,int>mp;
        int maxm=INT_MIN;
        for(auto it : nums)
        {
            mp[it%space]++;
            maxm=max(maxm,mp[it%space]);
        }
        sort(nums.begin(),nums.end());
        // we need to find the minimum number which when divided by space gives that
        for(auto it : nums)
        {
            if(mp[it%space]==maxm)
            {
                return it;
            }
        }
        return 0;
    }
};
