class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {    int minm=INT_MAX;
             int index=i;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i] && nums[j]<minm)
                {
                    minm=nums[j];
                    index=j;
                }
            }
            // now here swap the index j with the value at 
            if(index!=i)
           {   
               int temp=nums[i];
               nums[i]=nums[index];
            nums[index]=temp;
            sort(nums.begin()+i+1,nums.end());
            return ;
            }

        }
        sort(nums.begin(),nums.end());
    }
};
