class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sum_left=INT_MIN;
        int sum_right=INT_MIN;
        int var=1;
        for(int i=0;i<nums.size();i++)
        {
            var*=nums[i];

            sum_left=max(sum_left,var);
            if(var==0)
            {
                var=1;
            }
        }
        var=1;
        for(int j=nums.size()-1;j>=0;j--)
        {
            var*=nums[j];
            sum_right=max(sum_right,var);
            if(var==0)
            {
                var=1;
            }
        }
        return max(sum_left,sum_right);
    }
};
