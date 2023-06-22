 vector<int>nums;
       for(int i=1;i<=n;i++)
       {
           nums.push_back(i);
       }
       do
       {
           k--;
       }while(k&& next_permutation(nums.begin(),nums.end()));
    string temp;
    for(int i=0;i<nums.size();i++)
    {
        temp+=to_string(nums[i]);

    }   
    return temp;  
