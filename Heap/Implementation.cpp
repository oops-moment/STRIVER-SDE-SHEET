#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int>temp;
    vector<int>finalAnswer;
    auto mn= temp.begin();
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0)
        {
            temp.push_back(q[i][1]);
            mn=min_element(temp.begin(),temp.end());

        }
        else
        {
            finalAnswer.push_back(*mn);
            temp.erase(mn);
        }
    }
    return finalAnswer;

}
