 int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]>=nums[low])
            {
                //Sorted Left Part
                if(target>=nums[low] && target <nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                //sorted Right half
                if(target>nums[mid] && target <=nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
