class Solution {
public:
    void recurse(vector<int>&nums,vector<int>&temp,vector<vector<int>>&finalAnswer,vector<int>&visited, int count)
    {
        if(count==nums.size())
        {
            finalAnswer.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                temp.push_back(nums[i]);
                recurse(nums,temp,finalAnswer,visited,count+1);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>visited(nums.size(),0);
        vector<vector<int>>finalAnswer;
        vector<int>temp;
        recurse(nums,temp,finalAnswer,visited,0);
        return finalAnswer;
    }
};
