class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // WE HAVE PROVED THAT THE ELEMENT THAT IS DOMINANT REMAINS SAME IN BOTH THE ARRAYS TO NOTE LETS' FIND THAT ELEMENT
        int element=-1;
        int freq=0;
        for(int i=0;i<nums.size();i++)
        {
            if(freq==0)
            {
                freq++;
                element=nums[i];
            }
            else
            {
                if(nums[i]==element)
                {
                    freq++;
                }
                else
                {
                    freq--;
                }
            }
        }
        // finally this element is our number that is dominant
        int N=nums.size();
        // cout<<element<<"\n";
        vector<int>prefix(N,0);
        prefix[0]=(nums[0]==element)?1:0;
        for(int i=1;i<N;i++)
        {
            if(nums[i]==element)
            {
                prefix[i]=1+prefix[i-1];
            }
            else
            {
                prefix[i]=prefix[i-1];
            }
        }
        // now yes let's go 
        for(int i=0;i<N;i++)
        {
            if(((2*prefix[i])>((i+1))) && ((2*(prefix[N-1]-prefix[i]))>(N-i-1)))
            {
                return i;
            }
        }
        return -1;
    }
};
