#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &nums, int n) {
    // Write your code here
    vector<int>final_Answer(n);
    stack<int>stck;
        for(int i=n-1;i>=0;i--)
        {    
            while(!stck.empty()&& stck.top()<=nums[i])
            {
                stck.pop();
            }
            if(stck.empty())
            {
                final_Answer[i]=-1;
            }
            else
            {
                final_Answer[i]=stck.top();
            }
            stck.push(nums[i]);
        }
        return final_Answer;

}
