class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int count =0;
        int first=0;
        int last=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        while(last<n)
        {
            if((nums[last]-nums[first])<=2*k)
            {
                count=max(count,last-first+1);
                last++;
            }
            else
            {
                first++;
            }
            
        }
        return count;
    }
};
