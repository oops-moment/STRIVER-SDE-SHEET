#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>stck;
    vector<int>finalAnswer(n);
    for(int i=(n-1);i>=0;i--)
    {
        while(stck.empty()==0 && stck.top()>=arr[i])
        {
            stck.pop();
        }
        if(stck.empty())
        {
            finalAnswer[i]=-1;
        }
        else
        {
            finalAnswer[i]=stck.top();
        }
        stck.push(arr[i]);
    }
    return finalAnswer;
}
