vector<vector<int>>finalAnswer;
    int n=v.size();
    int totalWays=pow(2,n);
    for(int i=0;i<totalWays;i++)
    {   
        vector<int>temp;
        for(int j=0;j<n;j++)
        {
            if(i & 1<<j)
            {
                temp.push_back(v[j]);
            }
        }
        sort(temp.begin(),temp.end());
        finalAnswer.push_back(temp);
    }
    return finalAnswer;
