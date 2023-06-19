class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> finalAnswer;
        if(nums.size()<4)
        {
            return finalAnswer;
        }
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                long long int partialSum = nums[i] + nums[j];
                long long int remainSum = target - partialSum;
                long long int left = j + 1;
                long long int right = nums.size() - 1;
                
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    
                    if (sum == remainSum) {
                        vector<int> possibleAnswer;
                        possibleAnswer.push_back(nums[i]);
                        possibleAnswer.push_back(nums[j]);
                        possibleAnswer.push_back(nums[left]);
                        possibleAnswer.push_back(nums[right]);
                        finalAnswer.push_back(possibleAnswer);
                        
                        left++;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        
                        right--;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    } else if (sum < remainSum) {
                        left++;
                         while (left < right && nums[left] == nums[left - 1])
                            left++;
                        
                    } else {
                        right--;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        
        return finalAnswer;
    }
};
