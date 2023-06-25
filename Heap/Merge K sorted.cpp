#include <bits/stdc++.h> 
vector<int> merge(vector<int>&finalAnswer,vector<int>newar)
{
    vector<int>temp;
    int i=0;
    int j=0;
    int n=finalAnswer.size();
    int m=newar.size();
    while(i<n && j<m)
    {
        if(finalAnswer[i]<newar[j])
        {
            temp.push_back(finalAnswer[i]);
            i++;
        }
        else
        {
            temp.push_back(newar[j]);
            j++;
        }
    }
     while(j<m)
    {
       
           temp.push_back(newar[j]);
            j++;
        
    }
    while(i<n)
    {
        temp.push_back(finalAnswer[i]);
            i++;
    }
    finalAnswer=temp;
    return finalAnswer;
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int>finalAnswer=kArrays[0];
    for(int i=1;i<k;i++)
    {
        finalAnswer=merge(finalAnswer,kArrays[i]);
    }
    return finalAnswer;
}
