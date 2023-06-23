int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
       
        sort(stalls.begin(),stalls.end());
         int low=1;
        int high=stalls[n-1]-stalls[0]; // this is the maximum difference
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=1;
            int currentCow=stalls[0];
            int flag=0;
            for(int i=1;i<stalls.size();i++)
            {
                if((stalls[i]-currentCow)>=mid)
                {
                    count++;
                    currentCow=stalls[i];
                }
                if(count==k)
                {
                    flag=1;
                }
            }
            if(flag)
            {   
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
