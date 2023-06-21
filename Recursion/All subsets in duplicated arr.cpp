class Solution {
public:
    void recurse(vector<int>nums,vector<int>&temp,vector<vector<int>>&finalAnswer,int index)
    {
        finalAnswer.push_back(temp);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index &&  nums[i]==nums[i-1])
            {
                continue;
            }
            temp.push_back(nums[i]);
            recurse(nums,temp,finalAnswer,i+1);
            temp.pop_back();
        }
            
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           vector<vector<int>>finalAnswer;
           sort(nums.begin(),nums.end());
           vector<int>temp;
           int index=0;
           recurse(nums,temp,finalAnswer,0);
           return finalAnswer;
    }
};
