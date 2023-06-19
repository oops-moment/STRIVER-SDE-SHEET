int freq=0;
        int element= nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element)
            {
                freq++;
            }
            else
            {
                freq--;
                if(freq==0)
                {
                    element=nums[i+1];
                }
            }
        }
        return element;
