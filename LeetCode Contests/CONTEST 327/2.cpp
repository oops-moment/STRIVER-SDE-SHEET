
SO THE QUESTION WAS TO PERFORM K OPERATIONS , WHERE WE CAN DO ADD NUMS[I] TO THE NASWER REPLACING IT BY NUMS[I]/3 KA CEIL WE NEED MAXIMUM POSSIVBLE ANSWER
  // SO I DID THAT WILL THE PRIORITY QUEUE SINCE IT IS ALWAYS PREFEERRED TO ADD ALRGEST NUMBER
#include <bits/stdc++.h>
#include <cmath>
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // so we want the sum to be maximum right
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        // now take the l
        long long finalAnswer=0;
        for(int i=0;i<k;i++)
        {   
            int top=pq.top();
            finalAnswer+=pq.top();
            pq.pop();
            int pushh=ceil(static_cast<double>(top)/3);
            // cout<<pushh<<"\n";
            pq.push(pushh);
        }
        return finalAnswer;
    }
};
