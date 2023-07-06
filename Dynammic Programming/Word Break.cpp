class Solution {
public:
    bool recurse(string s,int start, int index,map<string,int>mp,vector<vector<int>>&dp)
    {
        // now there are two cases that either you are in the dict or you are not
        // ypu are
        // Base case
        if(index==s.length()-1)
        {
           if(mp[s.substr(start,index-start+1)]) 
           {
               return 1;
           }
           else
           {
               return 0;
           }
        }
        int a=0;
        if(dp[start][index]!=-1)
        {
            return dp[start][index];
        }
        if(mp[s.substr(start,index-start+1)]) 
        {
            a=recurse(s,index+1,index+1,mp,dp);
        }
        int b=recurse(s,start,index+1,mp,dp);
        return dp[start][index]= a||b;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(int i=0;i<wordDict.size();i++)
        {
            mp[wordDict[i]]=1;
        }
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return recurse(s,0,0,mp,dp);

    }
};
