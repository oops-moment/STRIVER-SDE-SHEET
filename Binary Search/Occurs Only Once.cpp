int solve(vector<int>&nums,int low, int high, int n)
    {
        if(low>high)
        {
            return -1;
        }
        int mid=low+(high-low)/2;
        if((mid!=0 && nums[mid]!=nums[mid-1])&& (mid!=n && nums[mid]!=nums[mid+1]))
        {
            return nums[mid];
        }
        if(mid==0 && nums[mid]!=nums[mid+1])
        {
            return nums[mid];
        }
        if(mid==(n)&& nums[mid]!=nums[mid-1])
        {
            return nums[mid];
        }
        int left = solve(nums,low,mid-1,n);
        if(left==-1)
        {
            left=solve(nums,mid+1,high,n);
        }
        return left;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=nums.size()-1;
        if(nums.size()==1)
        {
            return nums[0];
        }
        return solve(nums,low,high,n-1);

    }
