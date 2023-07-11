class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if(currentSum < 0) {
                currentSum = 0;
            }
        }

        int minSum = 0;
        currentSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            minSum = min(minSum, currentSum);
            if(currentSum > 0) {
                currentSum = 0;
            }
        }

        return max(abs(maxSum), abs(minSum));
    }
};
