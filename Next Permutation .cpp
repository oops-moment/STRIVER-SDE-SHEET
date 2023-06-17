class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n= nums.size()-1;
        for(int i=n;i>=0;i--)
        {   
            int minm=INT_MAX;;
            int ind=i;
            for(int j=i+1;j<=n;j++)
            {
                if(nums[j]>nums[i] && nums[j]<minm)
                {
                    minm=nums[j];
                    ind=j;
                }
               
            }
             if(ind!=i)
                {
                    nums[ind]=nums[i];
                    nums[i]=minm;
                    sort(nums.begin()+i+1,nums.end());
                    return;
                }
        }
        sort(nums.begin(),nums.end());
    }
};
