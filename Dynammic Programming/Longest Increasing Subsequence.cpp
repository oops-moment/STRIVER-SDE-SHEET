O(N2)
class Solution {
public:
    int recurse(vector<int>&nums,int pindex, int last,vector<vector<int>>&visited)
    {
        if(pindex==nums.size())
        {
            return 0;
        }
        if(last==-1)
        {
            // Two option either we can pick it or not pick
            int pick=1+recurse(nums,pindex+1,pindex,visited);
            int notpick=recurse(nums,pindex+1,last,visited);
            return max(pick,notpick);
        }
        if(visited[pindex][last]!=-1)
        {
            return visited[pindex][last];
        }
        int pick=INT_MIN;
        if(nums[pindex]>nums[last])
        {
            // we can yes pick it or we can choose not to pick it
            pick=1+recurse(nums,pindex+1,pindex,visited);

        }
        int notpick=recurse(nums,pindex+1,last,visited);
        return visited[pindex][last]=max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int last=-1; // since we have chosen none right now 
        int pindex=0;
        // Once this recursion is done we should memoize it best 
        vector<vector<int>>visited(nums.size(),vector<int>(nums.size(),-1));
        return recurse(nums,pindex,last,visited);
    }
};



O(N2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = size(nums);
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < i; j++) 
                if(nums[i] > nums[j]) 
				    dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
        return ans;
    }
};



O(Nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int len = 0;
        for(auto cur : A) 
            if(len == 0 || A[len-1] < cur) A[len++] = cur;             // extend
            else *lower_bound(begin(A), begin(A) + len, cur) = cur;    // replace
        return len;
    }
};
