 #include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
    int n=heights.size();
        vector<int>left_smallest(n);
        vector<int>right_smallest(n);
        stack<int>stck;
        for(int i=(n-1);i>=0;i--)
        {
            while(!stck.empty() && heights[stck.top()]>=heights[i])
            {
                stck.pop();
            }
            if(stck.empty())
            {
                right_smallest[i]=n;
            }
            else
            {
                right_smallest[i]=stck.top();
            }
            stck.push(i);
        }
        while(!stck.empty())
        {
            stck.pop();
        }
        for(int i=0;i<n;i++)
        {
            while(!stck.empty() && heights[stck.top()]>=heights[i])
            {
                stck.pop();
            }
            if(stck.empty())
            {
                left_smallest[i]=-1;
            }
            else
            {
                left_smallest[i]=stck.top();
            }
            stck.push(i);
        }
        int maxm_sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum=heights[i]*(right_smallest[i]-left_smallest[i]-1);
            maxm_sum=max(maxm_sum,sum);
        }
        return maxm_sum;

 }
