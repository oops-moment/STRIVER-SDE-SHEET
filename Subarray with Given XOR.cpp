#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    // so we will traverse the array and see how many subarrays exist given we will store what all xor we obtained we store the frequec y count
    int xr=0;
    int count=0; // stores the answer
    map<int,int>mp;
    for(auto it : arr)
    {
        xr=xr^it;
        if(xr==x)
        {
            count++;
        }
        if(mp.find(xr^x)!=mp.end())
        {
            count+=mp[xr^x];
            
        }
        mp[xr]++;
    }
    return count;
}
