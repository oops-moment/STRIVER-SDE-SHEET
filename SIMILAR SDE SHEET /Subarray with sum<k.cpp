class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0;
        int j=0;
        long long ans=0;
        long long sum=0;
        while(j<nums.size())
        {
             sum+=nums[j];
             while((sum)*(j-i+1)>=k)
             {
                sum-=nums[i];
                i++;
             }
             
             ans+=j-i+1;
            j++;

        }
        return ans;
    }
};
