class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int element1=1e9+1;
        int element2=1e9+1;
        for(int i=0;i<nums.size();i++)
        {
            if(element1==nums[i])
            {
                count1++;
            }
            else if(element2==nums[i])
            {
                count2++;
            }
            else if(count1==0)
            {
                count1++;
                element1=nums[i];
            }
            else if(count2==0)
            {
                count2++;
                element2=nums[i];
            }
            else
            {
                count1--;
                count2--;
            }
        }
        // Recheck
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element1)
            {
                count1++;
            }
            if(nums[i]==element2)
            {
                count2++;
            }
        }
        vector<int>final_ans;
        if(count1>(nums.size()/3))
        {
            final_ans.push_back(element1);
        }
        if(count2>(nums.size()/3))
        {
            final_ans.push_back(element2);
        }
        return final_ans;
    }
};
