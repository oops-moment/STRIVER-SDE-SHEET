class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>vec;
        vector<int>finalAnswer;
        for(int i=0;i<nums.size();i++)
        {
           vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int left=0;
        int right=vec.size()-1;
        while(left<right)
        {
            if((vec[left].first+vec[right].first)== target)
            {
                finalAnswer.push_back(vec[left].second);
                finalAnswer.push_back(vec[right].second);
                break;
            }
            else if((vec[left].first + vec[right].first) < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return finalAnswer;
    }
};
